class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int num = nums[n-1];
        int moves=0;
        for(auto x : nums){
            moves+= abs(num-x);
        }
        return moves;
    }
};