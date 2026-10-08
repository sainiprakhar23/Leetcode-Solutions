class Solution {
public:
    // BRUTEFORCE
    // vector<int> findAnagrams(string s, string p) {
    //     // BRUTEFORCE
    //     vector<int> result;
    //     // Frequency of p
    //     vector<int> mainString(26, 0);
    //     for(auto ch : p){
    //         mainString[ch - 'a']++;
    //     }
    //     int len = p.length();
    //     // Try every starting position
    //     for(int i = 0; i <= s.length() - len; i++){
    //         vector<int> temp(26, 0);
    //         // Build frequency of current substring
    //         for(int j = i; j < i + len; j++){
    //             temp[s[j] - 'a']++;
    //         }
    //         // If frequencies are same -> anagram
    //         if(mainString == temp){
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }

    // OPTIMAL WITH 2HASHMAP
    // vector<int> findAnagrams(string s, string p){

    // }

    // OPTIMAL WITH ONS HASHMAP
    vector<int> findAnagrams(string s, string p){
        vector<int> result;
        unordered_map<char,int> mp;
        for(char ch : p){
            mp[ch]++;
        }
        int left = 0,count=p.length();
        for(int right=0; right<s.length(); right++){
            char ch = s[right];
            int freq = mp[ch];

            if(freq > 0 ) count--;
            mp[ch] = freq -1;

            // remove left that is out of window size
            if(right-left+1 > p.length()){
                char leftChar = s[left];  //pich out the left chaarcter
                int leftCharFreq = mp[leftChar];

                if(leftCharFreq >=0 ){
                    // we need that character, so count incres,
                    //if it is -ve, then it is in abundace we dont need
                    count++;
                }
                // find lefChar in map and incdres the count,
                // bcz on arrive  we decrse it,  undo opereatio of right
                mp[leftChar] = leftCharFreq + 1; 
                left++;
            }
            if(count==0){
                result.push_back(left);
            }
        }
        return result;
    }
};