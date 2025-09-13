#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Function: topKFrequent
 * -----------------------
 * Returns the k most frequent elements in the given array.
 *
 * Approach:
 *  1. Count frequency of each number using an unordered_map (O(n)).
 *  2. Use a min-heap (priority_queue with greater comparator) to keep track 
 *     of the top k frequent elements. Heap stores pairs {frequency, element}.
 *     - Push every element into heap
 *     - If heap size exceeds k → pop the smallest frequency
 *     This ensures heap contains only the top k frequent elements.
 *  3. Extract elements from the heap and return them.
 *
 * Time Complexity:
 *  - Building frequency map: O(n)
 *  - Pushing into heap: O(m log k), where m = number of unique elements
 *  - Extracting from heap: O(k log k)
 *  - Overall: O(n + m log k)
 *
 * Space Complexity:
 *  - Frequency map: O(m)
 *  - Heap: O(k)
 *  - Output: O(k)
 *
 * Edge Cases:
 *  - nums is empty → return empty vector
 *  - k == 0 → return empty vector
 *  - k >= number of unique elements → return all unique elements
 */
vector<int> topKFrequent(vector<int> &nums, int k) {
    if (nums.empty() || k == 0) return {};

    // Step 1: Count frequency
    unordered_map<int,int> freq;
    for (auto num : nums)
        freq[num]++;

    // Step 2: Min-heap based on frequency
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

    for (auto &it : freq) {
        heap.push({it.second, it.first});
        if (heap.size() > k) {
            heap.pop(); // remove least frequent
        }
    }

    // Step 3: Extract elements from heap
    vector<int> output;
    while (!heap.empty()) {
        output.push_back(heap.top().second);
        heap.pop();
    }

    // Optional: most frequent first
    reverse(output.begin(), output.end());

    return output;
}

int main() {
    // ✅ Test Case 1: Normal case
    vector<int> nums1 = {1,2,1,2,1,1,3,1,4,5};
    vector<int> out1 = topKFrequent(nums1, 2);
    cout << "Test 1 (Expected top 2 = [1,2]): ";
    for (auto i : out1) cout << i << " ";
    cout << endl;

    // ✅ Test Case 2: Multiple same frequencies
    vector<int> nums2 = {4,4,6,6,7,7};
    vector<int> out2 = topKFrequent(nums2, 2);
    cout << "Test 2 (Expected top 2 = [4,6] or [6,7] etc.): ";
    for (auto i : out2) cout << i << " ";
    cout << endl;

    // ✅ Test Case 3: Single element repeated
    vector<int> nums3 = {10,10,10,10};
    vector<int> out3 = topKFrequent(nums3, 1);
    cout << "Test 3 (Expected top 1 = [10]): ";
    for (auto i : out3) cout << i << " ";
    cout << endl;

    // ✅ Test Case 4: k = number of unique elements
    vector<int> nums4 = {1,2,3,4,5};
    vector<int> out4 = topKFrequent(nums4, 5);
    cout << "Test 4 (Expected all elements): ";
    for (auto i : out4) cout << i << " ";
    cout << endl;

    // ✅ Test Case 5: Empty array
    vector<int> nums5 = {};
    vector<int> out5 = topKFrequent(nums5, 2);
    cout << "Test 5 (Expected empty): ";
    for (auto i : out5) cout << i << " ";
    cout << endl;

    // ✅ Test Case 6: k = 0
    vector<int> nums6 = {1,1,2,2,3};
    vector<int> out6 = topKFrequent(nums6, 0);
    cout << "Test 6 (Expected empty): ";
    for (auto i : out6) cout << i << " ";
    cout << endl;

    return 0;
}
