class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount=0;
        int currentCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currentCount++;
            }
            else{
                //nums[i]==0, find max_Count and then reset the current count
                maxCount = max(maxCount,currentCount);
                currentCount=0;
            }
        }
        return max(maxCount,currentCount);
        
    }
};