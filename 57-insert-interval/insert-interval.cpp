class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int start1 = newInterval[0];
        int end1 = newInterval[1];

        for(int i=0; i<n; i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(start1 <= end2  && start2<=end1){
                // overlapping condtion
                start1 = min(start1,start2);
                end1 = max(end1,end2);
            }else{
                // no ovelap
                if(start2 < start1){
                    res.push_back({start2,end2});
                }
                else{
                    res.push_back({start1,end1});
                    start1 = start2;
                    end1 = end2;
                }
            }
        }
        res.push_back({start1,end1});
        return res;
    }
};