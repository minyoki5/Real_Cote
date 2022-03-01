//#3. 플로이드 워셜 알고리즘- 다이나믹 프로그래밍의 방법을 이용
//2차원 리스트를 이용해 해당 노드를 거쳐가는 모든 경우를 계산해서 갱신
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

// 노드의 개수(N), 간선의 개수(M)
// 노드의 개수는 최대 500개라고 가정
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[501][501];

int main(void){
    cin >> n >> m;

    //최단 거리 테이블을 모두 무한대로 초기화
    for(int i=0; i<501; i++){
        //fill(시작주소,끝나는주소,초기화값)로 사용
        fill(graph[i],graph[i]+501,INF);
    }

    //자기 자신 노드로 가는 거리는 0으로 초기화
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            if(a==b){
                graph[a][b]=0;
            }
        }
    }

    //간선 정보 입력받기
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a>> b>> c;
        graph[a][b]=c;   //노드 a에서 b로 가는 비용이 c라는 의미 
    }

    //점화식에 따라 플로이드 워셜 알고리즘을 수행
    for(int k=1; k<=n; k++){
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                graph[a][b] = min( graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    //실행한 결과를 출력
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            if(graph[a][b]==INF){
                cout << "INFINITY" << ' ';
            }
            else{
                cout << graph[a][b] << ' ';
            }
        }
        cout << '\n';
    }

}