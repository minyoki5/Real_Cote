// BFS 실전문제 , 미로 탈출
#include <iostream>
#include <queue>
using namespace std;

int n,m;
int graph[201][201];      // 그래프 만들기
queue<pair<int, int> > q;   // 2차원 배열 큐 생성하는 방법임. 
//열에 해당하는 값에 대한 무언가를 하고 싶으면 first를, 행에 해당하는 값에 대한거면 second를 사용한다.

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};     //상,좌,하,우 순서

void bfs(int x,int y){
    q.push({x,y});

    while(!q.empty()){  //큐가 완전히 비워질 때 까지 실행 

       int x = q.front().first;
       int y = q.front().second;

        q.pop();

        for(int i=0; i<4 ; i++){    // 주변에 이동 가능한 노드가 있는지 확인
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0||ny<0||nx>=n||ny>=m){continue;} // 경계를 넘어가면 무시 
            if(graph[nx][ny]==0){continue;} //괴물이 있는 곳도 무시 

            if(graph[nx][ny]==1){   //갈 수 있는 노드인 경우
                graph[nx][ny]=graph[x][y] + 1;   // 이동 거리를 계산하기 위해 원래 있던 노드보다 값을 1증가 시킨다. 
                q.push({nx,ny});
            }
        }

    }


}

int main(void){

    cin >> n >> m;

    for(int i=0; i<n;i++){      //맵 생성
        for(int j=0; j<m;j++){
            scanf("%1d",&graph[i][j]); // 공백이 없기 때문에 1자리의 정수로 인식해줄 수 있게 scanf 사용(cin은 1자리 씩 공백 포함할 때만)
        }
    }
    bfs(0,0);

    cout<< graph[n-1][m-1] << '\n';

}
