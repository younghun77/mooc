#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int N;
 
unordered_map<string,vector<int>> dict; //문자열과 나온 idx 저장
vector<string> words; //입력받는 순서대로 문자열 저장
 
 
void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        string str;
        cin >> str;
        dict[str].push_back(i);
        if(dict[str].size()==1){ // 처음 들어온 문자열이면 words에 추가
            words.push_back(str);
        }
    }
}
 
void solve(){
    bool flag = false; //unique인지 판단
 
    for (int i= 0; i<words.size(); i++){
        string target = words[i];
        string str = "";
 
        //1번 이상 나왔던 단어
        if(dict[target].size() != 1){
            str += target;
            str += " ";
            flag = true;
            for(int j=0; j< dict[target].size(); j++){
                str += to_string(dict[target][j]);
                str += " ";
            }
            cout << str << '\n';
        }
  }
 
  if(!flag){
    cout<< "unique" << '\n';
  }
 
}
 
int main(){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    solve();
 
    return 0;
}
