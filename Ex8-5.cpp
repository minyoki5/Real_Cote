//다이나믹 프로그래밍 실전문제 5. 효율적인 화폐구성
//아직 너무 어려움.. 다시 풀어보기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;    //n은 화폐의 종류, m은 만들어야하는 합
vector<int> arr;

int main(void){
    cin >> n >> m;

    for(int i=0; i<n; i++){     //각 화폐의 가치를 저장 
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    //한 번 계산한 결과를 저장하기 위해 dp테이블 초기화
    vector<int> d(m+1,10001);

    d[0]=0;
    for(int i=0; i<n; i++){
        for(int j=arr[i]; j<=m; j++){
            if(d[j - arr[i]] != 10001){     //(i-k)원을 만드는 방법이 존재하는 경우
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }
    }

    if(d[m]==10001){
        cout << -1 <<'\n';
    }
    else{
        cout << d[m] <<'\n';
    }

}