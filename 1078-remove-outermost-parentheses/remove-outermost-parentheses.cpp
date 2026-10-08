class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string result;
        // how to chec k a parantheses , if count ==0;
        // only insert when count!=0;
        // if -> (  count++, else count--
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                if(count != 0) result.push_back(s[i]);
                count++;
            }
            else{
                count--; //imp bcz if we do lately , as last ) may have count!=0
                if(count != 0) result.push_back(s[i]);
            }
        }
        return result;
    }
};