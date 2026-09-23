class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // BRUTEFORCE
        // int minlen = INT_MAX;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum >= target){
        //             minlen = min(minlen,j-i+1);
        //             break;
        //         }
        //     }
        // }
        // return minlen==INT_MAX ? 0 : minlen;

        // OPTIMAL
        int minlen=INT_MAX;
        int left=0;
        int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                minlen = min(minlen,right-left+1);
                sum-= nums[left];
                left++;
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
        
    }
};