#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        auto isVal = [val](int n) {
            return n == val;
        };
        nums.erase(remove_if(nums.begin(), nums.end(),isVal ), nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> arr = {3, 2, 2, 3};
    Solution s;
    int k = s.removeElement(arr, 3);
    cout << k << endl;
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}
