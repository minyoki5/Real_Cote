// 실전 문제: 큰 수의 법칙 

#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b){  // 내림차순을 만들어주는 함수 정의
    return a>b;
}

int main(void){

    int n,m,k;
    int sum=0;

    cin>> n >> m>> k;

    int arr[100]={}; // 배열 만들기~

    for(int i=0;i<n;i++){ // 배열 입력받기
        cin >> arr[i];
}

sort(arr,arr+n,desc); // 크기가 큰 순서대로 배열을 정렬, 
//sort함수는 오름차순 정렬을 실행시켜주나 desc함수를 정의해서 내림차순으로 

int K=0;

for(int i=0;i<m;i++){//m번 더해주기
if(K<k){ //m번 더할 때 까지 최대 값(첫 인덱스) 더해줌
sum+=arr[0];
K++;
}
else{//m번 더해주면 그 다음 인덱스를 한 번 더해주고 M을 0으로 초기화 시켜서 다시 최대값 m번 더해주게함
sum+=arr[1];
K=0;
}

}
cout<<sum<<endl; // 결과를 출력

}