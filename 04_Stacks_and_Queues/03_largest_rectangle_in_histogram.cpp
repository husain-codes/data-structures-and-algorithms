#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

/**
 * Time Complexity: O(n)
 * Each bar is pushed and popped at most once.
 * Space Complexity: O(n) for the stack.
 */
int largestRectangleArea(vector<int>& heights);

int main() {
    vector<vector<int>> testCases = {
        {},                 // empty
        {5},                // single bar
        {2,2,2,2},          // all same
        {1,2,3,4,5},        // increasing
        {5,4,3,2,1},        // decreasing
        {10000,10000},      // large values
        {0,0,0},            // all zeros
        {2,1,5,6,2,3}       // example
    };

    for (auto &heights : testCases) {
        cout << "Heights: ";
        for (int h : heights) cout << h << " ";
        cout << " => Max Area = " << largestRectangleArea(heights) << endl;
    }
    return 0;
}

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // sentinel
    int area = 0;
    stack<int> st;
    
    for (int i = 0; i < heights.size(); i++) {
        while(!st.empty() && heights[i] < heights[st.top()]) {
            int index = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            area = max(area, heights[index] * width);
        }
        st.push(i);
    }
    return area;
}
