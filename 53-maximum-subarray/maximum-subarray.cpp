class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        //BRUTEFORCE -> 0(n2)
        // int maxSum = INT_MIN;
        // for(int i=0; i<n; i++){
        //     int sum=0;
        //     for(int j=i; j<n; j++){
        //         sum+=nums[j];
        //         maxSum = max(maxSum,sum);
        //     }
        // }
        // return maxSum;


        // OPTIMAL->Kadane's Algorithm
        int maxSum = INT_MIN;
        int bestend = nums[0];
        maxSum = nums[0];

        // for(int i=1; i<n; i++){
        //     int choice1 = bestend + nums[i];
        //     int choice2 = nums[i];

        //     bestend = max(choice1,choice2);
        //     maxSum = max(maxSum,bestend);
        // }

        // return maxSum;


        // another implementation
        int currentSum=0;
        int result = INT_MIN;
        for(int i=0; i<n;i ++){
            currentSum += nums[i];
            result = max(result,currentSum);
            if(currentSum < 0) currentSum=0; //start again

            
        }
        return result;
    }
};