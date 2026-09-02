class Solution {
public:
    vector<int>leftMaxArray(vector<int>& height,int& n){
        vector<int>leftMax(n);
        leftMax[0]=height[0]; //leftmost element
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }
    vector<int>rightMaxArray(vector<int>& height,int& n){
        vector<int> rightMax(n);
        rightMax[n-1]=height[n-1]; //right most elemnt
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        // using 2 arrays
        int n = height.size();
        vector<int> leftMax = leftMaxArray(height,n);
        vector<int> rightMax = rightMaxArray(height,n);

        int area=0;
        for(int i=0;i<n;i++){
            area += min(leftMax[i],rightMax[i]) - height[i];
        }
        return area;    
    }
};