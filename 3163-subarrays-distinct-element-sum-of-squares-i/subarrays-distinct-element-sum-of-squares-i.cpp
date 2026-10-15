class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n  = nums.size();
        int squareSum=0;
        for(int i=0;i<n; i++){
            for(int j=i; j<n; j++){
                unordered_set<int> st;
                for(int k=i; k<=j; k++){
                    st.insert(nums[k]);
                }
                int distintValueSize = st.size();
                squareSum += distintValueSize*distintValueSize;
            }
        }
        return squareSum;
    }
};