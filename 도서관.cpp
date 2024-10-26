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
        //만약 이전 학생이 떠나는 시간보다 다음 학생의 도착 시간이 빠르다면 →  구간이 이어짐 : 구간의 끝값을 다시 계산해 주어야 하는데, 시작시간이 느려도 이전 학생이 더 늦게 떠날 수도 있으므로 max값으로 갱신
        if(current_s<=e){
            e = max(current_e,e);
            present = max(e-s, present);
        }
        //하지만 다음 학생이 이전 학생이 떠난 후에 도착 →  학생이 한 명도 머물지 않았던 시간을 갱신 : 이전의 시작 시간 바꿔줌
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
