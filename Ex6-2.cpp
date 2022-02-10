// 정렬 실전문제 2번. 위에서 아래로. 내림차순으로 입력받은 수들을 정렬하기
// sort알고리즘을 사용하기 위해 algorithm 헤더파일 사용, sort 알고리즘은 퀵정렬 기반으로 만들어짐
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500];

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){ //배열에 입력받은 값들을 저장
        int x;
        cin >> x;
        arr[i]=x;
    }

    sort(arr,arr+n,greater<>());    // 배열을 내림차순으로 정렬 (sort함수의 default는 오름차순이고, 3번째 인자에 
    //  bool함수로 사용자지정한 비교법도 가능)

    for(int i=0; i<n; i++){ //배열에 입력받은 값들을 저장
        cout << arr[i] << ' ';
    }


}