#include <stdio.h>
#include <string>
#include <iostream>
  
using namespace std;
  
string str;
int ans;
 
void InputData(){
    cin >> str;
}
 
int solution(){
  
    int check_right{ 0 }; // 예외 1
    int check_left{ 0 }; // 예외 2
    int check{ 0 };
  
    for (int i = 0; i < int(str.size()); i++) {
        if (str[i] == '(') {
            check++;
            // 예외 2 체크
            if (check >= 2){
                check_left++;
            }
        }
        if (str[i] == ')') {
            check--;
            check_right++;
             
            // 예외 1 체크
            if (check < 0){
                return check_right;
            }
        }
         
        // check가 2보다 작을 때 예외 2
        if (check < 2){
            check_left = 0;
        }
    }
    return check_left;
}
  
int main(){
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = solution();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
