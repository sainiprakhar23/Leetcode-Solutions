class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n-k+1);
        deque<int> dq; //it will store index
        
        for(int right=0; right<n; right++){
            // if when index  is in valid or out of window size
            while(!dq.empty() && dq.front() <= right-k){
                // or dq.front() < right-k+1  -->r-k+1 ir start index of cuurent window
                dq.pop_front();
            }
            // If the new element is greater than or equal to the element at the back, remove the back element.
            while(!dq.empty() && nums[right] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
            // inserting in res vector
            if(right >= k-1){
                res[right-k+1]=nums[dq.front()];
            }
        }
        return res;
    }
};