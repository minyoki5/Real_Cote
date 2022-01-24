//숫자 카드 게임(수정본): 각 행마다 가장 작은 수를 찾은 뒤 그 수 중에서 가장 큰 수 찾기

#include <iostream>
using namespace std;

int N,M;
int row_max;

int main(void){
    cin>>N >> M;
    
    for(int i=0;i<N;i++){ 
        int min_value=10001; //1~10000 까지의 숫자가 입력되므로 최소값을 10001로 초기화
        // min 값을 초기화 해주는 과정이 필요하므로 for문안에 삽입을 해야한다!!! 안 그러면 계속 가장 작은 값인 '1'로 유지가 됨.
        for(int j=0;j<M;j++){
            int x;
            cin>> x;  // 배열 입력 받기 
            min_value= min(min_value,x); // 최소값을 변수에 저장
        }
            row_max= max(row_max,min_value); // 최소값 중 최대값을 저장
    }
  
    cout<< row_max<<'\n';


}