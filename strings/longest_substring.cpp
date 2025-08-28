#include <iostream>
#include <string>
#include <algorithm> // for std::fill, std::max

/**
 * Function: longest_substring
 * ---------------------------
 * Finds the length of the longest substring without repeating characters.
 *
 * Approach:
 * - Use the Sliding Window + Two Pointers technique.
 * - Maintain an array `store_index` that stores the last index of every character (ASCII 0–255).
 * - If a character repeats within the current window, move the left pointer `i`
 *   to the right of the last occurrence of that character.
 * - Update the maximum window length (`length`) as we go.
 *
 * Time Complexity:  O(n)   (each character is processed once)
 * Space Complexity: O(1)   (constant size array of 256 for ASCII characters)
 *
 * @param s: Input string
 * @return Length of the longest substring without repeating characters
 */
int longest_substring(std::string s)
{
    int size = s.length();
    if (size == 0)  // Edge case: empty string
        return 0;
    if (size == 1)  // Edge case: single character
        return 1;

    int i = 0, length = 0;              // i = left pointer of sliding window
    int store_index[256];               // Stores last seen index of each character
    std::fill(store_index, store_index + 256, -1); // Initialize to -1 (not seen)

    for (int j = 0; j < size; j++)      // j = right pointer of sliding window
    {
        // If the character was seen before and is inside the current window
        if (store_index[(unsigned char)s[j]] >= i)
            i = store_index[(unsigned char)s[j]] + 1; // Move left pointer ahead

        // Update the longest length found so far
        length = std::max(length, j - i + 1);

        // Store the last index of the current character
        store_index[(unsigned char)s[j]] = j;
    }

    return length;
}

int main()
{
    // 🔹 Test Cases for Validation
    std::cout << "Test Case 1: \"abcabcbb\"  -> " << longest_substring("abcabcbb") << " (Expected: 3)" << std::endl;
    std::cout << "Test Case 2: \"bbbbb\"     -> " << longest_substring("bbbbb")    << " (Expected: 1)" << std::endl;
    std::cout << "Test Case 3: \"pwwkew\"    -> " << longest_substring("pwwkew")   << " (Expected: 3)" << std::endl;
    std::cout << "Test Case 4: \"\" (empty)  -> " << longest_substring("")         << " (Expected: 0)" << std::endl;
    std::cout << "Test Case 5: \"a\"         -> " << longest_substring("a")        << " (Expected: 1)" << std::endl;
    std::cout << "Test Case 6: \"abcdef\"    -> " << longest_substring("abcdef")   << " (Expected: 6)" << std::endl;
    std::cout << "Test Case 7: \"abba\"      -> " << longest_substring("abba")     << " (Expected: 2)" << std::endl;

    return 0;
}

