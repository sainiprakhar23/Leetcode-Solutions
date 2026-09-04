class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // Bruteforce will fail -->TLE
        // OPTIMAL
        // precalcalate the max_elemt till [i]th index
        // precalcalate the min_elemt till [i-->n-1]th index
        // we can make 2 vector for both ;
        // but for max_elemt -> we can simply maintain a varible;
        // for min_element we have to to a vector
        int n= nums.size();
        vector<int> minElement(n);
        int minEle=INT_MAX;
        // for min element [from i ----> n-1]-> traverse form right and update minElement
        for(int i=n-1;i>=0;i--){
            minEle = min(minEle,nums[i]);
            minElement[i]=minEle;
        }
        // this will store min ele at each index ( eg. at i=4, if ele is 3, means 3 is the min element from i=4 to i=n-1 )
        int maxEle=INT_MIN;
        for(int i=0;i<n;i++){
            maxEle = max(maxEle,nums[i]);
            if(maxEle - minElement[i]  <= k){
                return i;
            }
        }
        return -1;

        // TC = O(n)
        // SC = O(n)
    }
};