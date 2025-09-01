#include <iostream>
#include <vector>

using namespace std;

/*
========================================================
Explanation:
This is a brute force solution to the "Sliding Window Maximum" problem.
For every window of size k, it scans all k elements to find the maximum.
=========================================================
Time Complexity:
Outer loop: (n-k+1) iterations (for each window)
Inner loop: k iterations (to find max in each window)
=> O((n-k+1) * k) ≈ O(n*k)

Space Complexity:
O(n-k+1) for the result vector (output)
O(1) extra space (no additional data structures)
*/

class MaxSlidingWindowBrute {
	public:
	// Function to calculate the maximum element for every sliding window of size k
	// Brute force approach: For each window, scan all k elements and take the maximum
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		vector<int> result;
		
		// Iterate through all possible windows of size k
		// i = starting index of the window
		for (int i = 0; i < (nums.size() - k + 1); i++) {
		    // Find the maximum element in the current window [i .. i+k-1]
		    int max = maxElement(nums,i,i+k-1);
			result.push_back(max);
		}
		return result;
	};
	
	// Helper function to get the maximum element in subarray nums[left..right]
	int maxElement (vector<int> &nums , int left, int right) {
			int maxElement = nums[left];
			
			// Linear scan from left to right
			for (int i = left; i <= right; i++) {   
				if(maxElement < nums[i])
					maxElement = nums[i];
			}
			return maxElement;
	};
};

int main() {
	// Example input
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	
	MaxSlidingWindowBrute maxSlidingWindowBrute;
	vector<int> result = maxSlidingWindowBrute.maxSlidingWindow(nums,3);
	
	// Print the result
	for (auto i : result)
		cout << i << " ";
	
	return 0;
}
