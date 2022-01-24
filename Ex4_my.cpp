//1이 될 때까지 (첫 풀이) : n이 k로 나누어 떨어질 때까지 뺐음

#include <iostream>
using namespace std;

int n,k;

int main(void){
    cin >> n >> k ; // n,k입력 받기
    int cnt=0; //카운트 세기

    while(true){
        if(n%k==0){ //n이 k로 나누어 떨어지면 나누기
            n/=k;
        }
        else{  // 아닌 경우는 1을 계속 빼기
            n-=1;
        }
        cnt++;
        if(n==1){ //n이 1이 되면 탈출
            break;
        }

    }
    cout << cnt <<'\n'; 
}