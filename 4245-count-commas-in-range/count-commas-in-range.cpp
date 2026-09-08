class Solution {
public:
    int countCommas(int n) {

        int num = n;
        int length = std::to_string(num).length();   

        if(length<4) return 0;
        return n-1000 +1;
        
            
    }
};