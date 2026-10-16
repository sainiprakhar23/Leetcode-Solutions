
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end >= start2) {
                // Merge overlapping intervals
                end = max(end, end2);
            } else {
                // No overlap: save the current interval
                result.push_back({start, end});

                start = start2;
                end = end2;
            }
        }
        result.push_back({start, end});

        return result;
    }
};
