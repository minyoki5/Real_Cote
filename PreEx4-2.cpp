//구현 part: 예제 4-2, 시각

#include <iostream>
using namespace std;

int n;

bool check(int h, int m, int s){ // 3이 포함되는 지 확인하는 함수 생성. 문자열 사용안해도됨 이러면

    if(h%10==3||m/10==3||m%10==3||s/10==3||s%10==3){
        return true;
    }
    else{
        return false;
    }

}

int main(void){
    cin >> n;

    string time;
    int count=0;

    //3중 for문을 사용해서 모든 경우를 탐색할 수 있게 한다.
    for(int i=0;i<n+1;i++){     //0시~N시 까지 경우
        for(int j=0;j<60;j++){  //0~59분 
            for(int k=0; k<60; k++){    //0~59초
            if(check(i,j,k)==true){
                count++;
            }
            }
        }
    }
    cout<<count<<'\n';

    
}