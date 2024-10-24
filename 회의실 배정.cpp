#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>
 
using namespace std;
 
int N;
 
//회의실 정보 <번호, 시작시간, 끝 시간, 소요 시간>
vector<tuple<int, int, int>> meeting;
vector<int> ans;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        int n, s, e;
        cin >> n >> s >> e;
        meeting.push_back(make_tuple(n,s,e));
    }
}
 
void OutputData(){
    cout << ans.size() << "\n";
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
 
static bool cmp(tuple<int, int, int> &v1, tuple<int, int, int> &v2)
{
    return get<2>(v1) < get<2>(v2);//tuple 3번째 값으로 비교
}
 
void solve(){
    sort(meeting.begin(), meeting.end(), cmp);
 
    int time = get<2>(meeting[0]); //종료시간
    ans.push_back(get<0>(meeting[0]));
 
    for(int i=0; i<N; i++){
        for (int i = 1 ;i < N; i++) {
            if (time <= get<1>(meeting[i])){
                ans.push_back(get<0>(meeting[i]));
                time = get<2>(meeting[i]);
            }
        }
    }
}
 
int main(){
    int ans = -1;
 
    InputData();// 입력받는 부분
 
    //여기서부터 작성
    solve();
 
    OutputData();// 출력하는 부분
    return 0;
}
