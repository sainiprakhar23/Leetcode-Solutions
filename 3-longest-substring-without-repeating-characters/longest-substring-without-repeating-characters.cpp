class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int left=0;
        //if(s=="") return 0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= left){
                left = mp[s[i]]+1;
            }
            len=max(len,i-left +1); 
            mp[s[i]]=i;
        }
        return len;
    }

    
};