//10-3 그래프이론 위상정렬.
//순서가 정해져 있는 일련의 작업을 차례대로 수행할 때 사용
//방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열하는 것'

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//노드의 개수(V)와 간선(Union 연산)의 개수(E)
//노드의 개수는 최대 100,000개로 가정
int v,e;
int indegree[100001];   //모든 노드의 진입차수를 0으로 초기화
vector<int> graph[100001];  //각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화

//위상 정렬 함수
void topologySort(){
    vector<int> result; //위상정렬 후 수행 결과를 담을 리스트
    queue<int> q;   //진입차수가 0이 되는 노드를 넣을 큐

    //1.처음으로 진입차수가 0인 노드를 큐에 삽입
    for(int i=1; i<=v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //큐가 빌 때까지, 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거
    //새롭게 진입차수가 0이되는 노드를 큐에 삽입
    while(!q.empty()){
        int now = q.front();
        q.pop();    //2.큐에서 원소 꺼내기
        result.push_back(now);  //결과리스트에 기록

        //3.해당 원소와 연결된 노드들의 진입차수를 1씩 줄인다.
        for(int i=0; i<graph[now].size(); i++){
            indegree[graph[now][i]] -= 1;
            //4. 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            }
        }

    }

    for(int i=0; i< result.size(); i++){
        cout << result[i] << '\n';
    }
}


int main(void){

    cin >> v >> e;

    //방향성이 있는 방향 그래프의 모든 간선 정보 입력받기
    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);  //A->B방향
        //진입차수를 1 증가 시킨다. 진입차수는 노드로 들어오는 간선의 개수 이기때문에 b에 저장
        indegree[b] += 1;
    }
    //위상정렬 수행
    topologySort();
}