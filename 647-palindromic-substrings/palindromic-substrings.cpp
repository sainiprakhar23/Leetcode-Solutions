class Solution {
public:
    int isPalindrome(const string& s, int left , int right,int count){
        while(left >=0 && right<s.length() ){ //left <= right, bcz we are expanding, we dont need
            if(s[left] != s[right]){
                break;
            }
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.length();
        // BRUTEFORCE
        // int palindromeCount = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(isPalindrome(s,i,j)){
        //             palindromeCount++;
        //         }
        //     }
        // }
        // return palindromeCount;


        // OPTIMAL -> 2 POINTER , SAME LOGIC LIKE LC-5
        // OPTIMAL -> EXPAND AROUND CENTER
        int palindromeCount = 0;
        for(int i = 0; i < n; i++) {
            // ODD LENGTH PALINDROME
            int odd = isPalindrome(s, i, i, 0);
            // EVEN LENGTH PALINDROME
            int even = isPalindrome(s, i, i + 1, 0);

            palindromeCount += odd + even;
        }
        return palindromeCount;
    }
};