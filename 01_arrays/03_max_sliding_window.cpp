#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
========================================================
Brute Force Approach
========================================================
Explanation:
- For every window of size k, scan all k elements to find the maximum.
- Very simple but inefficient when n is large.

Time Complexity:
- Outer loop: (n-k+1) iterations (for each window)
- Inner loop: k iterations (to find max in each window)
- Total: O((n-k+1) * k) ≈ O(n * k)

Space Complexity:
- O(n-k+1) for the result vector (output)
- O(1) extra space (no additional data structures)
*/
class MaxSlidingWindowBrute {
public:
    // Brute force sliding window maximum
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;

        // Iterate through all possible windows
        for (int i = 0; i < (nums.size() - k + 1); i++) {
            int max = maxElement(nums, i, i + k - 1);
            result.push_back(max);
        }
        return result;
    };

private:
    // Helper: find max in nums[left..right]
    int maxElement(vector<int> &nums, int left, int right) {
        int maxElement = nums[left];
        for (int i = left; i <= right; i++) {
            if (maxElement < nums[i])
                maxElement = nums[i];
        }
        return maxElement;
    };
};

/*
========================================================
Optimized Deque Approach
========================================================
Explanation:
- Uses a deque to store indices of elements in decreasing order of their values.
- Maintains only useful elements for the current window.
- Front of deque always has the index of the maximum element.

Time Complexity:
- Each element is pushed and popped at most once → O(n)
- Much faster than brute force when n is large.

Space Complexity:
- O(n-k+1) for result vector
- O(k) for the deque
*/
class MaxSlidingWindowDq {
public:
    // Deque-based optimized sliding window maximum
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> dq; // stores indices, not values

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of this window
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Window of size k formed → record max
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    };
};

int main() {
    // =========================
    // Test cases (including edge cases)
    // =========================
    vector<vector<int>> testCases = {
        {1, 3, -1, -3, 5, 3, 6, 7},   // Regular case
        {1},                           // Single element
        {9, 8, 7, 6, 5},               // Decreasing sequence
        {1, 2, 3, 4, 5},               // Increasing sequence
        {4, 4, 4, 4, 4},               // All elements same
        {-1, -3, -5, -2, -1},          // All negative numbers
        {}                             // Empty array
    };

    vector<int> ks = {3, 1, 2, 3, 2, 2, 1}; // Corresponding window sizes

    // Instantiate classes
    MaxSlidingWindowBrute bruteSolver;
    MaxSlidingWindowDq dqSolver;

    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];
        int k = ks[t];

        cout << "\nTest Case " << t + 1 << ": nums = { ";
        for (int x : nums) cout << x << " ";
        cout << "}, k = " << k << endl;

        // Handle empty input edge case
        if (nums.empty() || k <= 0) {
            cout << "Invalid input (empty array or invalid k)\n";
            continue;
        }

        // Brute Force result
        vector<int> bruteResult = bruteSolver.maxSlidingWindow(nums, k);
        cout << "Brute Force Result: ";
        for (int x : bruteResult) cout << x << " ";
        cout << endl;

        // Deque Optimized result
        vector<int> dqResult = dqSolver.maxSlidingWindow(nums, k);
        cout << "Deque Result      : ";
        for (int x : dqResult) cout << x << " ";
        cout << endl;
    }

    return 0;
}
