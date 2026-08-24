class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        // improved Brutefoce
        // for(int i=0;i<n;i++){
        //     unsigned long long product=1;
        //     for(int j=i;j<n;j++){
        //         product = product * nums[j];
        //         if(product >= k) break;
        //         count++;
        //     }
        // }


        // optimal --> sliding window;
        if(k<=1) return 0;
        int left =0;
        int  product = 1;
        for(int right=0; right<n;right++){
            product*=nums[right];
            while(product >=k ){
                product/=nums[left];
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
};