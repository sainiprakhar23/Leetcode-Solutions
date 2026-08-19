class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(nums.begin(),nums.end());
       
        
        for(int r=0;r<n;r++){  //first loop is for the rotation(r=2, means rotated by 2 place)
             bool flag=true;
            for(int i=0;i<n;i++){ //now check if positons are correct
                if(sorted[i] != nums[(i+r) % n]){
                    flag=false;
                    break;
                }
            }

            if(flag) return flag;
        }
        return false;
    }
};