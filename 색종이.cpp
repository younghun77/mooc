#include <iostream>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
int N;
int paper[101][101] = { 0 };
int ans=0;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        int a;
        int b;
        cin >> a >> b;
        for (int i = a; i < a + 10; i++){
            for (int j = b; j < b + 10; j++){
                paper[i][j] = 1;
            }
        }
    }
}
 
int solve(){
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
  
    for (int r = 1; r < 101; r++){
        for (int c = 1; c < 101; c++){
            if(paper[r][c] == 1){
                for (int i = 0; i < 4; i++){
                    // 상하좌우중 0인 것 존재 : 테두리
                    if (paper[r + dy[i]][c + dx[i]] == 0){
                        ans++;
                    }
                }
            }
        }
    }
  
    return ans;
}
     
 
int main(){
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
