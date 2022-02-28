//다이나믹 프로그래밍 실전문제 4. 바닥공사

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1001];

int main(void){
    cin >> n;

    d[1]=1;
    d[2]=3;

    int result=0;

    for(int i=3; i<=n; i++){
        d[i] = d[i-1] + 2 * d[i-2];
        result = d[i] % 796796;     //나머지 연산을 한 결과를 출력
    }
    
    cout<< result;

}