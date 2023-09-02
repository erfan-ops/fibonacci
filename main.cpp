#include <bits/stdc++.h>

typedef unsigned __int64 u64;

using namespace std;

string addBigNumbers(string number1, string number2) {
    if (number1.length() > number2.length())
    swap(number1, number2);
    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    for (int i=len1-1; i>=0; i--) {
        intSum = ((number1[i]-'0') + (number2[i+digitDiff]- '0') + carry);
        sum.push_back(intSum%10 + '0');
        carry = intSum/10;
    }
    for (int i=digitDiff-1; i>=0; i--) {
        intSum = ((number2[i]-'0')+carry);
        sum.push_back(intSum%10 + '0');
        carry = intSum/10;
    }
    if (carry)
    sum.push_back(carry+'0');
    reverse(sum.begin(), sum.end());
    return sum;
}

int main() {
    string num1 = "0";
    string num2 = "1";
    string max;
    clock_t start, end;
    ofstream file("fibonacci.txt");
    u64 n;
    
    cout << "How many fibonacci iterations do you want? : ";
    cin >> n;

    start = clock();

    for (u64 i = 0; i < n-2; i++) {
        file << num1 << '\n';
        max = addBigNumbers(num1, num2);
        num1 = num2;
        num2 = max;
    }
    file << num1 << '\n';
    file << num2 << '\n';

    end = clock();

    cout << "calculated in " << (double)(end - start)/(double)CLOCKS_PER_SEC << " s\n";
    cout << "last number has " << max.length() << " digits" << endl;
    
    file.close();

    return 0;
}