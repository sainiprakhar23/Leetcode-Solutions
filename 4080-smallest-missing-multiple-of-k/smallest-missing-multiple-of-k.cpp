class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int j=1;j<=101;j++){
            int num = k*j;
            if(s.find(num)==s.end()){
                return num;
            }
        }
        return 0;
    }
};