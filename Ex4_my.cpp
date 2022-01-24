//1이 될 때까지 (첫 풀이) : n이 4로 나누어 떨어질 때까지 뺐음

#include <iostream>
using namespace std;

int n,k;

int main(void){
    cin >> n >> k ;
    int cnt=0;

    while(true){
        if(n%k==0){
            n/=k;
        }
        else{
            n-=1;
        }
        cnt++;
        if(n==1){
            break;
        }

    }
    cout << cnt <<'\n'; 
}