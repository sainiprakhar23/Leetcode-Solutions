class Solution {
public:
    // BRUTEFORCE
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    // OPTIMAL
    int expand(const string& s, int left ,int right){
        while(left>=0 && right <s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left -1; //-1 bcz left/right may go out of bound after the loop, so minus 1
    }

    string longestPalindrome(const string& s) {
        const int n = static_cast<int>(s.size());

        // BRUTEFORCE
        // if (n <= 1) {
        //     return s;
        // }
        // int bestStart = 0;
        // int bestLength = 1;
        // for (int left = 0; left < n; ++left) {
        //     for (int right = left; right < n; ++right) {

        //         const int currentLength = right - left + 1;
        //         // No need to check if it cannot beat the current answer.
        //         if (currentLength <= bestLength) {
        //             continue;
        //         }
        //         if (isPalindrome(s, left, right)) {
        //             bestStart = left;
        //             bestLength = currentLength;
        //         }
        //     }
        // }
        // return s.substr(bestStart, bestLength);
        int start  = 0;
        int end = 0;
        int maxLen=0;
        for(int i=0; i<n; i++){
            int odd = expand(s, i, i);  //return length of valid palindrone 
            int even = expand(s, i, i+1);
            
            int currentLen = max(odd,even);

            if(currentLen >= maxLen){
                maxLen = currentLen;
                // finding the strt, end index of palindrom, as "i" is the center
                start = i - (maxLen - 1)/2;
                end = i + maxLen/2;
            }
        }
        return s.substr(start,maxLen);
        //return s.substr(start,enD);
    }
};