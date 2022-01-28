// 왕실의 나이트 문제(다른 풀이)
// 이번엔 dx,dy를 도입하여 반복문으로 모든 case를 검사하는 방법을 사용

#include <iostream>
#include <string>

using namespace std;

string pos;
//나이트가 이동할 수 있는 모든 방향을 정의한다. 
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={-1,-2,-2,-1,1,2,2,1};

int main(void){
    cin>>pos;

    int cnt=0;
    int row=pos[1]-'0';
    int col=pos[0]-'a'+1;

    for(int i=0;i<8;i++){ // for문 돌면서 모든 case 검사
    int nextRow=row+dy[i];
    int nextCol=col+dx[i];

    if(1<=nextRow&&nextRow<=8&&1<=nextCol&&nextCol<=8){
        cnt++;
    }

    }
    cout<<cnt<<'\n';


}