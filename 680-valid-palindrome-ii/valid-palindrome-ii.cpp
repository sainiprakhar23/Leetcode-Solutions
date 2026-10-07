class Solution {
public:
    bool palindroneCheck(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();

        int left = 0;
        int right = n -1;

        while(left < right){
            if(s[left] != s[right]){
                return  palindroneCheck(s,left + 1, right) ||  palindroneCheck(s,left, right-1); //ere we either del left and then check, or del right and then check
            }
            left++;
            right--;
        }
        return true;
    }
};