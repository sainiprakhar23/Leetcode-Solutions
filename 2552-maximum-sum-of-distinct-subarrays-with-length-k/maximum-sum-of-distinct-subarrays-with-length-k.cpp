class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        long long maxSum=0;
        long long currSum=0;
        int left=0;
        int right=0;
        while(right < n){
            // check if the nums[right] is present in set ,if present remove nums[left] one by one
            while(st.count(nums[right])){
                currSum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            // if not in set add it
            currSum+=nums[right];
            st.insert(nums[right]);

            if(right-left+1  == k){
                maxSum=max(maxSum,currSum);
                currSum-=nums[left];
                st.erase(nums[left]);
                left++;
            }
            right++;
        }
        return maxSum;
        
    }
};