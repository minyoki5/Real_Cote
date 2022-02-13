// 이진 탐색 실전문제.  부품찾기 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n , m;
vector<int> arr;
vector<int> targets;

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


int main(void){
    cin >> n;

    for(int i=0; i<n; i++){ //리스트에 가지고 있는 부품의 고유번호를 저장
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cin >> m; 

    for(int i=0; i<m; i++){ //손님이 요청하는 부품 번호 리스트에 저장
        int target;
        cin >> target;
        targets.push_back(target);
    }

    //이진탐색을 활용하기 위해 매장의 부품을 미리 정렬
    sort(arr.begin(),arr.end());

    for(int i=0; i<m; i++){
      int result = binarySearch(arr,targets[i],0,n-1);  //이진탐색을 수행
      if(result != -1){
          cout << "yes" << ' ';
      }
      else{
          cout << "no" << ' ';
      }
    }
    
}
/*
// 또 다른 방법. 계수정렬을 이용 
int arr2[100001];
vector<int> targets;

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr2[x]=1;  //입력받은 부품 번호의 인덱스를 1로 바꿔준다...
    }

    cin >> m;

    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        targets.push_back(x);
    }

    for(int i=0; i<m; i++){
        if(arr2[targets[i]]==1){    //해당 부품번호의 인덱스가 1이면 (부품이 존재하면)
            cout << "yes" << ' ';
        }
        else{
            cout << "no" << ' ';
        }
    }
}
*/