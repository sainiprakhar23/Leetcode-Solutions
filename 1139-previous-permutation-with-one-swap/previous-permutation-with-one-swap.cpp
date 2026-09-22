class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int pivot = -1;
        // finding the rightmost element to swap
        for(int i=n-1;i>0;i--){
            if(arr[i-1] > arr[i]){
                pivot = i-1;
                break;
            }
        }
        if(pivot != -1){
            int swapIndex = pivot;
            for(int j=n-1;j>0;j--){
                if(arr[j]<arr[pivot] && arr[j]!=arr[j-1]){
                    swapIndex = j;
                    break;
                }
            }
            // swap-->pivot && swapIndex
            int temp = arr[pivot];
            arr[pivot]=arr[swapIndex];
            arr[swapIndex]=temp;

            // we will not reverse in previous premutation
            //reverse(arr.begin() + pivot +1 , arr.end());
        }
            return arr;
    }
};