// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/
//
// Approach:
//   1. Count the frequency of every word with an unordered_map.
//   2. Move (word, freq) pairs into a vector and sort it with a custom
//      comparator: higher frequency first; on ties, lexicographically
//      smaller word first.
//   3. Take the first k words.
//
// Complexity: O(n log n + k) time, O(n) space.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for (auto &s : words) m[s]++;

        vector<pair<string,int>> v;
        v.reserve(m.size());
        for (auto &it : m) v.push_back({it.first, it.second});

        sort(v.begin(), v.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        vector<string> ans;
        ans.reserve(k);
        for (int i = 0; i < k; i++) ans.push_back(v[i].first);
        return ans;
    }
};
