//8. 다이나믹 프로그래밍 
//큰 문제를 작은 문제로 나누고, 같은 문제는 리스트에서 가져오는 방식
//메모제이션(memoization) 기법인 top-down 방식, bottom-up 방식

#include <iostream>
using namespace std;

int fibo(int x){    //재귀함수의 형태로 피보나치 수열을 구현, 이 형태에서는 n이 커질수록 수행시간이 기하급수적으로 늘어남
    if(x == 1 || x == 2){   //종료 조건
        return 1;
    }
    return fibo(x-1) + fibo(x-2);
}

long long d[100];   //한번 계산된 결과를 리스트(배열)에 저장하기 위해 배열 초기화

long long fibo_topdown(int x){  //top-down방법, 큰 문제를 해결하기 위해 작은 문제를 호출하는 방식, 재귀함수 이용
    if(x == 1 || x == 2){
        return 1;
    }
    //이미 계산했던 문제는 그대로 반환(다이나믹 프로그래밍의 특징!!!!)
    if(d[x]!=0){
        return d[x];
    }
    //계산된 적이 없는 문제면 점화식을 적용
    d[x]= fibo_topdown(x-1)+fibo_topdown(x-2);
    return d[x];

}
long long d1[100]; //앞서 계산된 결과를 저장하기 위한 'DP테이블' 초기화

int main(void){
    cout << fibo(4) <<'\n';
    cout << fibo_topdown(50) <<'\n';

    // 
    d1[1]=1;
    d1[2]=1;
    int n=50;

    for(int i=3; i<=50; i++){   //반복문을 통해 작은 문제부터 답을 도출해 나가는 bottom-up 방식
        d1[i]=d1[i-1]+d1[i-2];
    }
    cout << d1[n] << '\n';

    
    
}