class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> mp;
        for(int i=0; i<m; i++){
            mp[nums2[i]]=i;
        }

        vector<int> ans(n,-1);
        for(int i=n-1; i>=0; i--){
            int start = mp[nums1[i]];
            for(int j=start; j<m; j++){
                if(nums2[j] > nums1[i] ){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // Bruteforce - O(n2)
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