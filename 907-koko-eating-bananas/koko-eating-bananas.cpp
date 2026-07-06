class Solution {
public:
    bool isPossible(int mid, vector<int>& arr, int h) {
        long long hours = 0;

        for (int bananas : arr) {
            hours += (bananas + mid - 1) / mid;

            if (hours > h)
                return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid,piles,h)==true){
                ans= mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
};