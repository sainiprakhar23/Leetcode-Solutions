class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int start1 = newInterval[0];
        int end1 = newInterval[1];

        int i = 0;

        // Phase 1: Add intervals completely before the new interval
        // Existing interval ends before new interval starts
        while (i < n && intervals[i][1] < start1) {
            res.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge overlapping intervals
        // Overlap condition:
        // start1 <= end2 && start2 <= end1
        while (i < n &&
               start1 <= intervals[i][1] &&
               intervals[i][0] <= end1) {

            start1 = min(start1, intervals[i][0]);
            end1 = max(end1, intervals[i][1]);
            i++;
        }

        // Add the final merged interval
        res.push_back({start1, end1});

        // Phase 3: Add all remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    
    }
    //2nd WAY
    //     for(int i=0; i<n; i++){
    //         int start2 = intervals[i][0];
    //         int end2 = intervals[i][1];

    //         if(start1 <= end2  && start2<=end1){
    //             // overlapping condtion
    //             start1 = min(start1,start2);
    //             end1 = max(end1,end2);
    //         }else{
    //             // no ovelap
    //             if(start2 < start1){
    //                 res.push_back({start2,end2});
    //             }
    //             else{
    //                 res.push_back({start1,end1});
    //                 start1 = start2;
    //                 end1 = end2;
    //             }
    //         }
    //     }
    //     res.push_back({start1,end1});
    //     return res;
    // }
};