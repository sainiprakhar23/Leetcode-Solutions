class Solution {
public:
    bool backspaceCompare(string s, string t) {

        /*2-POINTER*/
        int i=s.length()-1;
        int j=t.length()-1;
        int skipS=0;
        int skipT=0;

        while(i>=0 || j>=0){
            // find the valid character of s
            while(i>=0){
                if(s[i]=='#'){
                    i--;
                    skipS++;
                }
                else if(s[i]!='#' && skipS>0){
                    i--;
                    skipS--;
                }
                else{
                    // s[i]!='#' && skipS<=0
                    break; //we have found the valid index
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    j--;
                    skipT++;
                }
                else if(t[j]!='#' && skipT>0){
                    j--;
                    skipT--;
                }
                else{
                    // s[i]!='#' && skipS<=0
                    break; //we have found the valid index
                }
            }

            // One string has a character, the other doesn't
            if (i < 0 || j < 0) {
                 return i<0 && j<0; //Return true only if BOTH strings are finished.
            }

            if(s[i]!=t[j]) return false;

            i--;
            j--; 

        }
        return true;
        
        // stack<char>s1;
        // stack<char>s2;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='#' && !s1.empty()){
        //         s1.pop();  
        //     }
        //     else{
        //         if(s[i]!='#'){
        //             s1.push(s[i]);;
        //         }
        //     }
        // }
        // string str1="";
        // while(!s1.empty()){
        //     str1+=s1.top();
        //     s1.pop();
        // }


        // for(int j=0;j<t.length();j++){
        //     if(t[j]=='#' && !s2.empty()){
        //         s2.pop();  
        //     }
        //     else{
        //         if(t[j]!='#'){
        //             s2.push(t[j]);;
        //         }
        //     }
        // }

        // string str2="";
        // while(!s2.empty()){
        //     str2+=s2.top();
        //     s2.pop();
        // }

        // if(str1==str2) return true;
        // return false;



    }
};