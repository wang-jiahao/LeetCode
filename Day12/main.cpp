#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> occurences;
    int result = 0;
    bool any_odd = false;
    for (auto c: s) {
        occurences[c] += 1;
    }
    for (auto [c,i]: occurences) {
        if (i % 2 == 0) {
            result += i;
        } else {
            result += i - 1;
            any_odd = true;
        }
    }
    return any_odd ? result + 1 : result;
}

int findContentChildren(vector<int> &g, vector<int> &s) {
    if (g.size() == 0 || s.size() == 0) { return 0; }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int j = 0;
    int result = 0;
    for (int i = 0; i < g.size() && j < s.size(); i++) {
        while (j < s.size()) {
            if (s[j] >= g[i]) {
                j++;
                result++;
                break;
            }
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {3};
    auto count = findContentChildren(g, s);
    cout << count << endl;
    string str("abccccdd");
    int l = longestPalindrome(str);
    cout << l << endl;

    return 0;
}
