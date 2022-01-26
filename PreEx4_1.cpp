// 구현 part: 예제4-1(첫 풀이)
#include <string> // getline 함수를 사용하기 위해 string library 사용
#include <iostream>
using namespace std;

int n;
int x=1,y=1;
// char move[4]={'L','R','U','D'};

int main(void){

    cin >> n;
    string plans;

    cin.ignore();// 공백을 제거해주는 함수
    getline(cin,plans); //getline() 함수는 공백포함된 문자열을 받기에 편리

    for(int i=0;i<plans.size();i++){

        char plan=plans[i];

        if(plan=='L'){ //왼쪽으로 이동하는 경우
            if(x>1){    //이동할 수 있는 경우에만 이동
                x-=1;
            }
        }
        else if(plan=='R'){
            if(x<n){    //이동할 수 있는 경우에만 이동
                x+=1;
            }
        }
        else if(plan=='U'){
            if(y>1){    //이동할 수 있는 경우에만 이동
                y-=1;
            }
        }
        else if(plan=='D'){
            if(y<n){    //이동할 수 있는 경우에만 이동
                y+=1;
            }
        }

    }

    cout << y << " " << x << '\n';

    
}