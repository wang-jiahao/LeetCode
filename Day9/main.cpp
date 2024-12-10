#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class MyQueue {
public:
    stack<int> A;
    stack<int> B;

    MyQueue() {
    }

    void push(int x) {
        A.push(x);
    }

    int pop() {
        if (B.empty()) {
            while (!A.empty()) {
                int x = A.top();
                A.pop();
                B.push(x);
            }
        }
        int y = B.top();
        B.pop();
        return y;
    }

    int peek() {
        if (B.empty()) {
            while (!A.empty()) {
                int x = A.top();
                A.pop();
                B.push(x);
            }
        }
        int y = B.top();
        return y;
    }

    bool empty() {
        return A.empty() && B.empty();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> deq;  // 双端队列，用来存储索引

        for (int i = 0; i < nums.size(); i++) {
            // 移除队列中已经不在窗口内的元素
            if (!deq.empty() && deq.front() < i - k + 1) {
                deq.pop_front();
            }

            // 移除队列中所有小于当前元素的索引
            while (!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }

            // 将当前元素的索引添加到队列末尾
            deq.push_back(i);

            // 当窗口已经包含k个元素时，记录当前窗口的最大值
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    auto m = s.maxSlidingWindow(nums,3);
    return 0;
}
