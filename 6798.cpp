#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;//정수

void InputData(){ 
	cin >> N; 
}

struct Fraction {
    int molecule;
    int denominator;
};


bool compareFractions(const Fraction &a, const Fraction &b) {
    return (a.molecule * b.denominator) > (b.molecule * a.denominator);
}
// 중복된 값을 제거하는 함수
void removeDuplicates(vector<Fraction> &fractions) {
    for (int i = 0; i < fractions.size() - 1; i++) {
        if (fractions[i].molecule == fractions[i + 1].molecule) {
            // 중복된 값일 경우에는 분모가 큰 수를 제거
            if (fractions[i].denominator > fractions[i + 1].denominator) {
                fractions.erase(fractions.begin() + i + 1);
            } else {
                fractions.erase(fractions.begin() + i);
            }
        }
    }
}


int main() {
	InputData();//입력
	vector<Fraction> fractions;
	Fraction f;
	//여기서부터 작성
	//0값 : 0/1 및 1값 : 1/1은 제외하고 sort한 다음 front와 back에 각각 push
	//여기서 중요한것은 중간에 있는 값들을 어떻게 정렬할 것인지 여부

	//0/1, 1/1
	//0/2, 1/2, 2/2
	//0/3, 1/3, 2/3, 3/3
	//0/4, 1/4, 2/4, 3/4, 4/4
	//0/5, 1/5, 2/5, 3/5, 4/5, 5/5
	for(int i=1; i<=N; i++) //분모(molecule)
	{
		for(int j=0; j<=i; j++) //분자(denominator)
		{
			
			if (j == 0 && i != 1) continue;
			if (i == j && i != 1) continue;
			f.molecule = i;
			f.denominator = j;
			fractions.push_back(f);
		}
	}
	sort(fractions.begin(), fractions.end(), compareFractions);
    for (int i = 0; i < fractions.size() - 1; i++)
    {
        if (fractions[i].molecule * fractions[i+1].denominator == fractions[i].denominator * fractions[i+1].molecule)
        {
            fractions.erase(fractions.begin()+i+1);
        }
        //cout << fractions[i].denominator << "/" << fractions[i].molecule << endl;
    }
    for (const auto &fraction : fractions) 
    {
        cout << fraction.denominator << "/" << fraction.molecule << endl;
    }
	return 0;
}
