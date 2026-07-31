class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = 1;
        int count = 1;
        while(high<nums.size()){
            if(nums[high]==nums[low] && count<2){
                low++;
                nums[low]=nums[high];
                count++;
            }
            else if(nums[high] != nums[low]){
                count=0;
                low++;
                nums[low]=nums[high];
                count++;
            }
            high++;
        }
        return low+1;

    }
};