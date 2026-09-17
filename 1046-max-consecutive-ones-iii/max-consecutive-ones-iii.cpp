class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n  = nums.size();

        // BRUTEFORCE
        // int count=0;
        // int zeroCount=0;
        // for(int i=0;i<n;i++){
        //     zeroCount=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0) zeroCount++;
        //         if(zeroCount > k){
        //             break;
        //         }
        //         count = max(count, j-i+1);
        //     }
 
        // }
        // return count;

        //OPTIMISED THEN BRUTEFORCE LESS THAN O(n2)
        // int max_Ans=0;
        // int zeroCount=0;
        // int left=0;
        // for(int right=0;right<n;right++){
        //     if(nums[right]==0) zeroCount++;

        //     while(zeroCount > k){
        //         if(nums[left]==0) zeroCount--;
        //         left++;
        //     }
        //     max_Ans=max(max_Ans,right-left+1);
        // }
        // return max_Ans;


        //OPTIMISED  O(n)
        int max_Ans=0;
        int zeroCount=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0) zeroCount++;

            if(zeroCount > k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
        }
        //now left is is the best location till right is moves out of last indx
        return n - left;
    }
};