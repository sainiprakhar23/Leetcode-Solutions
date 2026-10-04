class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        //BRUTEFORCE
        // int maxProduct = INT_MIN;
        // for(int i=0; i<n ;i++){
        //     int product = 1;
        //     for(int j=i; j<n; j++){
        //         product *= nums[j];
        //         maxProduct = max(maxProduct,product);
        //     }
        // }
        // return maxProduct;

        // OPTIMAL-->Kadane's Algorithm
        int maxProduct = nums[0];
        int maxBestEnd = nums[0];
        int minBestEnd = nums[0];

        for(int i=1; i<n; i++){
            int choice1 = nums[i];
            int choice2 = maxBestEnd * nums[i];
            int choice3 = minBestEnd * nums[i];

            maxBestEnd = max(choice1, max(choice2,choice3));
            minBestEnd = min(choice1, min(choice2,choice3));

            maxProduct = max(maxProduct,maxBestEnd);
        }
        return maxProduct;
    }
};