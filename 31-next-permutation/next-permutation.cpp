class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                pivot = i-1;
                break;
            }
        }
        if(pivot != -1){
            int swapIndex = pivot;
            for(int j=n-1;j>0;j--){
                 if(nums[j] > nums[pivot] /*&& nums[j]!=nums[j-1]*/){
                    swapIndex = j;
                    break;
                }
            }
            // swap-->pivot && swapIndex
            swap(nums[pivot],nums[swapIndex]);
        }
        // this is why we have kept pivot=-1, if not pivot reverse whole array
        reverse(nums.begin()+ pivot + 1, nums.end());  
    }
};



