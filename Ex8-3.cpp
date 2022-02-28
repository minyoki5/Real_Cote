//다이나믹 프로그래밍 실전문제 3. 개미전사

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int d[1001];    //dp 테이블 초기화
vector<int> arr;

int main(void){

    cin >> n;

    //식량창고 입력 받기
    for(int i=0; i<n; i++){ 
        int x;
        cin >> x;
        arr.push_back(x); 
    }

    d[0]=arr[0];    //1개일 때
    d[1]=max(arr[0],arr[1]);    //2개일 때

    for(int i=2; i<n; i++){    //3개인 경우부터는 합을 비교해봐야함
        //d[i-1] 값과 새로 더해지는 값과 d[i-2]값을 비교
        d[i] = max(d[i-1], d[i-2] + arr[i]);
            }

    cout << d[n-1]; //인덱스가 0부터 시작이므로 n-1번 째 인덱스를 출력!



}