class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int result = 0;
        int left = 0;
        for(int right=0; right<n; right++){
            char ch = s[right];
            mp[ch]++;

            while(mp[ch] > 1){
                char leftChar = s[left];
                mp[leftChar]--;
                left++;
            }
            result = max(result, right-left+1);
        }
        
        return result;
    }
};