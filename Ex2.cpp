// 실전 문제: 큰 수의 법칙 (수정본)

#include <iostream>
#include <algorithm> //sort함수 사용을 위해 필요한 헤더파일 
#include <vector> //벡터 사용을 위해 필요한 헤더파일

using namespace std;

int n,m,k;
vector<int> v;

int main(void){

    cin>> n >> m>> k;

    for(int i=0;i<n;i++){ //벡터 입력받기
        int x;
        cin >> x;
        v.push_back(x);
}

sort(v.begin(),v.end()); // 오름차순으로 벡터를 정렬

int first, second;

first=v[n-1];//가장 큰 수 저장
second=v[n-2]; // 두번째로 큰 수 저장

//가장 큰수가 K번 더해지고 두 번째로 큰 수가 1번 더해지는 형태의 반복
int cnt= m/(k+1) * k + m%(k+1); // 가장 큰 숫자가 더해지는 횟수는 M번을 (K+1)번으로 나누는 몫에 K배 해주고, 나머지 연산을 한 것을 더해준 값이다.
//두번 째 값은 몫 연산을 한 횟수만큼 더 해질 것이다.

int sum=first*cnt+ second*m/(k+1);

cout<< sum <<'\n'; //endl보다 '\n'이 빠름

}