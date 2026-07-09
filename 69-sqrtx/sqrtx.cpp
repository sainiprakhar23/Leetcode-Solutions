class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0; //edge case
        int low=1;
        int high = x;
        int ans=0; //for edge case

        while(low<=high){
            int mid = low + (high-low)/2;
            long long square = 1LL * mid * mid;
            if(square==x) return mid;
            if(square < x){
                ans=mid;
                low = mid+1;  //search for a larger valid answer 
            }
            else{
                high = mid-1; //search for a smaller valid answer
            }

        }
        return ans;
    }
};