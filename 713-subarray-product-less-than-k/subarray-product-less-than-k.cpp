class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            unsigned long long product=1;
            for(int j=i;j<n;j++){
                product = product * nums[j];
                if(product >= k) break;
                count++;
            }
        }
        return count;
    }
};