
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.length();
        vector<int> ans;
        if (words.empty()) return ans;

        int wordLen = words[0].length();
        int wordCount = words.size();

        int requiredLength = wordCount * wordLen;

        if (n < requiredLength) return ans;

        // Required frequency of every word
        unordered_map<string, int> required;
        for (auto x : words) {
            required[x]++;
        }

        // Try every possible starting index
        for (int i = 0; i <= n - requiredLength; i++) {

            string str = s.substr(i, requiredLength);

            unordered_map<string, int> mp;
            // Divide substring into equal-sized chunks
            for (int j = 0; j < requiredLength; j += wordLen) {
                string temp = str.substr(j, wordLen);
                mp[temp]++;
            }

            // Compare both frequency maps
            if (mp == required) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
