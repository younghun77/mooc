// 처음에 빙고개수가 무조건 3개라 생각해서 틀림
// 3개 이상도 가능
#include <iostream>
  
using namespace std;
  
int A[5+10][5+10];
int B[25+10];
int ans = 0;
int visited[5+10][5+10];
int cnt = 0;
 
void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}
 
//왼쪽 위에서 오른쪽 아래로 내려오는 대각선
bool check_diagonal1(){
    bool flag = true;
    for(int i=0; i<5; i++){
        if(!visited[i][i]){
            flag = false;
        }
    }
    return flag;
}
 
//오른쪽 위에서 왼쪽 아래로 내려오는 대각선
bool check_diagonal2(){
    bool flag = true;
    for(int i=0; i<5; i++){
        if(!visited[i][4-i]){
            flag = false;
        }
    }
    return flag;
}
 
//세로
bool check_col(int col){
    bool flag = true;
    for(int i=0; i<5; i++){
        if(!visited[i][col]){
            flag = false;
        }
    }
  
    return flag;
}
 
//가로
bool check_row(int row){
    bool flag = true;
    for(int i=0; i<5; i++){
        if(!visited[row][i]){
            flag = false;
        }
    }
  
    return flag;
}
  
void isBinggo(int row, int col){
    //가로 빙고 확인
    if(check_row(row)){
        cnt++;
    }
    //세로 확인
    if(check_col(col)){
        cnt++;
    }
    //대각선 확인
    if(row == col){
        if(check_diagonal1()){
            cnt++;
        }
    }
  
    if(row+col == 4){
        if(check_diagonal2()){
            cnt++;
        }
    }
}
  
void check(int n){
    for(int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if(A[i][j] == n){
                visited[i][j] = 1;
                isBinggo(i,j);
            }
        }
    }
}
  
void solve(){
    for(int i=0; i<25; i++){
        check(B[i]);
        if(cnt >= 3){
            ans = i+1;
            break;
        }
    }
  
}
  
int main(){
    InputData();// 입력받는 부분
  
    // 여기서부터 작성
    solve();
  
    cout << ans << endl;// 출력하는 부분
    return 0;
}
