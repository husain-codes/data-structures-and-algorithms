#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/* Function to compute the number of days until a warmer temperature
* Time Complexity: O(n) 
*    - Each index is pushed and popped from the stack at most once.
* Space Complexity: O(n)
*    - For the output vector and stack in the worst case.
*/
vector<int> dailyTemperatures(vector<int>& temperatures);

// Function to print vector
void printVector(const vector<int>& v);

int main() {
    // Test case 1: Mixed temperatures (example case)
    vector<int> t1 = {73,74,75,71,69,72,76,73};
    cout << "Case 1: ";
    printVector(dailyTemperatures(t1));  // Expected: 1 1 4 2 1 1 0 0

    // Test case 2: Empty input
    vector<int> t2 = {};
    cout << "Case 2: ";
    printVector(dailyTemperatures(t2));  // Expected: (empty line)

    // Test case 3: Single element
    vector<int> t3 = {80};
    cout << "Case 3: ";
    printVector(dailyTemperatures(t3));  // Expected: 0

    // Test case 4: All decreasing temperatures
    vector<int> t4 = {90, 80, 70, 60};
    cout << "Case 4: ";
    printVector(dailyTemperatures(t4));  // Expected: 0 0 0 0

    // Test case 5: All increasing temperatures
    vector<int> t5 = {60, 70, 80, 90};
    cout << "Case 5: ";
    printVector(dailyTemperatures(t5));  // Expected: 1 1 1 0
    return 0;
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    
    // Edge cases
    if (size == 0) return {};         // no input
    if (size == 1) return {0};        // only one day, no warmer day
    
    vector<int> answer(size, 0);
    stack<int> s; // stack to store indices
    
    for (int i = 0; i < size; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return answer;
}
void printVector(const vector<int>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}