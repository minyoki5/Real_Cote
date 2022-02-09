// 정렬의 4가지 방법 : 선택정렬(Selection Sort) 삽입정렬(Insertion Sort) 퀵 정렬(Quick Sort) 계수정렬(Count Sort)

#include <iostream>
#include <algorithm> // swap 함수를 사용하기 위한 라이브러리 
#define Max_Value 9 // 인덱스 범위를 0~9로 설정하려고 9로 Max를 설정
using namespace std;

int n = 10;
int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int m=15;
int arr2[15] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};


void SelectionSort(int arr[]){  //1.선택정렬 

    //가장 작은 원소의 인덱스를 찾기
    for(int i=0; i<n; i++){
        int min_index=i;    //가장 작은 원소의 인덱스 
        for(int j=i+1; j<n; j++){   //i번째 이후 인덱스들과 값을 비교 
           if(arr[j]<arr[min_index]){
               min_index=j;
           } 
        }
        //swap를 이용해서 인덱스에 해당하는 값 변경하기 (가장 작은 값과 i번째 값을 변경하는 과정을 반복)
        swap(arr[i],arr[min_index]);
    }

}

void InsertionSort(int arr[]){  //2.삽입정렬
    for(int i=1; i<n; i++){ //첫번째 인덱스는 이미 정렬된 것으로 생각하기 때문에 1부터 시작
        for(int j=i; j>0; j--){     
            if(arr[j]<arr[j-1]){    //정렬되어있는 원소가 자기보다 클 경우 swap
                swap(arr[j],arr[j-1]);
            }
            else{
                break;  //자신보다 작은 데이터에 삽입
            }
        }
    }

}

void QuickSort(int *arr, int start, int end){   //3.퀵 정렬, 매개변수에 시작 점과 끝점이 포함된다.

    if(start >= end){return;}     //리스트 안의 원소가 1개일 경우 종료
    int pivot=start;    //첫 원소를 피벗으로 만듬
    int left=start+1;
    int right=end;

    while(left <= right){   // 교차되기 전까지 피벗보다 큰 데이터를 left부터, 작은 데이터를 right부터 찾기
        while(left <= end && arr[left] <= arr[pivot]){  //피벗보다 큰 원소 찾기
            left++;
        }
        while(right > start && arr[right] >= arr[pivot]){  //피벗보다 작은 원소 찾기
            right--;
        }
        if(right > left){   //교차되지 않는 경우 좌,우 원소값을 교체
            swap(arr[left],arr[right]);
        }
        else{   //교차되는 경우 피벗보다 작은 값과 피벗의 원소값 교체
            swap(arr[right],arr[pivot]);
        }

    }
        // 분할이후 좌,우 리스트에 대해서 재귀함수를 사용하여 정렬을 수행 
        QuickSort(arr,start,right-1);
        QuickSort(arr,right+1,end);

}

int cnt[Max_Value+1];     //모든 범위를 포함하는 리스트 선언(모든 원소값은 0으로 초기화)

void CountSort(int arr[]){
    

    for(int i=0; i<m; i++){
        cnt[arr2[i]]+=1;    //각 원소값에 해당하는 인덱스의 값을 증가시킴 
    }

}



int main(void){
   //SelectionSort(arr);
   //InsertionSort(arr);
   QuickSort(arr, 0, n-1);
   CountSort(arr2);

    
    //  for(int i = 0; i < n; i++) {
    //     cout << arr[i] << ' ';
    // }
    

    for (int i = 0; i <= Max_Value; i++) { // 배열에 기록된 정렬 정보 확인
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << ' '; // 띄어쓰기를 기준으로 등장한 횟수만큼 인덱스 출력
        }
    }

}