#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute Force Solution for Two Sum Problem
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class TwoSumBrute {
public:
    // Function to find indices of two numbers that add up to target
    vector<int> twoSum (vector<int> &nums, int target) {
        vector<int> result; // to store the answer indices
        
        // Check every possible pair (i, j)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                
                // If the pair adds up to target, store the indices
                if (target == nums[i] + nums[j]) {
                    result.push_back(i);
                    result.push_back(j);
                    
                    // Since problem guarantees exactly one solution,
                    // we can return immediately after finding it
                    return result;
                }
            }
        }
        
        // If no solution is found (not expected per problem statement),
        // return empty vector
        return result;
    }
};

/*
 Complexity Analysis:
- Step 1 (build pairs): O(n)
- Step 2 (sorting): O(n log n)
- Step 3 (two-pointer search): O(n)
-----------------------------------
Total Time = O(n log n)
Space = O(n)  (for arr vector storing pairs)
*/

class TwoSumSort {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int size = nums.size();
        vector<pair<int,int>> arr;  // will store (value, original_index)

        // Step 1: Store numbers with their original indices
        // O(n) time, O(n) space
        for (int i = 0; i < size; i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort by values
        // O(n log n) time
        sort(arr.begin(), arr.end());

        // Step 3: Two-pointer search
        int left = 0;
        int right = size - 1;

        // Move pointers until they meet
        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                // Found the required pair
                result.push_back(arr[left].second);  // original index of left number
                result.push_back(arr[right].second); // original index of right number
                break; // stop, since problem guarantees one solution
            }
            else if (sum < target) {
                left++;   // increase sum by moving left pointer
            }
            else {
                right--;  // decrease sum by moving right pointer
            }
        }

        return result;
    }
};


int main() {
    // Example input
    vector<int> nums = {2,7,11,5};
    int target = 9;

    // Create object of TwoSumBrute
    TwoSumBrute twoSumBrute;

    // Call the brute force method
    vector<int> result = twoSumBrute.twoSum(nums, target);

    // Print result in [i , j] format
    cout << "[ " << result[0] << " , " << result[1] << " ]" << endl;
	
	// Create object of TwoSumSort
    TwoSumBrute twoSumSort;

    // Call the sort  method
    result = twoSumSort.twoSum(nums, target);

    // Print result in [i , j] format
    cout << "[ " << result[0] << " , " << result[1] << " ]" << endl;

    return 0;
}
