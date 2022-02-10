//실전문제 4번. 두 배열의 원소 교체

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arrA[100000];
int arrB[100000];

int main(void){

    cin >> n >> k ;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arrA[i]=x;
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arrB[i]=x;
    }
    //배열 A는 오름차순, B는 내림차순으로 정렬
    sort(arrA,arrA+n);
    sort(arrB,arrB+n,greater<>());
    


    for(int i=0; i<k ; i++){
        //A의 가장 작은 원소가 B의 가장 큰 원소보다 작은 값일 때만 교환
        if(arrA[0]<arrB[0]){
            swap(arrA[0],arrB[0]);  //A의 가장 작은 값과 B의 가장큰 값을 교환
            sort(arrA,arrA+n);
            sort(arrB,arrB+n,greater<>());
        //교환 후 다시 정렬해서 반복할 수 있게
        }
        else{
            break;  //아닌 경우는 중지
        }
        
    }

    /*for(int i=0; i<n; i++){
        cout << arrA[i] <<' ';
     }

     for(int i=0; i<n; i++){
        cout << arrB[i] <<' ';
     }
*/

    //A의 모든 원소의 합을 구한다.
    long long result=0;     // 원소의 값이 10,000 이하까지 가능하기 때문에 합의 자료형을 long long으로 정해줌

    for(int i=0; i<n; i++){
        result+=arrA[i];
    }

    cout << result << '\n';

}