class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold,  int mid){
        int sum=0;
        for(auto x: nums){
            sum = sum + (x + mid -1)/mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // search space
        int low = 1;//the lowest divisor possible;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums,threshold,mid)){
                ans=mid;
                high=mid-1; //ihave to find minimun divisor;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};