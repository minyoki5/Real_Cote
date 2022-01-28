//구현 실전문제: 왕실의 나이트 (첫 풀이)
//+) cin으로 문자열 입력받으면 공백이 입력되면 종료되기 때문에, 공백이 포함된 경우에는 getline함수를 사용한다.

#include <iostream>
#include <string>
 
using namespace std;
string pos;

int main(void){

    cin>> pos;  //나이트의 현재 위치 입력 받기
    
    // 입력받은 좌표를 행과 열로 변환. string 클래스를 사용하면 문자열을 배열처럼 한 문자씩 다룰 수 있다.
    //(1,1)~(8,8)의 좌표로 만들어준다.

    int row=pos[1]-'0';
    int col=pos[0]-'a'+1; 

    int cnt=0;

    //가능한 8가지 case를 모두 검사해서 count 하기
        if(row+2<=8){
            if(col+1<=8){
                cnt++;
            }
            if(col-1>=1){
                cnt++;
            }
        }
        if(row-2>=1){
            if(col+1<=8){
                cnt++;
            }
            if(col-1>=1){
                cnt++;
            }
        }
        if(col+2<=8){
            if(row+1<=8){
                cnt++;
            }
            if(row-1>=1){
                cnt++;
            }
        }
        if(col-2>=1){
            if(row+1<=8){
                cnt++;
            }
            if(row-1>=1){
                cnt++;
            }
        }
        
    
    cout<< cnt ;

    

}