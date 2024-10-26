#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>
 
using namespace std;
 
int N, C, M;
int ans;
vector<tuple<int, int, int>> car;
int capacity[10001] = {0};
 
void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        int s,e,num;
        cin >> s >> e >> num;
        car.push_back(make_tuple(s,e,num));
    }
}
 
//2번째 원소 기준 오름차순 정렬
static bool cmp(tuple<int, int, int> &v1, tuple<int, int, int> &v2)
{
    if(get<1>(v1) == get<1>(v2)){
        return get<0>(v1) < get<0>(v2);
    }
 
    return get<1>(v1) < get<1>(v2);
}
 
void solution(){
 
    sort(car.begin(), car.end(), cmp);
 
    for(int i=0; i<M; i++){
 
        int maxnum = 0;
 
        //트럭을 돌면서 가장 많이 쌓인 양
        for (int j = get<0>(car[i]); j < get<1>(car[i]); j++){
            maxnum = max(capacity[j], maxnum);
        }
 
        //트럭에 더 싣을 수 있는 양
        int cnt = min(get<2>(car[i]), C - maxnum);
        ans += cnt;
         
        //구간마다 쌓는 양 계산
        for (int j = get<0>(car[i]); j < get<1>(car[i]); j++) {
            capacity[j] += cnt;
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
