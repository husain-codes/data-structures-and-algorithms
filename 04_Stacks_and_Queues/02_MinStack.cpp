#include <iostream>
#include <vector>
#include <algorithm>  // for std::min

using namespace std;

/**
 * MinStack supports:
 * - push(x): O(1)
 * - pop(): O(1)
 * - top(): O(1)
 * - getMin(): O(1)
 * 
 * We maintain a second stack (minimum) that tracks the minimum value
 * at each level of the stack.
 */
class MinStack {
    vector<int> stack;     // stores values
    vector<int> minimum;   // stores current min at each level
public:
    MinStack() {}

    void push(int val) {
        stack.push_back(val);
        if (minimum.empty())
            minimum.push_back(val);
        else
            minimum.push_back(std::min(val, minimum.back()));
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
            minimum.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minimum.back();
    }
};

int main() {
    MinStack st;

    st.push(3);
    st.push(5);
    cout << "Top: " << st.top() << ", Min: " << st.getMin() << endl;  // Top=5, Min=3

    st.push(2);
    st.push(1);
    cout << "Top: " << st.top() << ", Min: " << st.getMin() << endl;  // Top=1, Min=1

    st.pop();
    cout << "Top: " << st.top() << ", Min: " << st.getMin() << endl;  // Top=2, Min=2

    st.pop();
    cout << "Top: " << st.top() << ", Min: " << st.getMin() << endl;  // Top=5, Min=3

    return 0;
}
