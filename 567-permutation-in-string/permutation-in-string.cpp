class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        // BRUTEFORCE
        vector<int> str1(26,0);
        for(char ch : s1){
            str1[ch - 'a']++;
        }
        for(int i=0; i<=m-n; i++){
             vector<int> str2(26,0);
            for(int j=i; j<i+n; j++){
                char  ch = s2[j];
                str2[ch - 'a']++;

                if(str1 == str2) return true;
            }
        }
        return false;
    }
};