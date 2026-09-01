class Solution {
public:
    int maxArea(vector<int>& height) {
        // we will use greedy, as if we are decresing with, we need the more hieght to sustain max area
        int n= height.size();
        int left = 0;
        int right = n-1;
        int maxArea =INT_MIN;

        while(left <= right){
            // int heightofContainer = min(height[left],height[right]);
            // int widthofContainer = right-left;
            // int area = heightofContainer*widthofContainer;

            int area = min(height[left],height[right]) * (right-left);

            maxArea = max(maxArea,area);

            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
        
    }
};