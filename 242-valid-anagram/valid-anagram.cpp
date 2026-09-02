class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for(int j=0;j<t.length();j++){
            char ch = t[j];
            if(mp.find(ch) != mp.end()){
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            
        }
        if(mp.size()>0) return false;
        return true;
    }
};