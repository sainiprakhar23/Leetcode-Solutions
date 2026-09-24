class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        // using prefix and suffix sum array
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0]=0;
        suffix[n-1]=0;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int j=n-2;j>=0;j--){
            suffix[j] = suffix[j+1] + nums[j+1];
        }
        for(int k=0;k<n;k++){
            if(prefix[k]==suffix[k]){
                return k;
            }
        }
        return -1;

        // using total sum and left variable
        // int totalSum=0;
        // int left = 0;
        // int right = 0;
        // for(int i=0;i<n;i++){
        //     totalSum+=nums[i];
        // }
        
        // for(int j=1;j<n;j++){
        //     left += numsji-1];
        //     right = totalSum - nums[j] - left;
        //     if(left==right) return j;
        // }
        // return -1;

    }
};