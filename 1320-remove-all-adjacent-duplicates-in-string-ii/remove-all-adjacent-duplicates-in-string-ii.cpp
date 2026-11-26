class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;  //char:count

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.empty()){
                st.push({ch,1});
                continue;
            }

            if(ch != st.top().first){
                st.push({ch,1});
                continue;
            }

            if(st.top().second < k-1){
                pair<char,int> p  = st.top();
                st.pop();
                st.push({p.first,p.second+1});
            }else{
                st.pop();
            }
            
        }

        string res="";

        while(!st.empty()){
            pair<char,int> p = st.top();
            st.pop();

            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};