class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int result = 0;
        int n = nums.size();
        unordered_map<int,int> mp; //diff:index
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else one++;

            int diff = zero-one;
            if(diff==0) result = max(result,i+1);

            if(mp.find(diff)==mp.end()){
                // not found in map stor the diff with index where it was last found
                mp[diff]=i;
            }
            else{
                // found in hashmap , store map value
                // we don't need to update the indx ans we need longest subaaray
                // for that laal part must be small
                int index = mp[diff];
                //int lengthofGreenPart = i-idx+1;
                //result = max(result,lengthofGreenPart);
                result = max(result,i-index);
            }
        }
        return result;
    }
};