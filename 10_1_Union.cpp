//10. 그래프이론 1 - 서로소 집합 알고리즘 + 사이클 판별 

#include <iostream>
using namespace std;

//노드의 개수(V)와 간선(Union 연산)의 개수(E)
//노드의 개수는 최대 100,000개로 가정

int v,e;
int parent[100001];     //부모 테이블 초기화하기

//특정 원소가 속한 집합을 찾기
int findParent(int x){
    //루트노드가 아니라면, 루트 노드를 찾을 때 까지 재귀적으로 호출
    if(x==parent[x]){
        return x;
    }
    return findParent(parent[x]);
}
// 경로 압축(path compression)을 통해 시간복잡도 개선하는 방법
//find함수를 재귀적으로 호출해 부모 테이블값을 갱신
int findParent2(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]= findParent(parent[x]);
    //이 방법을 이용하면 해당 노드의 루트 노드를 바로 부모 모드로 만들 수 있다.
}

//두 원소가 속한 집합을 합치기(합집합 연산)
void unionParent(int a, int b){
    //1. 두 원소의 부모 노드를 찾는다.
    a = findParent(a);
    b = findParent(b);

    //2. 부모노드의 번호를 비교해서 작은 번호가 큰 번호의 부모노드가 되게한다.
    if(a<b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

int main(void){
    cin >> v >> e;

    //1. 부모테이블 상에서 부모를 자기 자신으로 초기화
    for(int i=1; i<=v; i++){
        parent[i] = i;
    }
    //사이클 발생 여부 판단
    bool cycle = false;

    //2. Union연산을 각각 수행
    for(int i=1; i<=e; i++){
        int a,b;
        cin >> a >>b;
        //사이클이 발생한 경우에는 종료
        if(findParent2(a) == findParent2(b)){
            cycle = true;
            break;
        }
        else{
            unionParent(a,b);
        }

    }
    //3. 각 원소가 속한 집합 출력
    cout << "각 원소가 속한 집합: ";
    for(int i=1; i<=v; i++){
        cout << findParent2(i) <<' ';
    }
    cout << '\n';
    //4. 부모 테이블 내용 출력
    cout << "부모 테이블: ";
    for(int i=1; i<=v; i++){
        cout << parent[i] <<' ';
    }
    cout <<'\n';

    if(cycle){
        cout << "사이클 발생" << '\n';
    }
    else{
        cout << "사이클 발생안함" << '\n';
    }
}
