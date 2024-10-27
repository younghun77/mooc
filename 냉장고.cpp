#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int N;
int ans;
vector<pair<int,int>> v;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
}
 
void solution(){
 
    sort(v.begin(), v.end());
 
    int low = -280; //구간 최소값
    int high = -280; // 구간 최대값
 
    for(int i=0; i<N; i++){
        int s = v[i].first; // 시작 온도
        int e = v[i].second; // 끝 온도
 
        //기존 구간의 최대값보다 시작온도가 큼 -> 구간 새로
        if(high < s){
            ans++;
            low = s;
            high = e;
        }else{
            high = min(e, high);
            low = max(s,low);
        }
    }
 
}
 
int main(){
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    solution();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
