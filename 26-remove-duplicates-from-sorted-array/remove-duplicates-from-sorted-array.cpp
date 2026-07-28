class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = 1;
        while(high<nums.size()){
            if(nums[high] != nums[low]){
                low++;
                nums[low]=nums[high];
            }
            high++;
        }
        return low+1;
    }
};