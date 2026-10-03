class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum = 0;
        int count=0;
        unordered_map<int,int> mp; //remainde:index
        mp[0]=1;  //why we add this intially

        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int remainder = prefixSum % k;

            // edge case
            if(remainder < 0) remainder = remainder + k;

            if(mp.find(remainder) != mp.end()){
                int freq = mp[remainder];
                count += freq;
            }
            mp[remainder]++;
        }
        return count;
        
    }
};