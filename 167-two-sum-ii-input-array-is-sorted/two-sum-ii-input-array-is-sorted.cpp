class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        //  TWO POINTER APPROACH
        int left = 0;
        int right = n-1;
        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum > target) right--;
            else  if(sum < target) left++;
            else{
                // sum == target
                return {left+1, right+1};
            }
        }
        return {};


        // USING HASHMAP
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     int needed = target-nums[i];
        //     if(mp.find(needed) != mp.end()){
        //         return {i+1,mp[needed]+1};
        //         break;
        //     }
        //     // if not found in map, stor it in the map
        //     mp[nums[i]]=i;
        // }
        // return {};

        
    }
};