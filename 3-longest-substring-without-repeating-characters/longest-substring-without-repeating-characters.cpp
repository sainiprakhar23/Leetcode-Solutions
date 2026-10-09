class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        // OPTIMAL -> HASHMAP(CHAR : FREQ)
        // unordered_map<char,int> mp;
        // int result = 0;
        // int left = 0;
        // for(int right=0; right<n; right++){
        //     char ch = s[right];
        //     mp[ch]++;

        //     while(mp[ch] > 1){
        //         char leftChar = s[left];
        //         mp[leftChar]--;
        //         left++;
        //     }
        //     result = max(result, right-left+1);
        // }
        // return result;


        // OPTIMAL -> HASHMAP(CHAR : INDEX) TO REMOVE WHILE LOOP
        unordered_map<int,int> mp;
        int result= 0;
        int left = 0;
        for(int right=0; right<n; right++){
            char ch = s[right];
            if(mp.count(ch)){
                left = max(left, mp[ch]+1); //updates left to make a vild winfow
            }
            mp[ch] = right; //update the postion with new index found
            result = max(result, right-left+1);
        }
        return result;

    }
};