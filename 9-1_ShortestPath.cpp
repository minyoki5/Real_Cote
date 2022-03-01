//9. 최단경로 구하기
//다익스트라 알고리즘의 1. 간단한 구현, 2. 개선된 구현과 3.플로이드 워셜 알고리즘
//#1 간단한 구현

#include <iostream>
#include <vector>
#define INF 1e9    //무한에 해당하는 값을 10억으로 설정
using namespace std;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정

int n,m,start;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열, (현재 노드, 연결된 노드)정보
// 2개의 지정한 타입의 값을 각각 저장가능, 저장한 값은 .first, .second로 접근 가능
// 2개의 연관된 값을 같이 저장할 수 있어서 관리 편함, 2개의 정렬 조건으로 정렬을 하고 싶을 때 유리
vector<pair<int, int> > graph[100001];
// 방문한 적이 있는지 체크하는 목적의 배열 만들기
bool visited[100001];
// 최단 거리 테이블 만들기
int dis[100001];

// 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
int getSmallestNode(){
    int min_val=INF;    //최단거리를 무한대로 초기화
    int index=0;    //최단 거리가 가장 짧은 노드의 인덱스를 반환하기 위해 초기화

    for(int i=1; i<=n; i++){    //1~n번째 노드까지 반복

        if(dis[i] < min_val && !visited[i]){    //최단거리가 min_val보다 작음 and 방문한적이 없으면
            min_val = dis[i];   //최단 거리 정보를 갱신 
            index = i;
        }

    }
    return index;   //최단거리가 가장 짧은 노드의 번호 반환
}

void dijkstra(int start){
    //시작 노드에 대해서 초기화 진행
    dis[start]=0;
    visited[start]=true;
    for(int j=0; j<graph[start].size(); j++){
        dis[graph[start][j].first] = graph[start][j].second;
    }

    //시작 노드를 제외한 전체 노드 n-1 개의 노드에 대해 반복
    for(int i=1; i<n; i++){
        //현재 노드에서 가장 가까운 거리에 있는 노드를 꺼내고 방문한 노드를 방문처리
        int now = getSmallestNode();
        visited[now] = true;

        //현재노드와 연결된 다른 노드들의 최단 거리 확인
        for(int j=0; j<graph[now].size(); j++){
            int cost = dis[now] + graph[now][j].second; //비용은 현재노드의 최단거리 + 연결된 다른 노드까지의 거리
            //현재 노드를 거쳐 다른 노드로 이동하는 거리가 더 짧은 경우
            if(cost<dis[graph[now][j].first]){
                dis[graph[now][j].first] = cost;    //새로운 값으로 갱신
            }
        }
    }


}

int main(void){
    cin >> n >> m >> start;
    // 모든 간선 정보 입력 받기
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a>> b>> c;
        graph[a].push_back({b, c}); //노드 a에서 b로 가는 비용이 c라는 의미 
    }

    //최단 거리 테이블을 모두 무한대 값으로 초기화
    //fill_n(초기화하고싶은배열 이름, 배열의 크기, 초기화 하려는 값)으로 사용할 수 있다.
    fill_n(dis,10001,INF);
    //start에 대해 다익스트라 알고리즘을 수행
    dijkstra(start);

    //모든 노드에 대해 각각 갈 수 있는 최단거리를 출력
    for(int i=1; i<=n; i++){
        if(dis[i]==INF){
            cout<< "Node" << i << ":" << "INF" <<'\n';
        }
        else{
            cout<< "Node" << i << ":" << dis[i] <<'\n';
        }
    }

}




