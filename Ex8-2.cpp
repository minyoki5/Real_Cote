//다이나믹 프로그래밍 실전문제 2번. 1로 만들기

#include <iostream>
#include <algorithm>
using namespace std;

int d[30001];   // 앞서 계산한 결과를 저장하기 위해 dp 테이블을 초기화시킴 
int x;

// bottom-up 방식으로 다이나믹 프로그래밍 진행
int main(void){
    cin >> x;

    for(int i=2; i<x+1; i++){
        // 1. 1을 빼는 경우
        d[i]=d[i-1]+1;
        //2. 2로 나눠지는 경우
        if(i%2==0){
            d[i]=min(d[i],d[i/2]+1);
        }
        //3. 3으로 나눠지는 경우
        if(i%3==0){
            d[i]=min(d[i],d[i/3]+1);
        }
        //4. 5로 나눠지는 경우
        if(i%5==0){
            d[i]=min(d[i],d[i/5]+1);
        }       

    }

    

    cout << d[x] ;
}