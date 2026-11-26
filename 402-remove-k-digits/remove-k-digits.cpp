class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        // Edge case
        if(k >= n) return "0";

        stack<char> st;
        string result = "";

        // STEP 1: Greedy removal
        for(int i = 0; i < n; i++){

            while(!st.empty() &&
                  st.top() > num[i] &&
                  k > 0){

                st.pop();
                k--;
            }

            // Push every digit
            st.push(num[i]);
        }

        // STEP 2: Remove remaining digits from the end
        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        // STEP 3: Construct result
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        // STEP 4: Remove leading zeros
        int i = 0;

        while(i < result.size() && result[i] == '0'){
            i++;
        }

        result = result.substr(i);

        // STEP 5: Handle empty result
        if(result.empty()) return "0";

        return result;
    }
};


// class Solution {
// public:
//          <<<IRERATIVE BRUTEFORCE
//     string ans = "";
//     void generate(string& num, int idx, int k, string curr) {
//         int n = num.size();
//         // We have selected all required digits
//         if (curr.size() == n - k) {
//             // Remove leading zeros
//             int pos = 0;
//             while (pos < curr.size() && curr[pos] == '0') {
//                 pos++;
//             }
//             curr = curr.substr(pos);
//             if (curr.empty()) {
//                 curr = "0";
//             }
//             // Update minimum answer
//             if (ans == "" || curr.size() < ans.size() ||
//                 (curr.size() == ans.size() && curr < ans)) {
//                 ans = curr;
//             }
//             return;
//         }
//         // Not enough remaining digits to complete the selection
//         if (n - idx < n - k - curr.size()) {
//             return;
//         }
//         // Iteratively generate combinations using a loop
//         for (int i = idx; i < n; i++) {
//             generate(num, i + 1, k, curr + num[i]);
//         }
//     }
//     string removeKdigits(string num, int k) {
//         int n = num.size();
//         if (k >= n) return "0";
//         ans = "";
//         generate(num, 0, k, "");
//         return ans;
//     }
// };


// // class Solution {
// public:
//     // BRUTEFORCE
//     string ans = "";
//     void solve(string& num, int k, int idx, string curr) {
//         // BASE CASE: All digits have been processed
//         if (idx == num.size()) {
//             // Accept only if exactly k digits were removed
//             if (k == 0) {
//                 // Step 1: Remove leading zeros from curr
//                 int position = 0;
//                 while (position < curr.length() &&
//                        curr[position] == '0') {
//                     position++;
//                 }
//                 curr = curr.substr(position);
//                 // Step 2: If curr becomes empty, answer is "0"
//                 if (curr.empty()) {
//                     curr = "0";
//                 }
//                 // Step 3: Compare this valid candidate with ans
//                 // A shorter string represents a smaller number.
//                 // If lengths are equal, lexicographical comparison works.
//                 if (ans == "" ||
//                     curr.size() < ans.size() ||
//                     (curr.size() == ans.size() && curr < ans)) {

//                     ans = curr;
//                 }
//             }
//             // Stop this recursive branch
//             return;
//         }
//         // CHOICE 1: REMOVE the current digit
//         // We can remove only if k > 0.
//         // idx increases, k decreases, curr remains unchanged.
//         if (k > 0) {
//             solve(num, k - 1, idx + 1, curr);
//         }
//         // CHOICE 2: KEEP the current digit
//         // idx increases, k remains unchanged,
//         // and the current digit is appended to curr.
//         solve(num, k, idx + 1, curr + num[idx]);
//     }

//     string removeKdigits(string num, int k) {
//         int n = num.size();
//         // If we must remove all digits or more, result is zero.
//         if (k >= n) {
//             return "0";
//         }
//         // Reset answer before starting recursion
//         ans = "";
//         // Start from index 0, with k removals remaining
//         // and an initially empty candidate string.
//         solve(num, k, 0, "");
//         return ans;
//     }
// };
