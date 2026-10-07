class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSubSum = nums[0];
        int minSubSum = nums[0];
        int maxAbsoluteSum = max( abs(maxSubSum),abs(minSubSum) );

        for(int i = 1; i < n; i++){
            maxSubSum = max(maxSubSum + nums[i], nums[i]);
            minSubSum = min(minSubSum + nums[i], nums[i]);

            maxAbsoluteSum = max( maxAbsoluteSum , max(abs(maxSubSum),abs(minSubSum)) );
        }
        
        return maxAbsoluteSum;
    }
};