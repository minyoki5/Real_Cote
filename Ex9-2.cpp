//최단 경로 실전문제 2. 미래도시
#include <iostream>
#include <algorithm>
#define INF 1e9    //무한에 해당하는 값을 10억으로 설정
using namespace std;

int n,m,x,k;
int graph[101][101];

int main(void){

    cin >> n >> m;

    //1. graph의 간선들을 무한대로 초기화
    for(int i=0; i<101; i++){
        fill(graph[i],graph[i]+101,INF);
    }

    //2. 자기 자신으로 가는 노드들은 거리를 0으로 초기화
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            if(a == b){
            graph[a][b] = 0;
            }
        }
    }

    //3. 간선정보 입력받기
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b ;
        graph[a][b] = 1;
        graph[b][a] = 1;    //모든 경로를 가는데 소요되는 시간은 1 + 양방향 이동 가능
    }

    //4. 플로이드-워셜 알고리즘 수행
    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
            //점화식:A에서 B로 가는 최소 비용과 A에서 K를 거쳐 B로 가는 비용을 비교해서 작은 값으로 갱신
               graph[a][b] = min( graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    //5. 생성된 그래프에서 결과 출력
    cin >> x >> k; 
    int result= graph[1][k] + graph[k][x];

    if (result >= INF) {
        cout << "-1" << '\n';
    }
    // 도달할 수 있다면, 최단 거리를 출력
    else {
        cout << result << '\n';
    }
    
}

