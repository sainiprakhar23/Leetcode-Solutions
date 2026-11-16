
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    // BRUTEFORCE
    //     int n = s.length();
    //     vector<int> ans;
    //     if (words.empty()) return ans;

    //     int wordLen = words[0].length();
    //     int wordCount = words.size();

    //     int requiredLength = wordCount * wordLen;

    //     if (n < requiredLength) return ans;

    //     // Required frequency of every word
    //     unordered_map<string, int> required;
    //     for (auto x : words) {
    //         required[x]++;
    //     }

    //     // Try every possible starting index
    //     for (int i = 0; i <= n - requiredLength; i++) {

    //         string str = s.substr(i, requiredLength);

    //         unordered_map<string, int> mp;

    //         // Divide substring into equal-sized chunks
    //         for (int j = 0; j < requiredLength; j += wordLen) {
    //             string temp = str.substr(j, wordLen);
    //             mp[temp]++;
    //         }

    //         // Compare both frequency maps
    //         if (mp == required) {
    //             ans.push_back(i);
    //         }
    //     }

    //     return ans;
    // }


        vector<int> ans;

        if (words.empty()) return ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();

        int totalLen = wordLen * wordCount;

        if (n < totalLen) return ans;

        // STEP 1: Store required word frequencies
        unordered_map<string, int> required;
        for (auto &word : words) {
            required[word]++;
        }

        // STEP 2: Try every possible alignment
        for (int offset = 0; offset < wordLen; offset++) {

            // Initialize a new sliding window
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            // STEP 3: Move right in word-sized chunks
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                // Extract current word
                string word = s.substr(right, wordLen);
                // CASE 1: Word is not present in required
                if (required.find(word) == required.end()) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                // CASE 2: Add current word
                window[word]++;
                count++;
                // CASE 3: Remove excess occurrences
                while (window[word] > required[word]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }
                // CASE 4: All required words are matched
                if (count == wordCount) {
                    ans.push_back(left);
                    // Remove leftmost word to continue searching
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }
        return ans;
    }
};
