#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;

class MyStack {
public:
    queue<int> a;
    queue<int> b;

    MyStack() {
    }

    void push(int x) {
        a.push(x);
    }

    int pop() {
        while (a.size() != 1) {
            b.push(a.front());
            a.pop();
        }
        int x = a.front();
        a.pop();
        swap(a, b);
        return x;
    }

    int top() {
        while (a.size() != 1) {
            b.push(a.front());
            a.pop();
        }
        int x = a.front();
        b.push(x);
        a.pop();
        swap(a, b);
        return x;
    }

    bool empty() {
        return a.empty();
    }
};

vector<string> commonChars(vector<string> &words) {
    vector<string> result;
    int n = words.size();
    if (n == 1) {
        for (auto c: words[0]) {
            string str(1, c);
            result.push_back(str);
        }
        return result;
    }
    unordered_map<char, int> map;
    for (auto c: words[0]) {
        map[c] += 1;
    }
    for (int i = 1; i < n; i++) {
        unordered_map<char, int> m;
        for (auto c: words[i]) {
            m[c] += 1;
        }
        for (auto c: words[0]) {
            if (m[c] < map[c]) {
                map[c] = m[c];
            }
        }
    }
    for (auto c: words[0]) {
        while (map[c] > 0) {
            string str(1, c);
            result.push_back(str);
            map[c]--;
        }
    }
    return result;
}

int main() {
    vector<string> v = {"bella", "label", "roller"};
    auto result = commonChars(v);
    for (auto s: result) {
        cout << s << endl;
    }

    return 0;
}
