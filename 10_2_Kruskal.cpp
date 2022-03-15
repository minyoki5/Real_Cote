//10-2 그래프이론 
//크루스칼 알고리즘. 최소 신장트리 알고리즘의 대표적인 알고리즘
//모든 간선에 대해 정렬을 수행한 뒤 가장 거리가 짧은 간선부터 집합에 포함하는데,
//사이클을 발생시킬 수 있는 간선은 집합에 포함시키지 않는다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//노드의 개수(V)와 간선(Union 연산)의 개수(E)
//노드의 개수는 최대 100,000개로 가정

int v,e;
int parent[100001];     //부모 테이블 초기화하기
vector<pair<int,pair<int,int>>> edges;      //모든 간선의 정보를 담을 리스트
int result = 0;     //최종비용

int findParent(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a<b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }

}

int main(void){
    cin >> v >> e;

    //부모테이블에서, 우선 자기자신을 부모로 초기화
    for(int i=1; i<=v; i++){
        parent[i]=i;
    }

    //모든 간선 정보 입력받기
    for(int i=0; i<e; i++){
        int a,b,cost;
        cin >> a >> b >> cost;
        //비용순으로 정렬하기 위해 cost를 튜플의 첫 원소로 설정한다.
        edges.push_back({cost, {a,b}});
    }

    //간선을 오름차순으로 정렬
    sort(edges.begin(),edges.end());

    //간선을 작은 비용부터 하나씩 확인하면서, 사이클이 이루어지지 않는 경우에만 집합에 포함시킨다.
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(findParent(a) != findParent(b)){
            unionParent(a,b);
            result += cost;
        }
    }

    cout << result << '\n';

}