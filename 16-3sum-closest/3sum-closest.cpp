class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff=INT_MAX;
        int closest_sum=INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                int diff = target-sum;
                if(fabs(diff) < min_diff){
                    min_diff=fabs(diff);
                    closest_sum = sum;
                }
                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    if(diff==0) return sum;
                     
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }

                    left++;
                    right--;

                }
               
            }

        }
        return closest_sum;
    }
};