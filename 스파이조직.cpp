// 트리의 높이를 leveld
// '<'의 경우 level +1
//'>''의 경우 level-1
//숫자인 경우 해당 level에 값 저장
 
#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
 
using namespace std;
 
int N;
string str;
//높이 별 원소 저장
//<높이,<해당원소>>
unordered_map<int,vector<string>> tree;
 
void InputData(){
    cin >> N >> str;
}
 
void solution(){
    int level = 0;
    bool flag = true;
 
    for(int i=0; i<int(str.size()); i++){
        if(str[i] == '<'){
            level++;
            flag = true;
        }else if(str[i] == '>'){
            level--;
            flag = true;
        }else{
            //숫자
            if(flag){
                int s = i;
                int j = 0;
                string st = "";
                while(true){
                    if(str[s+j] == '<' || str[s+j] == '>'){
                        break;
                    }
                    st += str[s+j];
                    st += "";
                    j++;
                }
                flag = false;
 
                tree[level].push_back(st);
            }
        }
    }
 
    for(int i=0; i<tree[N].size(); i++){
        cout << tree[N][i] << " ";
    }
 
}
 
int main (){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    solution();
 
    return 0;
}
