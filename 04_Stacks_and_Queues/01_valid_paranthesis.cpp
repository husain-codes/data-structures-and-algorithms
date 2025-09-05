#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
    Function: isValid
    Problem: Valid Parentheses
    -----------------------------------------
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    A string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.

    Approach:
    - Use a stack to keep track of opening brackets.
    - Push every opening bracket onto the stack.
    - For every closing bracket:
        * If stack is empty → invalid (no matching opening).
        * Check if the top of the stack matches the closing bracket.
          - If yes → pop from stack.
          - If not → invalid immediately.
    - At the end, stack must be empty for the string to be valid.

    Time Complexity: O(n)
        - Each character is pushed and popped at most once.
    Space Complexity: O(n)
        - Stack may store up to n opening brackets.

*/

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        // Push opening brackets
        if (c == '(' || c == '[' || c == '{')
            st.push(c);

        // For closing brackets
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty())  return false; // nothing to match with

            if ((c == ')' && st.top() == '(') ||
                (c == '}' && st.top() == '{') ||
                (c == ']' && st.top() == '[')) {
                st.pop(); // matched
            } else {
                return false; // mismatch
            }
        }
    }

    // String is valid only if no unmatched openings remain
    return st.empty();
}

int main() {
    vector<string> testCases = {
        "()",        // valid
        "()[]{}",    // valid
        "(]",        // invalid
        "([)]",      // invalid
        "{[]}",      // valid
        "",          // valid (edge case: empty string)
        "(",         // invalid
        "]"          // invalid
    };

    for (auto &tc : testCases) {
        cout << "Input: " << tc << " -> " 
             << (isValid(tc) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
