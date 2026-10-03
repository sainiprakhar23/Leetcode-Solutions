class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        // BRUTEFORCE
        // for(int i=0;i<n;i++){
        //     int sum=nums[i];
        //     for(int j=i+1;j<n;j++){
        //         sum+=nums[j];
        //         if(sum % k == 0) return true;
        //         //break;
        //     }
        // }
        // return false;


        // OPTIMAL -->PREFIX SUM + HASHMAP(REMAINDE : INDEX)
        unordered_map<int,int> mp;
        mp[0]=-1;
        int prefixSum=0;
        for(int index=0;index<n;index++){
            prefixSum += nums[index];
            int remainder = prefixSum % k;
            if(mp.find(remainder) != mp.end()){
                if( index - mp[remainder] >= 2) return true;
            }else{
                mp[remainder]=index;
            }
        }
        return false;
    }
};