class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=INT_MAX;
        int idx;
        // if(n<=1){
        //     if(nums[0] <=k) return 0;
        //     else return -1;
        // }
        for(int i=0;i<n;i++){
            int num1 = *max_element(nums.begin(),nums.begin()+i);
            int num2 = *min_element(nums.begin()+i,nums.end());

            if(num1-num2 <=k) return i;
        }
        return -1;

    }
};