#include <iostream>
#include <string>
#include<queue>
 
 
using namespace std;
 
#define MAXN ((int)1e4)
  
int M, T, N;
 
struct passenger{
    int AT;
    string SIDE;
    int arrive_time;
};
 
struct passenger p_data[MAXN+10];
queue<struct passenger *> q[2]; // 0-> left , 1->right
 
void InputData() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> p_data[i].AT >> p_data[i].SIDE;
    }
}
 
void OutputData() {
    for (int i = 0; i < N; i++) {
        cout << p_data[i].arrive_time << "\n";
    }
}
 
  
void solution(){
    // queue 채우기
    for(int i = 0; i<N; i++){
        if(p_data[i].SIDE == "left"){
            q[0].push(p_data+i);
        }
        else{
            q[1].push(p_data+i);
        }
    }
  
    int arrived_cnt = 0;
    int cur_time = 0;
    int cur_pos = 0; // 0-> left 1-> right
  
    while(arrived_cnt < N){
        // 현재 정박지에 탈수 있는 사람이 있으면
        if(!q[cur_pos].empty() && q[cur_pos].front()->AT <= cur_time){
            int cnt = 0;
            while(!q[cur_pos].empty() && cnt < M && q[cur_pos].front()->AT <= cur_time){
                q[cur_pos].front()->arrive_time = cur_time+T;
                q[cur_pos].pop();
                arrived_cnt +=1;
                cnt+=1;
            }
  
            cur_time+=T;
            cur_pos^=1;
        }
        else{
            //현재 정박지에 탈수 있는 사람이 없음
            // 1)queue 자체에 사람 X
            if(q[cur_pos].empty()){
                cur_pos^=1;
                cur_time = max(cur_time , q[cur_pos].front()->AT);
                cur_time += T;
            }
            // 2)시간때문에 사람 X
            else{
                // 반대쪽 도착 시간이 더 빠름
                if(!q[cur_pos^1].empty() && q[cur_pos].front()->AT > q[cur_pos^1].front()->AT){
                    cur_pos^=1;
                    cur_time = max(q[cur_pos].front()->AT, cur_time);
                    cur_time+=T;
                }
                else{
                    cur_time = q[cur_pos].front()->AT;
                }
            }
  
        }
  
    }
  
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    InputData();//입력받는 부분
     
    //여기서부터 작성
    solution();
 
    OutputData();//출력하는 부분
    return 0;
}
