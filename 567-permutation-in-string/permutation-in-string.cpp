class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        // BRUTEFORCE
        // vector<int> str1(26,0);
        // for(char ch : s1){
        //     str1[ch - 'a']++;
        // }
        // for(int i=0; i<=m-n; i++){
        //      vector<int> str2(26,0);
        //     for(int j=i; j<i+n; j++){
        //         char  ch = s2[j];
        //         str2[ch - 'a']++;

        //         if(str1 == str2) return true;
        //     }
        // }
        // return false;

        // OPTIMAL  -> SLIDING WINDOW + VECTOR
        // vector<int> str1(26,0);
        //         vector<int> str2(26,0);
        // for(char ch : s1){
        //     str1[ch - 'a']++;
        // }

        // for(int right=0; right < s2.length(); right++){
        //     char ch = s2[right];
        //     str2[ch - 'a']++;

        //     if(right >= s1.length()){
        //         char leftChar = s2 [right  - s1.length()];
        //         str2[leftChar - 'a']--;
        //     }

        //     if(str1==str2) return true;
        // }
        // return false;


        // OPTMAL-> SLIDING WINDOW + HASHMAP
        unordered_map<char, int> mp;
        for(char ch : s1){
            mp[ch]++;
        }
        int count = s1.length();
        int left = 0;
        for(int right=0; right<s2.length(); right++){
            char ch = s2[right];
            int freq = mp[ch]; //if not tere in map it will create it with freq=0

            if(freq > 0) count--;
            mp[ch] = freq - 1;

            if(right - left + 1 > s1.length()){
                char leftChar = s2[left];
                if(mp[leftChar] >= 0 )count++; //
                mp[leftChar]++; //when leaving incfese the freq
                left++;
            }
            
            if(count==0) return true;
        }
        return false;
    }
};