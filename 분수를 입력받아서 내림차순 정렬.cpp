#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 정수

void InputData() {
    cin >> N;
}

// 분수를 나타내는 구조체
struct Fraction {
    int molecule;   // 분자
    int denominator; // 분모

    // 분수를 출력하는 함수
    void print() const {
        std::cout << molecule << "/" << denominator;
    }

    // 분수의 값을 double로 반환하는 함수
    double value() const {
        return static_cast<double>(molecule) / denominator;
    }
};

// 분수를 비교하는 함수
bool compareFractions(const Fraction& a, const Fraction& b) {
    // a/b < c/d 는 a*d < b*c 와 동일
    return a.molecule * b.denominator < b.molecule * a.denominator;
}

// 분수의 값이 같은지 비교하는 함수
bool equalFractions(const Fraction& a, const Fraction& b) {
    return a.value() == b.value();
}

int main() {
    InputData(); // 입력
    vector<Fraction> fractions;
    Fraction f;

    for (int i = 1; i <= N; i++) { // 분모(molecule)
        for (int j = 0; j <= i; j++) { // 분자(denominator)
            if (j == 0 && i != 1) continue;
            if (i == j && i != 1) continue;
            f.molecule = j;
            f.denominator = i;
            fractions.push_back(f);
        }
    }

    // 분수 정렬 (분모가 작은 순서로 정렬)
    std::sort(fractions.begin(), fractions.end(), [](const Fraction& a, const Fraction& b) {
        if (a.value() == b.value()) {
            return a.denominator < b.denominator;
        }
        return a.value() < b.value();
    });

    // 중복된 분수 제거
    auto last = std::unique(fractions.begin(), fractions.end(), equalFractions);
    fractions.erase(last, fractions.end());

    // 정렬된 분수 출력
    for (const auto& fraction : fractions) {
        fraction.print();
        std::cout << " " << "\n";
    }
    std::cout << std::endl;

    return 0;
}
