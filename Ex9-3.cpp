//최단경로 실전문제 3. 전보
//다익스트라 알고리즘을 이용
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9    //무한에 해당하는 값을 10억으로 설정
using namespace std;

int n,m,c;
// 최단 거리 테이블 만들기
int dis[30001];
// 노드 정보 테이블 만들기
vector<pair<int, int> > graph[30001];   //(노드번호, 최단거리)

void dijkstra(int c){
    //(걸리는 시간, 노드 번호)로 구성
    priority_queue <pair <int, int>> pq;
    //c 도시가 출발점이기 때문에 초기화
    pq.push({0,c});
    dis[c] = 0;

    while(!pq.empty()){
        //큐가 모두 비워질 때까지 
        // 거리 정보와 현재 노드의 정보를 뽑는다. 
        int distance = -pq.top().first;
        int now = pq.top().second;
        //뽑고 나면 큐에서 제거
        pq.pop();

        if(distance > dis[now]){    // 이미 최단거리를 갱신한 노드는 pass
            continue;
        }

        //현재 노드에서 연결된 다른 노드들과의 거리를 비교
        for(int i=0; i<graph[now].size(); i++){
            //비용을 계산, 현재까지 도달한 거리정보와 연결된 다른 노드와의 거리를 합한다.
            int cost = distance + graph[now][i].second;
            if(cost < dis[graph[now][i].first]){    //새로 계산된 비용이 더 작으면 값을 갱신
                dis[graph[now][i].first] = cost ;
                pq.push(make_pair(-cost,graph[now][i].first));  //우선순위 큐에 삽입
            }
        }


    }

    
}

int main(void){

    cin >> n >> m >> c;

    //1. 노드,간선정보 입력받기
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // X번 노드에서 Y번 노드로 가는 비용이 Z라는 의미
        graph[x].push_back({y, z});
    }
    //2. 최단거리 테이블의 거리를 무한대로 초기화
    fill(dis, dis + 30001, INF);

    //3. 다익스트라 실행
    dijkstra(c);

    //4. 메세지를 받는 도시의 수는 C에서 거리가 무한대가 아닌 도시의 갯수
    // 모든 메세지를 받는데 걸리는 시간은 무한대를 제외한 노드 중 최대 값
    int count=0;
    int max_time=0;

    for(int i=0; i<n; i++){
        if(dis[i]!=INF){
            count++;
            if(dis[i]>max_time){
                max_time = dis[i];
            }
        }
    }

    cout << count << ' ' << max_time << '\n';
    



}

