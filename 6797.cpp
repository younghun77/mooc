#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arry[4];

void InputData(){
	cin >> N;
}



int main()
{
	int ans = -1;
	int bigNum, lowNum, delta = -1;
	int number;
	int cnt = 0;
	InputData();// 입력받는 부분
    //자리수를 바꿔가면서 
	// 여기서부터 작성
		
	while (delta != 6174)
	{
		if (cnt == 0) number = N;
		else number = delta;
		
		arry[0] = number/1000;
		arry[1] = (number%1000)/100;
		arry[2] = ((number%1000) - arry[1]*100)/10;
		arry[3] = ((number%1000) - arry[1]*100 - arry[2]*10);
	
		sort(arry, arry+4);

		bigNum = arry[0]+arry[1]*10+arry[2]*100+arry[3]*1000;
		lowNum = arry[3]+arry[2]*10+arry[1]*100+arry[0]*1000;
		
		delta = bigNum - lowNum;
		cnt++;
	}

	ans = cnt; 
	cout << ans << endl;// 출력하는 부분

	return 0;
}
