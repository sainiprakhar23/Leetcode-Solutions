class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int rightBoundary = -1;
        int leftBoundary = -1;

        int minSeen = INT_MAX;
        int maxSeen = INT_MIN;

        int left=0;
        int right = nums.size()-1;

        while(right >=0 ){
            minSeen = min(minSeen, nums[right]);

            if(nums[right] > minSeen){
                leftBoundary = right;
            }
            right--;
        }
        if(leftBoundary==-1) return 0;

        while(left <=nums.size()-1 ){
            maxSeen=max(maxSeen,nums[left]);
            if(nums[left] < maxSeen){
                rightBoundary = left;
            }
            left++;
        }
        
        return rightBoundary-leftBoundary+1;
    }
};