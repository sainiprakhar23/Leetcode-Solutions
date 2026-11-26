class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        stack<int> st;
        vector<int> nge(m, -1);
        unordered_map<int, int> mp;

        // Step 1: Find NGE for every element in nums2 -> LEFT TO RIGHT
        for(int i = 0; i < m; i++) {
            int curr = nums2[i];

            while(!st.empty() && nums2[st.top()] < curr) {

                int idx = st.top();
                st.pop();

                nge[idx] = curr;
            }

            st.push(i);
        }

        // Step 2: Store element -> NGE mapping
        for(int i = 0; i < m; i++) {
            mp[nums2[i]] = nge[i];
        }

        // Step 3: Build answer for nums1
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

//         int n = nums1.size();
//         int m = nums2.size();

//         stack<int> st;
//         unordered_map<int,int> mp;

//         mp[nums2[m-1]] = -1;
//         st.push(nums2[m-1]);

//         for(int i = m-2; i >= 0; i--) {
//             while(!st.empty() && nums2[i] >= st.top()) {
//                 st.pop();
//             }
//             if(st.empty())
//                 mp[nums2[i]] = -1;
//             else
//                 mp[nums2[i]] = st.top();

//             st.push(nums2[i]);
//         }

//         vector<int> ans(n);
//         for(int i = 0; i < n; i++) {
//             ans[i] = mp[nums1[i]];
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // another buteforce ->T.C = )( m {for building hashmap} + n*m)
//         int n = nums1.size();
//         int m = nums2.size();

//         unordered_map<int,int> mp;
//         for(int i=0; i<m; i++){
//             mp[nums2[i]]=i;
//         }

//         vector<int> ans(n,-1);
//         for(int i=n-1; i>=0; i--){
//             int start = mp[nums1[i]];
//             for(int j=start; j<m; j++){
//                 if(nums2[j] > nums1[i] ){
//                     ans[i] = nums2[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // Bruteforce - O(n*m)
//         int n = nums1.size();
//         int m = nums2.size();

//         vector<int> temp(n);
//         vector<int> ans(n,-1);

//         for(int i=0; i<n; i++){
//             int number = nums1[i];
//             for(int j=0; j<m; j++){
//                 if(nums2[j] == number){
//                     temp[i]=j;
//                     break;
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             int number = nums1[i];
//             for(int j=temp[i]; j<m; j++){
//                 if(nums2[j] > number){
//                     ans[i]=nums2[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };