class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // BRUTEFORCE
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     int product=1;
        //     for(int j=0;j<n;j++){
        //         if(i==j) continue;
        //         product*=nums[j];
        //     }
        //     ans[i]=product;
        // }
        // return ans;


        // OPTIMAL -> PREFIX SUM
        // vector<int>prefixProduct(n);
        // vector<int>suffixProduct(n);
        vector<int>result(n);
        // prefixProduct[0]=1;
        // suffixProduct[n-1]=1;
        // for(int i=1;i<n;i++){
        //     prefixProduct[i] = nums[i-1] * prefixProduct[i-1];
        // }
        // for(int j=n-2;j>=0;j--){
        //     suffixProduct[j] = nums[j+1] * suffixProduct[j+1];
        // }
        // for(int k=0;k<n;k++){
        //     result[k] = prefixProduct[k] * suffixProduct[k]; 
        // }

        // return result;

        // truing to solve folow up??
        result[0]=1;
        for(int i=1;i<n;i++){
            result[i] = result[i-1] * nums[i-1];
        }

        // now maintain a right varible
        int rightProduct = 1;
        for(int j = n-2;j>=0;j--){
            rightProduct = rightProduct * nums[j+1];
            result[j] = result[j] * rightProduct;
        }
        return result;
    }
};