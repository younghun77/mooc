#include <iostream>
#include <vector>
  
using namespace std;
  
int N;
double ans, max_n = 0;
vector<double> num, result;
  
double D[10000+10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        double temp;
        cin >> temp;
        num.push_back(temp);
    }
}
double solve() {
    double temp;
    result.push_back(num[0]);
    max_n = num[0];
  
    for (int i = 1; i < N; i++) {
        if (num[i] * result[i - 1] >= num[i]){
            temp = num[i] * result[i - 1];
        }else{
            temp = num[i];
        }
  
        result.push_back(temp);
        if (max_n < temp){
            max_n = temp;
        }
    }
  
    return max_n;
  
}
  
int main(){
    InputData();// 입력받는 부분
  
    // 여기서부터 작성
    ans = solve();
  
    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}
