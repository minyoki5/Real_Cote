//구현 실전문제: 게임 개발, 시뮬레이션 유형 
// 처음 접하니 매우 어려움,,, 
#include<iostream>

using namespace std;

int n,m; // N은 세로, M은 가로
int a,b,dir;  // 입력받은 칸과 바라보는 방향 

int map[50][50]; // 입력받을 맵, 육지:0 바다:1
int d[50][50]; // 캐릭터가 이동한 위치를 기록하는 맵도 생성

//방향에 따른 x,y의 이동을 나타내기 위해 dir순서에 따라 배열 생성
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void turn_left(){   // 현재 방향 기준으로 왼쪽 방향으로 차례대로 방향 정해주기
    dir -= 1;
    if(dir==-1)
    {
        dir=3;
    }
}


int main(void){

    cin >> n >> m;
    cin >> a >> b >> dir;

    d[a][b]=1; // 캐릭터가 시작하는 곳을 1로 표시해서 기록

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }

    // 캐릭터가 이동하는 시뮬레이션 시작.
    int cnt = 1;    //첫 좌표도 카운트셈
    int turn_time=0;    //4방향 모두 고려했을 때도 갈 곳이 없어서 반복문 탈출할 때 상황을 위해 

    while(true){
        turn_left();    // 매뉴얼 1번. 현재 방향 기준으로 왼쪽 방향으로 방향 전환

        //다음 이동할 좌표를 설정
        int x= a + dx[dir];
        int y= b + dy[dir];

        //매뉴얼 2번.
        if(map[x][y]==0 && d[x][y]==0){   // 아직 가보지 않은 칸+ 육지 일 경우 
        // 이동위치를 기록 + 그 방향으로 전진
            d[x][y]=1;
            a=x;
            b=y;
            cnt++;
            turn_time=0; // 회전 횟수 초기화
            continue; //다시 반복문 돌 수 있게 
        }
        else{   // 가보지 않은 칸이 없는 경우= 가본 칸만 있을 경우 + 바다가 있을 경우
            turn_time+=1;
        }

        //매뉴얼 3번.
        if(turn_time==4){
            x=a-dx[dir];
            y=b-dy[dir];

            if(map[x][y]==0) {  //뒤로 이동할 수 있는 경우 (뒤가 육지일 때)
                a=x;
                b=y;
            }  
            else{
                break;
            } 
                turn_time=0;           
           
        }
        

    }




cout << cnt <<'\n'; 



}
