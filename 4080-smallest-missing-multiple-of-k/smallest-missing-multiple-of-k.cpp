class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());

        for(int j=1;j<=nums.size()+1;j++){  //j<nums.szzie()+1 or __
            int num = k*j;
            if(s.find(num)==s.end()){
                return num;
            }
        }
        return 0;
    }
};