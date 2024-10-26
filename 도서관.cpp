#include <iostream>
#include <algorithm>
#include<vector>
 
using namespace std;
 
int N;
int present;
int absent;
vector<pair<int, int>> student;
 
void InputData(void){
    cin >> N;
    int s,e;
    for (int i=0; i<N; i++){
        cin >> s >> e;
        student.push_back(make_pair(s,e));
    }
}
  
void solution(){
    //학생들 시작 시간으로 정렬
    sort(student.begin(), student.end());
  
    int s=0, e=0;
    int current_s,current_e;
 
    for(int i = 0; i<N; i++){
        current_s = student[i].first;
        current_e = student[i].second;
        if(current_s<=e){
            e = max(current_e,e);
            present = max(e-s, present);
        }
        else{
            absent = max(current_s-e, absent);
            s = current_s;
            e = current_e;
        }
    }
}
  
 
int main(void){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    solution();
 
    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}
