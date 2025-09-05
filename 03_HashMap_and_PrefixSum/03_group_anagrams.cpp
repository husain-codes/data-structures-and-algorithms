#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
========================================================
Function: groupAnagrams
--------------------------------------------------------
Approach:
- For each word, compute a "frequency signature" (26-length key)
- Use this as the map key, and group words with the same key
- Return all grouped anagrams as a 2D vector

Complexity:
- Building frequency array: O(L) per word, where L = word length
- Doing this for N words: O(N * L)
- Inserting/finding in unordered_map: O(1) average
- Total Time Complexity: O(N * L)
- Space Complexity: O(N * L) for storing all words in groups + keys
========================================================
*/
vector<vector<string>> groupAnagrams(vector<string>& strs);

int main() {
    // Test Case 1: Regular input
    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> grp1 = groupAnagrams(strs1);
    cout << "Test 1 (normal case):" << endl;
    for (auto &group : grp1) {
        cout << "[ ";
        for (auto &word : group)
            cout << word << " ";
        cout << "]" << endl;
    }
    cout << endl;

    // Test Case 2: Empty input
    vector<string> strs2 = {};
    vector<vector<string>> grp2 = groupAnagrams(strs2);
    cout << "Test 2 (empty input):" << endl;
    if (grp2.empty()) cout << "[]" << endl;
    cout << endl;

    // Test Case 3: Single word
    vector<string> strs3 = {"abc"};
    vector<vector<string>> grp3 = groupAnagrams(strs3);
    cout << "Test 3 (single word):" << endl;
    for (auto &group : grp3) {
        cout << "[ ";
        for (auto &word : group)
            cout << word << " ";
        cout << "]" << endl;
    }
    cout << endl;

    // Test Case 4: All identical words
    vector<string> strs4 = {"aaa","aaa","aaa"};
    vector<vector<string>> grp4 = groupAnagrams(strs4);
    cout << "Test 4 (all identical words):" << endl;
    for (auto &group : grp4) {
        cout << "[ ";
        for (auto &word : group)
            cout << word << " ";
        cout << "]" << endl;
    }
    cout << endl;

    // Test Case 5: No anagrams at all
    vector<string> strs5 = {"abc","def","ghi"};
    vector<vector<string>> grp5 = groupAnagrams(strs5);
    cout << "Test 5 (no anagrams):" << endl;
    for (auto &group : grp5) {
        cout << "[ ";
        for (auto &word : group)
            cout << word << " ";
        cout << "]" << endl;
    }
    cout << endl;

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> groupAnagrams;
    unordered_map<string,vector<string>> map;

    for (string &word: strs) {
        vector<int> freq(26,0);
        string key;

        for (char c : word)
            freq[c - 'a']++;

        for (int f : freq)
            key += to_string(f) + "#"; // create unique key

        map[key].push_back(word);
    }

    for (auto &entry : map)
        groupAnagrams.push_back(entry.second);

    return groupAnagrams;
}
