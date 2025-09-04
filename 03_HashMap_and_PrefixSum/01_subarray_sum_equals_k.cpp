#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
=====================================================
Problem: Subarray Sum Equals K
Approach:
- Use a prefix sum and hashmap (unordered_map) to store
  how many times each prefix sum has occurred.
- For each element, compute current prefix sum (sum).
- If (sum - k) exists in map, it means there are 
  "umap[sum - k]" subarrays ending at current index 
  that sum to k.
- Increment count by umap[sum - k].
- Update umap[sum] by 1 (record this prefix sum).
=====================================================
Time Complexity:
O(n) → One pass through nums, each map operation O(1) average.
Space Complexity:
O(n) → For hashmap storing prefix sums.
*/

int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    unordered_map<int,int> umap;
    umap[0] = 1; // Base case: empty prefix has sum = 0

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // Update running prefix sum
        
        // Check if (sum - k) has been seen before
        auto it = umap.find(sum - k);
        if (it != umap.end()) {
            count += it->second; // Add number of ways
        }

        // Record this prefix sum
        umap[sum]++;
    }
    return count;
}

int main() {
    // ========================
    // Test cases
    // ========================

    vector<int> nums1 = {1, -1, 0};
    cout << "Test 1: " << subarraySum(nums1, 0) << endl;
    // Expected: 3 → [1,-1], [0], [1,-1,0]

    vector<int> nums2 = {1, 2, 3};
    cout << "Test 2: " << subarraySum(nums2, 3) << endl;
    // Expected: 2 → [1,2], [3]

    vector<int> nums3 = {1, 1, 1};
    cout << "Test 3: " << subarraySum(nums3, 2) << endl;
    // Expected: 2 → [1,1] at (0,1) and (1,2)

    vector<int> nums4 = {0, 0, 0};
    cout << "Test 4: " << subarraySum(nums4, 0) << endl;
    // Expected: 6 → [0]x3, [0,0]x2, [0,0,0]x1

    vector<int> nums5 = {-1, -1, 1};
    cout << "Test 5: " << subarraySum(nums5, 0) << endl;
    // Expected: 1 → [-1,-1,1]

    vector<int> nums6 = {100, -100, 100};
    cout << "Test 6: " << subarraySum(nums6, 0) << endl;
    // Expected: 1 → [100, -100]

    return 0;
}
