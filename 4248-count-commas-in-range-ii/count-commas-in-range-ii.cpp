class Solution {
public:
    long long countCommas(long long n) {
        long long result=0;
        long long length = std::to_string(n).length();
        if(length < 4) return 0;
        for(long long start = 1000; start<=n; start=start*1000){
            result+=(n-start+1);
        }
        return result;
        
    }
};