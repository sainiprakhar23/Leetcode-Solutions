class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // OPTIMAL -> KADANE'S ALGO + 1 DELETION
        int n = arr.size();
        // powerNotUsed = maximum subarray sum ending at i
        //                where NO deletion has been used
        //
        // powerUsed = maximum subarray sum ending at i
        //             where ONE deletion has already been used

        // Predefining for i=0
        int powerNotUsed = arr[0];
        // We cannot have a deletion at i=0 yet
        // because there is no previous element to delete
        int powerUsed = INT_MIN;
        int maxSum = arr[0];
        for(int i = 1; i < n; i++){
            // ---------------- NO POWER USED ----------------
            int v1 = arr[i]; 
            // START NEW SUBARRAY from current element
            int v2 = powerNotUsed + arr[i];
            // CONTINUE previous subarray

            // ---------------- POWER USED ----------------
            // OPTION 1:
            // Delete CURRENT element arr[i]
            // So previous powerNotUsed remains
            int v3 = powerNotUsed;
            // OPTION 2:
            // Deletion was already used previously
            // So we HAVE TO include current arr[i]
            int v4 = INT_MIN;
            // IMPORTANT:
            // If powerUsed == INT_MIN, it means this state
            // is IMPOSSIBLE, so don't do INT_MIN + arr[i]
            if(powerUsed != INT_MIN){
                v4 = powerUsed + arr[i];
            }
            // ans:"Only extend the powerUsed state if we actually had a valid powerUsed state from the previous index."

            powerNotUsed = max(v1, v2);
            powerUsed = max(v3, v4);
            maxSum = max(maxSum, max(powerNotUsed, powerUsed));
        }

        return maxSum;
    }
};