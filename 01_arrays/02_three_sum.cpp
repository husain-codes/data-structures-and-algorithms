#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
-------------------------
Sorting + Two Pointers
-------------------------
1. Sorting: O(N log N), where N = size of nums.
2. Outer loop (i): O(N).
3. Two-pointer scan inside loop: O(N) in worst case.

=> Total = O(N^2).

Space Complexity: 
- Sorting done in-place: O(1) extra space (ignoring result storage).
- Output result can take up to O(K) where K = number of unique triplets.

So, final complexity = O(N^2) time, O(1) extra space.
*/

class ThreeSum {
public:
    // Function to find all unique triplets such that nums[i] + nums[j] + nums[k] == 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // Step 1: Sort the array
        vector<vector<int>> result;
        int size = nums.size();

        // Fix the first element and use two pointers to find the other two
        for (int i = 0; i < size; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers inward
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;   // Need a larger sum → move left pointer
                } else {
                    right--;  // Need a smaller sum → move right pointer
                }
            }
        }

        return result;
    }
};

int main() {
    ThreeSum solver;

    // Test case 1: classic example
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = solver.threeSum(nums1);
    cout << "Test 1: [-1,0,1,2,-1,-4]\n";
    for (auto& triplet : res1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]\n";
    }
    cout << "\n";

    // Test case 2: all zeros
    vector<int> nums2 = {0, 0, 0, 0};
    auto res2 = solver.threeSum(nums2);
    cout << "Test 2: [0,0,0,0]\n";
    for (auto& triplet : res2) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]\n";
    }
    cout << "\n";

    // Test case 3: no valid triplets
    vector<int> nums3 = {1, 2, 3, 4, 5};
    auto res3 = solver.threeSum(nums3);
    cout << "Test 3: [1,2,3,4,5]\n";
    for (auto& triplet : res3) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]\n";
    }
    cout << (res3.empty() ? "No triplets found\n" : "") << "\n";

    // Test case 4: mixture of negatives and positives
    vector<int> nums4 = {-2, 0, 1, 1, 2};
    auto res4 = solver.threeSum(nums4);
    cout << "Test 4: [-2,0,1,1,2]\n";
    for (auto& triplet : res4) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]\n";
    }
    cout << "\n";

    return 0;
}
