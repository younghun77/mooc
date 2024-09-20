#include<iostream>
 
using namespace std;
 
#define MAXN ((int)1e3)
int n;
int ans = 0;
int check[MAXN];
 
int calc_num(int num){
    int sum = 0;
    int temp = num;
 
    while(num !=0 ){
        temp = num % 10;
        sum += temp*temp;
        num /= 10;
    }
 
    return sum;
}
 
bool happyNum(int num){
     
    while(true){
        num = calc_num(num);
        if(num == 1){
            return true;
        }else if(check[num] == 1){
            break;
        }
 
        check[num] = 1;
 
    }
    return false;
}
void solve(){
 
    for(int i=n; i>0; i--){
        if(happyNum(i)){
            ans = i;
            break;
        }
    }
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
 
    solve();
 
    cout<< ans << '\n';
     
}
