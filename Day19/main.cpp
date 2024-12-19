#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
using namespace std;

int findGCD(vector<int> &nums) {
    int minimum = *min_element(nums.begin(), nums.end());
    int maximum = *max_element(nums.begin(), nums.end());
    return gcd(maximum, minimum);
}

vector<int> partitionLabels(string s) {
    //贪心，相同字母的下标一定在同一片段中
    vector<int> result;
    vector<int> last_position(26); //记录每一个字母最后一次出现的下标位置
    for (int i = 0; i < s.size(); ++i) {
        last_position[s[i] - 'a'] = i;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.size(); ++i) {
        end = max(end, last_position[s[i] - 'a']);
        if (i == end) {
            result.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return result;
}

int main() {
    return 0;
}
