#include <iostream>
#include<algorithm>
#include<cmath>
#include<string>
 
using namespace std;
int N;//빌딩의 층수
int ans = 0;
 
void InputData(){
    cin >> N;
}
 
int calc_sum(int n){
   string n_str = to_string(n);
   int sum = 0;
   for(int i=0; i< n_str.size(); i++){
        int num = n_str[i] - '0';
        if(num>=4){
            num--;
        }
        sum += num*(pow(9,n_str.size()-i-1));
   }
 
    return sum;
}
 
void solve(){
    ans = calc_sum(N);
}
 
int main(){
    InputData();//입력받는 부분
 
    //여기서부터 작성
    solve();
 
    cout << ans << endl;//출력하는 부분
    return 0;
}
