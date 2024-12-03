#include <iostream>
#include<stack>
 
using namespace std;
 
#define MAXN ((int)5e5)
 
int N, K;
char str[MAXN + 10];
int cnt;
stack<char> num;
stack<char> tmp;
 
void InputData() {
    cin >> N >> K;
    cin >> str;
}
 
void solution(){
    for(int i=0; i<N; i++){
        while (!num.empty() && cnt < K && str[i] > num.top()){
            cnt++;
            num.pop();
        }
        num.push(str[i]);
    }
 
    //pop한 수가 K보다 작으면 추가로 pop
    while (cnt < K){
        cnt++;
        num.pop();
    }
 
    //출력하기 위해 스택 순서 거꾸로
    while (!num.empty()){
        tmp.push(num.top());
        num.pop();
    }
 
    while (!tmp.empty()){
        cout << tmp.top();
        tmp.pop();
    }
}
 
int main() {
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    solution();
 
    return 0;
}
