// DFS 실전 문제:  음료수 얼려 먹기

#include <iostream>
using namespace std;

int n,m;
int map[1000][1000];      // 그래프 만들기

bool dfs(int x, int y){
    if(y>=m||y<0||x>=n||x<0){       // 범위를 벗어난 경우에는 false를 반환
        return false;
    }
    
    if(map[x][y]==0){   //방문한 적이 없는 노드의 경우 

        map[x][y]=1;     //해당 노드를 1로 바꿔서 방문처리
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);         // 상하좌우 모두 확인하기 위해 재귀함수 사용, 연결된 모든 지점을 방문 가능
                            
        return true;        // 상하좌우에 방문한 적 없는 노드가 있어도 어차피 처음 방문한 노드의 결과만 true를 반환하게 만듬
        // 연결된 지점들은 map에서 1로 바뀐 상태가 되어 if문안에 다시 걸리지 않음.
    }
    
    return false;   // 이미 방문했거나 가로 막힌 곳은 false를 반환

//true, false를 반환시키는데 덩어리의 개수를 찾기 위해 방문하지 않은 노드의 개수(true를 반환하는 노드의 수)만 세주면 된다.
}

int main(void){
    cin>> n >> m ;

    for(int i=0; i<n;i++){      //맵 생성
        for(int j=0; j<m;j++){
            scanf("%1d",&map[i][j]); // 공백이 없기 때문에 1자리의 정수로 인식해줄 수 있게 scanf 사용(cin은 1자리 씩 공백 포함할 때만)
        }
    }
    
    int result=0;
    for(int i=0; i<n;i++){      //true를 반환하는 노드만 세준다.
        for(int j=0; j<m;j++){
            if(dfs(i,j)){
                result ++;
            }
        }
    }

    cout<< result << '\n';

}