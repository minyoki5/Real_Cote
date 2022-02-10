#include <iostream>
#include <vector>   //리스트를 사용하기 위한 헤더파일
#include <algorithm>
using namespace std;

class Student{      //학생의 (이름, 성적)정보를 객체로 저장하기 위해 클래스 선언
    public:
    string name;
    int score;
    Student(string name,int score){ //생성자 
    //  this를 사용해서 멤버 변수를 초기화 해준다. this 는 자신을 가리키는 것이라고 생각
        this -> name= name;
        this -> score= score;
    }
    //  Student 객체들이 성적에 대해 정렬이 이루어질 수 있도록 연산자 재정의 
    bool operator <(Student &other){
        return this->score < other.score;
    }

};

int n;
vector<Student> v;

int main(void){
    cin >> n;
    
    for(int i=0; i<n; i++){     //리스트에 Student객체를 저장
        string name;
        int score;
        cin >> name >> score;
        v.push_back(Student(name,score));
    }
    sort(v.begin(),v.end());    //내림차순으로 정렬

    for(int i=0; i<n; i++){
        cout<<v[i].name<<' ';
    }

}