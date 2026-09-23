class Solution {
public:
    int atMost(vector<int> nums, int k){
        unordered_map<int,int>mp;
        int left = 0;
        int count=0;
        for(int right = 0; right< nums.size(); right++){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] ==0 )mp.erase(nums[left]);
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        // BRUTEFORCE
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     unordered_set<int> st;
        //     for(int j=i;j<n;j++){
        //         st.insert(nums[j]);
        //         if(st.size() > k){
        //             break;
        //         }
        //         // normal Sliding Window count for at most Ki , i.e <=k, but we want ==k
        //         if(st.size()==k) ans++;
        //     }
        // }
        // return ans;

        // OPTIMAL ->SLIDING WINDOW + HASHMAP
        //normal Sliding Window count for at most Ki , i.e <=k, but we want ==k
        // so calculate with "k" then with "k-1" subtract them
        int result = atMost(nums,k) - atMost(nums,k-1);
        return result;
    }
};