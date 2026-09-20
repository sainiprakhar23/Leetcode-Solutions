class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        for(int i=0; i<s.length();i++){

            int reverseIdx = 26 - (s[i] - 'a');
            result += reverseIdx*(i+1);  //postion starts from1 that is why i+1
        }
        return result;
        
    }
};