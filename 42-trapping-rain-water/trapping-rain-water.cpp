class Solution {
public:
    /*PREFIX ARRAY SOLUTION*/
    // vector<int>leftMaxArray(vector<int>& height,int& n){
    //     vector<int>leftMax(n);
    //     leftMax[0]=height[0]; //leftmost element
    //     for(int i=1;i<n;i++){
    //         leftMax[i]=max(leftMax[i-1],height[i]);
    //     }
    //     return leftMax;
    // }
    // vector<int>rightMaxArray(vector<int>& height,int& n){
    //     vector<int> rightMax(n);
    //     rightMax[n-1]=height[n-1]; //right most elemnt
    //     for(int i=n-2;i>=0;i--){
    //         rightMax[i]=max(rightMax[i+1],height[i]);
    //     }
    //     return rightMax;
    // }
    int trap(vector<int>& height) {
        // using 2 arrays
        int n = height.size();
        // vector<int> leftMax = leftMaxArray(height,n);
        // vector<int> rightMax = rightMaxArray(height,n);

        // int area=0;
        // for(int i=0;i<n;i++){
        //     area += min(leftMax[i],rightMax[i]) - height[i];
        // }
        // return area;    


        /*2 PONTER SOLUTION*/
        // INSTEAD OF MAINTINF 2 ARRAY WE MAINTAIN 2 POINTER AND CAL FROM ONE WHHICH IS MINIMUM
        int area=0;
        int left=0;
        int right=n-1;
        int leftMax=height[0];
        int rightMax=height[n-1];

        while(left<=right){
            // cal lmax and rmax
            leftMax=max(leftMax,height[left]);
            rightMax=max(rightMax,height[right]);

            // which ever is min cal from that side
            if(leftMax<rightMax){
                area += (leftMax - height[left]);
                left++;
            }
            else{
                area += (rightMax - height[right]);
                right--;
            }
        }
        return area;
    }
};