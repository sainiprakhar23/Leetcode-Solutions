class Solution {
public:

    int kadanesMax(vector<int> nums, int n){
        int maxSum = nums[0];
        int result = nums[0];

        for(int i = 1; i < n; i++){
            maxSum = max(maxSum + nums[i], nums[i]);
            result = max(maxSum, result);
        }

        return result;
    }

    int kadanesMin(vector<int> nums, int n){
        int minSum = nums[0];
        int result = nums[0];

        for(int i = 1; i < n; i++){
            minSum = min(minSum + nums[i], nums[i]);
            result = min(minSum, result);
        }

        return result;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // 1. Total sum
        int Sum = accumulate(nums.begin(), nums.end(), 0);

        // 2. Minimum subarray
        int minBestSum = kadanesMin(nums, n);

        // 3. Maximum normal subarray
        int maxBestSum = kadanesMax(nums, n);

        // 4. Maximum circular subarray
        int circularSum = Sum - minBestSum;

        // All elements are negative
        if(maxBestSum <= 0)
            return maxBestSum;

        return max(maxBestSum, circularSum);
    }
};