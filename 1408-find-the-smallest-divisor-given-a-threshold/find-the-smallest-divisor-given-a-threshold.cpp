class Solution {
public:
    bool isPossible(int mid, vector<int>& arr, int threshold){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            // sum+=ceil((double)(arr[i]/mid));
            sum += (arr[i] + mid - 1) / mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high = *max_element(nums.begin(),nums.end());
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            // function to check
            if(isPossible(mid,nums,threshold)==true){
                ans= mid;
                // now will search for the smallest divisor
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};