class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();

        // BRUTEFORCE
        // int maxcount=0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             maxcount++;
        //         }
        //     }
        // }
        // return maxcount;


        // OPTIMISE -> PREFIX SUM + HASHMAP
        unordered_map<int,int> mp;
        mp[0]++;
        int sum=0;
        int result=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int ques = sum-k;
            int freq = mp[ques];
            result+=freq;
            mp[sum]++;
        }
        return result;
    }
};