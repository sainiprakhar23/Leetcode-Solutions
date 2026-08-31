class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#' && !s1.empty()){
                s1.pop();  
            }
            else{
                if(s[i]!='#'){
                    s1.push(s[i]);;
                }
            }
        }
        string str1="";
        while(!s1.empty()){
            str1+=s1.top();
            s1.pop();
        }


        for(int j=0;j<t.length();j++){
            if(t[j]=='#' && !s2.empty()){
                s2.pop();  
            }
            else{
                if(t[j]!='#'){
                    s2.push(t[j]);;
                }
            }
        }

        string str2="";
        while(!s2.empty()){
            str2+=s2.top();
            s2.pop();
        }

        if(str1==str2) return true;
        return false;



    }
};