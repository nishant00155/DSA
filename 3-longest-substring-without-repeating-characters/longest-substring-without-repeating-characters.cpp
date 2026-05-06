class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int a = 0;              // left pointer
        int maxlength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = a; j < i; j++) {
                if (s[i] == s[j]) {
                    a = j + 1;  // slide left pointer past duplicate
                    break;
                }
            }
            int length = i - a + 1;   // current window size
            maxlength = max(maxlength, length);
        }
        return maxlength;
    }
};
