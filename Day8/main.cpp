#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        string result = "";
        while (!stk.empty()) {
            auto c = stk.top();
            result += c;
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isAnagram(string s, string t) {
        //等价于排序后是否相同
        if (s.length() != t.length()) { return false; }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    return 0;
}
