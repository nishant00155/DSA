class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;

        int have = 0, needCount = need.size();
        int resLen = INT_MAX, resStart = 0;

        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            // shrink from left while valid
            while (have == needCount) {
                if (j - i + 1 < resLen) {
                    resLen = j - i + 1;
                    resStart = i;
                }
                window[s[i]]--;
                if (need.count(s[i]) && window[s[i]] < need[s[i]]) {
                    have--;
                }
                i++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
