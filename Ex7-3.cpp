//이진탐색 실전문제 3. 떡볶이 떡 만들기
//높이를 이진탐색으로 범위를 줄여가며 찾기 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, h;
vector<int> v;


int main(void){
    cin >> n >> m ;

    for(int i=0; i<n ; i++){    //리스트에 떡의 개별 높이를 저장
        int x;
        cin >> x;
        v.push_back(x);
    }
    //이진탐색의 시작점과 끝점을 설정
    int start = 0;  //0 또는
    int end = 1e9;  //10억 보다 작거나 같은 양의 정수 
    int result = 0; //절단기에 설정 가능한 최대의 높이


        while(start <= end){
            long long int total = 0;    //잘린 떡의 길이의 합
            int mid = (start + end)/2;

            for(int i=0; i<n; i++){     //잘린 떡의 길이 합을 계산
                if(v[i]>mid){
                    total += v[i] - mid;
                }
            }
            
            if(total < m){  // 길이의 합이 부족한 경우, 더 많이 잘라야 하니깐 왼쪽 부분 탐색
                end = mid - 1;
            }
            else{   //요청한 길이를 만족하는 경우 최대의 높이를 찾아야 하니깐 오른쪽 부분 탐색
                result = mid;   // result에 최대의 높이를 기록
                start = mid + 1;
            }
        }
        
        cout << result <<'\n';

}

