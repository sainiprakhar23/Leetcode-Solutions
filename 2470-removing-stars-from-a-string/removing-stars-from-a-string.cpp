class Solution {
public:
    string removeStars(string s) {
        // 2 pointer approach
        int n = s.length();
        int left = 0 ;

        for(int right = 0; right<n; right++){
            if(s[right] == '*'){
                left--;
                continue;
            }
            else{
                s[left] = s[right];
                left++;
            }
           
        }
        return s.substr(0,left);
    }
};