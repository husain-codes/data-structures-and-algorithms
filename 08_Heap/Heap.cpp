#include <iostream>
#include <vector>
using namespace std;

void insertMaxheap(vector<int> &nums , int n) {
    int i = n;
    int temp = nums[i];
    while (i > 0 && temp > nums[(i - 1) / 2]) {
        nums[i] = nums[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    nums[i] = temp;
}

void createMaxheap(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        insertMaxheap(nums, i);
    }
}

void insertMinheap(vector<int> &nums , int n) {
    int i = n;
    int temp = nums[i];
    while (i > 0 && temp < nums[(i - 1) / 2]) {
        nums[i] = nums[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    nums[i] = temp;
}

void createMinheap(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        insertMinheap(nums, i);
    }
}

void DeleteMax(vector<int> &nums , int n) {
	int val = nums[0];
	nums[0] = nums[n-1];
	int i = 0;
	int heapSize = n - 1; 
	int largest = i;
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
	nums[n-1]=val;
}

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