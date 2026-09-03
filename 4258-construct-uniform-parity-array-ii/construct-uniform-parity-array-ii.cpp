class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int countEven=0;
        int minEven=INT_MAX;
        int minOdd = INT_MAX;
        int countOdd=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                countEven++;
                minEven=min(minEven,nums1[i]);
            }
            else{
                countOdd++;
                minOdd=min(minOdd,nums1[i]);
            }
        }
        if(countEven==0 || countOdd==0) return true;

        if(minOdd<minEven){
            for(int i=0;i<n;i++){
                if(nums1[i]%2 !=0)continue;
                nums1[i]=nums1[i]-minOdd;
                if(nums1[i]<=0 || nums1[i]%2==0) return false;
                break;
            }
        }
        else{ //minEven
            for(int i=0;i<n;i++){
                if(nums1[i]%2 ==0)continue;
                nums1[i]=nums1[i]-minEven;
                if(nums1[i]<=0 || nums1[i]%2!=0) return false;
                break;
            }         
        }
       
        return true;
        
    }
};