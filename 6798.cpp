#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;//정수
vector<int> vec;

void InputData(){ 
	cin >> N; 
}

int main() {
	InputData();//입력
	//나눴을때 1보다 작거나 같은 경우
	for(int i=1; i<=N; i++)
	{
		for(int j=0; j/i<=1; j++)
		{
			
			if (j/i == 0 || j/i == 1)
			{
				if (i!=0 || i!=1) continue;
			}
			//vec push
			vec.push_back(j/i);
			
			
			//0/1, 1/1
			//0/2, 1/2, 2/2
			//0/3, 1/3, 2/3, 3/3
			//0/4, 1/4, 2/4, 3/4, 4/4
			//0/5, 1/5, 2/5, 3/5, 4/5, 5/5

		}
		//나눴을때 1보다 작거나 같은 경우

	}
	//여기서부터 작성
	//vec 정렬 및 print
	sort(vec.begin(), vec.end());
	for (int i=0; i<vec.size(); i++) {
		cout <<	vec[i] << "\n";
	}
	return 0;
}
