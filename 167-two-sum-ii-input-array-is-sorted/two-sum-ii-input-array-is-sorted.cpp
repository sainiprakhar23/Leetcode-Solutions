class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // using 2 pointer approach
        // int i = 0;
        // int j = numbers.size()-1;
        // while(i<j){
        //     int sum = numbers[i]+numbers[j];
        //     if(sum == target) return {i+1,j+1};
        //     if(sum < target) i++;
        //     else j--; //(sum > target)
        // }
        // return {};

        // using map
        unordered_map<int,int> mp;
        for(int i=0;i<numbers.size();i++){
            int remain = target - numbers[i];
            if(mp.find(remain) != mp.end()){
                return {mp[remain]+1,i+1};
            }
            mp[numbers[i]]=i;
            
        }
        return {};


    }
};