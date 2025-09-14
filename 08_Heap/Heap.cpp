#include <iostream>
#include <vector>
using namespace std;

/*
 * Function: insertMaxheap
 * -----------------------
 * Inserts an element at index 'n' into a max heap.
 * It fixes the heap property by moving the element up (heapify-up).
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
void insertMaxheap(vector<int> &nums , int n) {
    int i = n;
    int temp = nums[i];
    // Move element up until parent is larger or root is reached
    while (i > 0 && temp > nums[(i - 1) / 2]) {
        nums[i] = nums[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    nums[i] = temp;
}

/*
 * Function: createMaxheap
 * -----------------------
 * Converts a given array into a max heap by repeatedly inserting elements.
 *
 * Time Complexity: O(n log n) using insertion method
 * Space Complexity: O(1)
 */
void createMaxheap(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        insertMaxheap(nums, i);
    }
}

/*
 * Function: insertMinheap
 * -----------------------
 * Inserts an element at index 'n' into a min heap.
 * It fixes the heap property by moving the element up (heapify-up).
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
void insertMinheap(vector<int> &nums , int n) {
    int i = n;
    int temp = nums[i];
    // Move element up until parent is smaller or root is reached
    while (i > 0 && temp < nums[(i - 1) / 2]) {
        nums[i] = nums[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    nums[i] = temp;
}

/*
 * Function: createMinheap
 * -----------------------
 * Converts a given array into a min heap by repeatedly inserting elements.
 *
 * Time Complexity: O(n log n) using insertion method
 * Space Complexity: O(1)
 */
void createMinheap(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        insertMinheap(nums, i);
    }
}

/*
 * Function: DeleteMax
 * ------------------
 * Deletes the maximum element from a max heap (root element).
 * Places the max element at the end (used for heap sort).
 *
 * Time Complexity: O(log n) - heapify down
 * Space Complexity: O(1)
 */
void DeleteMax(vector<int> &nums , int n) {
	int val = nums[0];         // Store max element
	nums[0] = nums[n-1];       // Move last element to root
	int i = 0;
	int heapSize = n - 1; 
	int largest = i;

	// Heapify-down to restore max heap property
	while(true) {
		int left = 2*i+1;
		int right = 2*i+2;
		largest = i;
		
		if(left < heapSize && nums[left] > nums[largest])
			largest = left;
		if(right < heapSize && nums[right] > nums[largest])
			largest = right;
		if(largest != i) {
			swap(nums[i],nums[largest]);
			i = largest;
		} else {
			break;
		}
	}

	nums[n-1]=val;   // Place max element at the end
}

/*
 * Function: HeapSort
 * -----------------
 * Sorts an array using heap sort algorithm.
 * Builds a max heap, then repeatedly deletes the max element and places it at the end.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1) - in-place
 */
void HeapSort(vector<int> &nums) {
	createMaxheap(nums);
	
	for(int i = nums.size(); i > 1 ; i--)
		DeleteMax(nums,i);
}

int main() {
    vector<int> nums;
    cout << "Enter the numbers  and press -1 to end" << endl;

    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        nums.push_back(x);
    }

    // Max heap
    createMaxheap(nums);
    cout << "Max Heap: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    // Min heap
    createMinheap(nums);
    cout << "Min Heap: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    // Heap sort
    HeapSort(nums);
    cout << "Sorted Array: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    return 0;
}
