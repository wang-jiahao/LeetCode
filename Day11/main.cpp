#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for (char c: s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (c == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
    }
    if (!stk.empty()) { return false; }
    return true;
}

bool canConstruct(string ransomNote, string magazine) {
    vector<int> arr1(26, 0);
    vector<int> arr2(26, 0);
    for (char c: ransomNote) {
        arr1[c - 'a'] += 1;
    }
    for (char c: magazine) {
        arr2[c - 'a'] += 1;
    }
    for (int i = 0; i < 26; ++i) {
        if (arr2[i] < arr1[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s("([])");
    cout << isValid(s) << endl;
    return 0;
}
