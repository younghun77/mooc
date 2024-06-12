#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

bool compareFractions(const Fraction &a, const Fraction &b) {
    return (a.numerator * b.denominator) > (b.numerator * a.denominator);
}

int main() {
    int N;
    vector<Fraction> fractions;

    cout << "Enter the number of fractions: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        Fraction f;
        cout << "Enter numerator for fraction " << i + 1 << ": ";
        cin >> f.numerator;
        cout << "Enter denominator for fraction " << i + 1 << ": ";
        cin >> f.denominator;
        fractions.push_back(f);
    }

    sort(fractions.begin(), fractions.end(), compareFractions);

    cout << "Fractions in descending order: " << endl;
    for (const auto &fraction : fractions) {
        cout << fraction.numerator << "/" << fraction.denominator << endl;
    }

    return 0;
}
