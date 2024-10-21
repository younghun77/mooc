#include <iostream>
 
using namespace std;
 
int K;
int A[6+10];
int B[6+10];
int direc[4]; // 방향 별 등장 횟수 저장
 
void InputData(){
    cin >> K;
    for (int i=0 ; i<6 ; i++){
        cin >> A[i] >> B[i];
        direc[A[i]]++;
    }
}
 
int solve(){
 
    int small = 1; // 작은 사각형의 넓이
    int big = 1; // 큰 사각형의 넓이
 
    for (int i = 0; i < 6; i++) {
 
        if (direc[A[i]] == 1) {
            // 한 번씩 등장하는 방향
            big *= B[i]; // 큰 사각형의 가로/세로
            continue;
        }
 
        //작은 사각형 구하기
        int now = (i + 1) % 6;
        int next = (i + 2) % 6;
         
        //같은 방향 사이에 낀 값이 작은 사각형의 가로/세로
        if (A[i] == A[next]){
            small *= B[now];
        }
    }
 
    return (big - small) * K;
 
}
 
int main(){
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
   
