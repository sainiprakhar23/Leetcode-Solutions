class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int needed = target-nums[i];
            if(mp.find(needed) != mp.end()){
                return {i,mp[needed]};
                break;
            }
            // if not found in map, stor it in the map
            mp[nums[i]]=i;
        }
        return {};
        
    }
};