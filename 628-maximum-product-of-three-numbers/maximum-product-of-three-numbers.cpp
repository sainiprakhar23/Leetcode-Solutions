class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int size = nums.size();
        int maximum = nums[size-1];
        int second_maximum = nums[size-2];
        int third_maximum = nums[size-3];

        long long result_1 = maximum * second_maximum * third_maximum;

        int neg_product=0;
        if(nums[0]<0 && nums[1]<0 && maximum>0){
            neg_product = nums[0]*nums[1];
            long long result_2 = maximum * neg_product;
            if(result_2 > result_1){
                return (int)result_2;
            }
        }   
        return (int)result_1;
    }
};