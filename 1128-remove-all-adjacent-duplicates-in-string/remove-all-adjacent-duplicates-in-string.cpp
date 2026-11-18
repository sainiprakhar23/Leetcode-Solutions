class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans="";
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty() || ch != st.top()){
                st.push(ch);
            }
            else{
                // ch==st.top
                st.pop();
            }
        }

        while(!st.empty()){
            char ch = st.top();
            ans.push_back(ch);
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};