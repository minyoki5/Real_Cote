// 실전 문제: 큰 수의 법칙 (첫 풀이)

#include <iostream>
#include <algorithm> //sort함수 사용을 위해 필요한 헤더파일 

using namespace std;

bool desc(int a, int b){ // 내림차순 정렬을 위한 함수 정의
    return a>b; 
}

int n,m,k;

int main(void){

    cin>> n >> m>> k;
    int arr[100]={};

    for(int i=0;i<n;i++){ //배열 입력받기
        cin >> arr[i];
}

sort(arr,arr+n,desc); // 내림차순으로 벡터를 정렬

int sum=0;
int K=0;

for(int i=0; i< m;i++){ //M번동안 더해줌
    if(K<k){ //K번 더할때까지 가장큰값 더해주기
        sum+=arr[0];
        K++;
    }
    else{ //K번 넘어가면 둘째 값 더해주고 K를 다시 초기화
        sum+=arr[1];
        K=0;
    }
}

cout<< sum <<'\n'; //endl보다 '\n'이 빠름

}