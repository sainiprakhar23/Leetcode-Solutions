class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // STORE N-2 elements in st as for cicular, to find out and for the last elemtn rest all same as for Next Greater Element
        int n = nums.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=n-2; i>=0; i--){
            st.push(nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }

            if(st.empty()) res[i]=-1;
            else res[i]=st.top();

            st.push(nums[i]);
        }

        return res;
    }
};