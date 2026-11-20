class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // NEXT GREATER COCCEPT OF STACK IT USED
        int n = temperatures.size();
        vector<int> res(n,0);
        res[n-1]=0;
        stack<int> st; //we will store index and when soln found, return diif og index
        st.push(n-1);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()) res[i]=0;
            else res[i] = st.top()-i;

            st.push(i);
        }
        return res;
    }
};