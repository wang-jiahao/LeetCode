#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool lemonadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;
    for (auto bill: bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) { return false; }
            ten++;
            five--;
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool Palindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) { return false; }
    }
    return true;
}

bool validPalindrome(string s) {
    if (Palindrome(s)) { return true; }
    int n = s.size();
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return Palindrome(string(s.begin() + i + 1, s.begin() + n - i)) || Palindrome(
                       string(s.begin() + i, s.begin() + n - i - 1));
        }
    }
    return true;
}

int main() {
    string s("abc");
    cout << validPalindrome(s) << endl;

    return 0;
}
