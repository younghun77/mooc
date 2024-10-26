#include <iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int N;//영화수
int ans;
 
vector<pair<int, int>> movie;
 
void InputData(){
    cin >> N;
    int s,e;
    for (int i=0; i<N; i++){
        cin >> s >> e;
        movie.push_back(make_pair(e,s));
    }
}
 
void solution(){
 
    sort(movie.begin(), movie.end());
     
    int time = movie[0].first;
    ans = 1;
    for (int i = 1 ;i < N; i++){
        if (time <= movie[i].second && ((movie[i].first - movie[i].second) >= 2)){
            ans++;
            time = movie[i].first;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력받는 부분
 
    //여기서부터 작성
    solution();
 
    cout << ans << "\n";//출력하는 부분
    return 0;
}
