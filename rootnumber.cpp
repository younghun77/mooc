#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
 
using namespace std;
 
int N;
int arr[10000];
int root[10000];
 
bool compare(const pair<int, int> &a, const pair<int, int> &b){
 
    if (a.first == b.first) {
        return a.second < b.second;
    }
     
    return a.first > b.first;
}
 
int find_numroot(int num, int i){
    int num2 = num;
    if(num2 < 10){
        root[i] = num;
        return 0;
    }
 
    num = 0;
    while(num2/10 > 0){
        num = num + num2%10;
        num2 = num2/10;
    }
    num = num+num2%10;
    find_numroot(num,i);
 
    return 0;
 
}
 
int main(){
    cin >> N;
    std::vector<pair<int, int>> v;
 
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        find_numroot(n,i);
        arr[i] = n;
    }
 
    for(int i=0; i<N; i++){
         v.push_back(make_pair(root[i], arr[i]));
    }
 
    sort(v.begin(), v.end(),compare);
     
    cout<< v[0].second;
 
}
