#include<iostream>
#include<string>
 
using namespace std;
 
string str;
int check;
int ans = 0;
 
void InputData(){
    cin >> str;
}
 
void solve(){
    for (int i = 0; i < int(str.size()); i++) {
        // 매 괄호마다 검토
        if (str[i] == '('){
            check++;
        }
        else{
            check--;
        }
 
        //'('가 없는데 ')'인 경우
        if (check < 0) {
            ans++;
            check = 1; //올바르게 뒤집음
        }
    }
     
    //')'보다 '('가 더 많이 나온 경우
    if (check > 0){
        ans += check / 2;
    }
 
}
 
int main(){
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
