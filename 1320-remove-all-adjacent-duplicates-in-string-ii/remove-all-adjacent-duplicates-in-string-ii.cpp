class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>> st;  //char:count

        for(int i=0; i<n; i++){
            char ch = s[i];
            // CASE 1: If the stack is empty-> push 
            if(st.empty()){
                st.push({ch,1});
                continue;
            }

            // CASE 2: If the stack top is not eqal to current number-> push 
            if(ch != st.top().first){
                st.push({ch,1});
                continue;
            }
            // CASE 3: If the stack top is eqal to current number-> then first check
            // if count < k-1 -> add the count, if not pop from the stack
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



// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         stack<pair<char,int>> st;

//         for(char ch : s) {
//             if(!st.empty() && st.top().first == ch) {
//                 st.top().second++;

//                 if(st.top().second == k)
//                     st.pop();
//             }
//             else {
//                 st.push({ch, 1});
//             }
//         }

//         string res = "";

//         while(!st.empty()) {
//             auto [ch, cnt] = st.top();
//             st.pop();

//             res += string(cnt, ch);
//         }

//         reverse(res.begin(), res.end());
//         return res;
//     }
// };