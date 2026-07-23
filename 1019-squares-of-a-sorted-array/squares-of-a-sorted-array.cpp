class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        if(neg.size()==0){
            for(int j=0;j<pos.size();j++){
                pos[j] = pos[j]*pos[j];
            }
            return pos;
        }
        if(pos.size()==0){
            for(int k=0;k<neg.size();k++){
                neg[k] = neg[k]*neg[k];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }

      
        for(int j=0;j<pos.size();j++){
            pos[j] = pos[j]*pos[j];
        }

        for(int k=0;k<neg.size();k++){
            neg[k] = neg[k]*neg[k];
        }

        reverse(neg.begin(),neg.end());

        int i=0;
        int j=0;
        while(i<pos.size() && j<neg.size()){
            if(pos[i] <= neg[j]){
                res.push_back(pos[i]);
                i++;
            }
            else{
                res.push_back(neg[j]);
                j++;
            }
        }

        while(i<pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            res.push_back(neg[j]);
            j++;
        }

        return res;
    }
};