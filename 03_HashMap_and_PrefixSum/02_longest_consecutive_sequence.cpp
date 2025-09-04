#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
====================================================
Time Complexity:
- Building the unordered_set: O(n)
- Outer loop runs for each unique element: O(n)
- Inner while loop across all elements combined: O(n)
=> Overall: O(n)

Space Complexity:
- O(n) for the unordered_set
====================================================
*/
int longestConsecutive(vector<int> &nums);

int main() {
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << longestConsecutive(nums1) << endl; // 4

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    cout << "Test 2: " << longestConsecutive(nums2) << endl; // 9

    vector<int> nums3 = {1,2,3,4,5};
    cout << "Test 3: " << longestConsecutive(nums3) << endl; // 5

    vector<int> nums4 = {};
    cout << "Test 4: " << longestConsecutive(nums4) << endl; // 0 (edge case)

    vector<int> nums5 = {10};
    cout << "Test 5: " << longestConsecutive(nums5) << endl; // 1 (edge case)

    return 0;
}

int longestConsecutive(vector<int> &nums) {
    if(nums.empty()) return 0;
    
    // Insert all numbers into an unordered_set for O(1) lookups
    unordered_set<int> uset(nums.begin(), nums.end());
    int longest = 0;

    // Iterate through each unique number
    for (int num : uset) {
        // Only start counting if this number is the "start" of a sequence
        if (uset.find(num - 1) == uset.end()) {
            int temp = num;
            int len = 1;

            // Expand forward until the sequence breaks
            while (uset.find(temp + 1) != uset.end()) {
                temp++;
                len++;
            }

            // Update maximum length
            longest = max(longest, len);
        }
    }
    return longest;
}
