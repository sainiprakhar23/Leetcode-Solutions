class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
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