//숫자 카드 게임(첫 풀이)

#include <iostream>
using namespace std;

int N,M;

int main(void){
    cin>>N >> M;
    int arr[100][100]={}; // 2차원 배열 생성
    int row[100]={};
    
    int row_max=1; // 최대값을 저장하기 위해 1로 초기화

    for(int i=0;i<N;i++){ 
        int min=10001; //1~10000 까지의 숫자가 입력되므로 최소값을 10001로 초기화
        // min 값을 초기화 해주는 과정이 필요하므로 for문안에 삽입을 해야한다!!! 안 그러면 계속 가장 작은 값인 '1'로 유지가 됨.
        for(int j=0;j<M;j++){
            cin>> arr[i][j];  // 배열 입력 받기 
            if(min>=arr[i][j]){ //행의 최소값을 배열에 저장
                min = arr[i][j];
            }
            row[i]=min;
        }
            if(row_max<=row[i]){ // 행의 최소값들을 비교하여 최대 값을 저장
                row_max=row[i];
            }
    }
  
    cout<< row_max<<'\n';


}