#include<iostream>
 
using namespace std;
 
int N;
int P;
int check[1000];
int ans = 0;
 
void input_data(){
    cin >> N >> P;
}
 
void solve(){
    int n = N;
 
    while(true){
        n = (n*N)%P;
        if(check[n] == 2){
            break;
        }
        check[n]++;
    }
 
    for(int i=0; i<P; i++){
        if(check[i] == 2){
            ans++;
        }
    }
 
}
 
int main(){
    ios::sync_with_stdio(0);
    input_data();
 
    solve();
 
    cout << ans << '\n';
 
}
