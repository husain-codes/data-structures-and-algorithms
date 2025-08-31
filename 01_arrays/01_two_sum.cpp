#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
===============================
   Approach 1: Brute Force
===============================
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class TwoSumBrute {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        // Step 1: Check every possible pair (i, j)
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Step 2: If pair adds up to target, return indices
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result; // Early exit, since one solution guaranteed
                }
            }
        }

        // Step 3: Return empty vector if no solution (edge case)
        return result;
    }
};


/*
===============================
   Approach 2: Sorting + Two Pointers
===============================
Steps:
1. Store (value, original_index) pairs.
2. Sort by value.
3. Use two-pointer search to find target sum.
-------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
class TwoSumSort {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int size = nums.size();
        vector<pair<int,int>> arr;  // {value, original_index}

        // Step 1: Store elements with original indices
        for (int i = 0; i < size; i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort by value
        sort(arr.begin(), arr.end());

        // Step 3: Two-pointer search
        int left = 0, right = size - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                // Found the pair
                result.push_back(arr[left].second);
                result.push_back(arr[right].second);
                break;
            }
            else if (sum < target) left++;
            else right--;
        }

        return result;
    }
};


/*
===============================
   Approach 3: Hash Map
===============================
Steps:
1. Build a hash map {value -> index}.
2. For each element, check if target - value exists.
-------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
class TwoSumHash {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> arr;  // {value -> index}

        // Step 1: Build hash map
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = i;   // Insert / overwrite index
        }

        // Step 2: Check complements
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = arr.find(complement);

            if (it != arr.end() && it->second != i) {
                result.push_back(i);
                result.push_back(it->second);
                break; // One solution guaranteed
            }
        }

        return result;
    }
};


int main() {
    // Example input
    vector<int> nums = {2, 7, 11, 5};
    int target = 9;

    // ====== Brute Force ======
    TwoSumBrute bruteSolver;
    vector<int> result = bruteSolver.twoSum(nums, target);

    if (!result.empty())
        cout << "Brute Force Result: [ " << result[0] << " , " << result[1] << " ]" << endl;
    else
        cout << "Brute Force: No solution found" << endl;

    // ====== Sort + Two Pointers ======
    TwoSumSort sortSolver;
    result = sortSolver.twoSum(nums, target);

    if (!result.empty())
        cout << "Sort + Two Pointers Result: [ " << result[0] << " , " << result[1] << " ]" << endl;
    else
        cout << "Sort + Two Pointers: No solution found" << endl;

    // ====== Hash Map ======
    TwoSumHash hashSolver;
    result = hashSolver.twoSum(nums, target);

    if (!result.empty())
        cout << "Hash Map Result: [ " << result[0] << " , " << result[1] << " ]" << endl;
    else
        cout << "Hash Map: No solution found" << endl;

    // ====== Corner Case Demo ======
    vector<int> nums2 = {1}; // only one element
    result = hashSolver.twoSum(nums2, 2);
    if (result.empty())
        cout << "Corner Case (single element): No solution found" << endl;

    return 0;
}
