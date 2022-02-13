// 이진탐색 기본 코드
// 1. 재귀함수를 통해 구현 , 2. 반복문을 통해 구현

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr,int target, int start, int end){ //1. 재귀함수를 이용한 구현

    if(start > end){ return -1; }
    int mid = (start + end)/2;  //정수형으로 선언해서 소수점 아래는 버릴 수 있게(몫을 구하는 방법)

    if(arr[mid]==target){   //찾고자 하는 값이 중간값과 같으면 인덱스를 반환
        return mid;
        }    
    else if(arr[mid]<target){   //찾고자 하는 값이 중간값보다 크면 중간값 오른쪽을 확인
        return  binarySearch(arr,target,mid+1,end);
    }
    else{   // 찾고자 하는 값이 중간값보다 작으면 왼쪽을 확인
        return  binarySearch(arr,target,start,mid-1);
    }
    
}

int binarySearch2(vector<int>& arr,int target, int start, int end){     //2. 반복문을 이용해서 구현
    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start = mid +1;
        }
        else{
            end = mid -1;        
        }
    }

}

int n, target;
vector<int> arr;

int main(void){
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n'; //인덱스는 0부터시작이니깐 1을 더해준다.
    }

}