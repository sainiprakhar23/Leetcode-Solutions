class Solution {
public:
    int mySqrt(int x) {
        //if(x==0) return 0;
        int low=1;
        int high= x;
        int ans=0;

        while(low<=high){
            int mid = low+(high-low)/2;
            long long square = 1LL * mid * mid;
            if(square == x) return mid;
            if(square < x){
                // Store current mid as a possible answer and search for a larger valid square root.
                ans = (int) mid;
                low=mid+1;
            }
            else{  //square > x
                high=mid-1;
            }
        }
        return ans;

    }
};