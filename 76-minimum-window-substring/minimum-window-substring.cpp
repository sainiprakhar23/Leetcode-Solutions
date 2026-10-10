
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int count = t.length();
        int left = 0;
        int minlen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            if (mp.count(ch)) {
                if (mp[ch] > 0) {
                    count--;
                }
                mp[ch]--;
            }

            while (count == 0) {
                int currentLen = right - left + 1;

                if (currentLen < minlen) {
                    minlen = currentLen;
                    start = left;
                }

                char leftChar = s[left];

                if (mp.count(leftChar)) {
                    if (mp[leftChar] >= 0) {
                        count++;
                    }
                    mp[leftChar]++;
                }

                left++;
            }
        }

        if (minlen == INT_MAX) {
            return "";
        }

        return s.substr(start, minlen);
    }
};