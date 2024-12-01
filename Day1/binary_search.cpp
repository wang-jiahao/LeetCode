#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//binary search
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
                mid = left + (right - left) / 2;
            } else {
                right = mid - 1;
                mid = left + (right - left) / 2;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr{1, 3, 5, 7, 9};
    cout << s.search(arr, 9);

    return 0;
}
