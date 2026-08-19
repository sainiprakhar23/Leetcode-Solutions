class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // bruteforce approach
        vector<int> sorted(n); //making a sorted array and check if it is sorted or not
        for(int r=0;r<n;r++){
            int idx=0;
            for(int i=r;i<n;i++){
                sorted[idx]=nums[i];
                idx++;
            }
            // for the remaining part of array
            for(int i=0;i<r;i++){
                sorted[idx]=nums[i];
                idx++;
            }
    
            // check if array is sorted or not
            bool isSorted=true;
            for(int j=0;j<n-1;j++){
                if(sorted[j] > sorted[j+1]){
                    isSorted= false;
                    break;
                }
            }

            if(isSorted) return true;
        }
        return false;

        // brtueforce with better approach
        // vector<int> sorted = nums;
        // sort(nums.begin(),nums.end());
     
        // for(int r=0;r<n;r++){  //first loop is for the rotation(r=2, means rotated by 2 place)
        //      bool flag=true;
        //     for(int i=0;i<n;i++){ //now check if positons are correct
        //         if(sorted[i] != nums[(i+r) % n]){
        //             flag=false;
        //             break;
        //         }
        //     }

        //     if(flag) return flag;
        // }
        // return false;


        // optimal approach
        //check for 1 dip or 1 peak
        // int peak=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i] > nums[(i+1) % n]){ //%n beacuse we have to also chech last ele with first 
        //         peak++;
        //     }
        // }

        // if(peak<2) return true;
        // return false;
    }
};
