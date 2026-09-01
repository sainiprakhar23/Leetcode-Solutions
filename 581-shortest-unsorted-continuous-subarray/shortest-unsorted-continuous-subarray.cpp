class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // int rightBoundary = -1;
        // int leftBoundary = -1;

        // int minSeen = INT_MAX;
        // int maxSeen = INT_MIN;

        // int left=0;
        // int right = nums.size()-1;

        // while(right >=0 ){
        //     minSeen = min(minSeen, nums[right]);

        //     if(nums[right] > minSeen){
        //         leftBoundary = right;
        //     }
        //     right--;
        // }
        // if(leftBoundary==-1) return 0;

        // while(left <=nums.size()-1 ){
        //     maxSeen=max(maxSeen,nums[left]);
        //     if(nums[left] < maxSeen){
        //         rightBoundary = left;
        //     }
        //     left++;
        // }
        
        // return rightBoundary-leftBoundary+1;


        /*IN SINGLE PASS*/
        int n=nums.size();
        int left=-1;
        int right=-1;

        int minSeen = nums[n-1];
        int maxSeen = nums[0];

        for(int i=1;i<n;i++){
            // pointer from left to right
            maxSeen = max(maxSeen,nums[i]);
            if(nums[i]<maxSeen) right=i;


            // Pointer moving from right → left
            int j = n-1-i;
            minSeen = min(minSeen,nums[j]);
            if(nums[j]>minSeen) left=j;
            
        }
        if(left==-1)return 0;
        return right-left+1;
    }
};