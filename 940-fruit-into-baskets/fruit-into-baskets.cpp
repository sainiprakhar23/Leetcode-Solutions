class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // BRUTEFORCE
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     unordered_set<int> st;
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         st.insert(fruits[j]);
        //         if(st.size()>2){
        //             break;
        //         }   
        //         count++;
        //     }
        //     ans = max(ans,count);
        // }
        // return ans;

        // OPTIMAL->SLIDINF WINDOW + HASHMAP
        unordered_map<int,int> mp;
        int maxLen = 0;
        int left = 0;
        for(int right=0; right<n; right++){
            mp[fruits[right]]++;
            while(mp.size() >2){
                mp[fruits[left]]--;

                if(mp[fruits[left]] == 0 ) mp.erase(fruits[left]);
                left++;
            }
            maxLen = max(maxLen,right-left + 1);
        }
        return maxLen;

        
    }
};