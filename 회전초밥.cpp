#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
 
using namespace std;
 
int N, D, K, C;
int A[3000000+10];
bool check[30001];
int max_n = 0;
int start, cnt;
unordered_map<int, int> sushi;
 
void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}
 
int solve() {
    //앞과 뒤만 확인할 것이기에 미리 채워둠
    for (int i = 0; i < K - 1; i++) {
        sushi[A[i]]++;
    }
 
    //새로 확인할 것
    int end = K - 1;
 
    //1-5,2-6,3-7 이런식으로 탐색할 것이기에 앞에것은 나중에 삭제
    for(int i = 0 ; i < N ; i++){
        int del = A[start];
        int cur = A[end%N];
 
        sushi[cur]++;
         
        int num = sushi.size();
 
        // 쿠폰용 초밥을 먹지 않았다면 +1
        if (sushi.find(C) == sushi.end()) {
            max_n = max(max_n, num + 1);
        }
        else {
            max_n = max(max_n, num);
        }
        sushi[del]--; //다음 범위 확인을 위해 앞부분 삭제
 
        //만약 삭제한 스시의 갯수가 0개라면 map에서 재외
        if (sushi[del] == 0){
            sushi.erase(sushi.find(del));
        }
        start++;
        end++;
    }
 
    return max_n;
}
 
int main(){
    int ans = -1;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
