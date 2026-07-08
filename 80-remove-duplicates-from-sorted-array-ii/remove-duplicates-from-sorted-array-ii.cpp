class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int count =1;//we are keeping first element 
        while(j<nums.size()){
            if(nums[i]==nums[j] && count<2){
                i++;
                nums[i]=nums[j];
                //nums[++i]==nums[j];
                count++;

            }
            else if(nums[i]!=nums[j]){
                count=0;
                i++;
                nums[i]=nums[j];
                // nums[++i]=nums[j];
                count++;
            }
            j++;
        }
        return i+1;
    }
};