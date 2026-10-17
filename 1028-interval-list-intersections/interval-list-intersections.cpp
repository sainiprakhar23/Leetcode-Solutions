class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        if(n==0 || m==0) return {};

        vector<vector<int>> res;
        int i=0;
        int j=0;

        while(i<n && j<m){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];

            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(start1 <= end2  && start2 <= end1){
                // overlpping conditon , fint he points
                int startPoint = max(start1,start2);
                int endPoint = min(end1,end2);
                res.push_back({startPoint,endPoint});
                
            }
            // Move the pointer whose interval ends first
            if (end1 < end2) {
                i++;
            } else {
                j++;
            }

        }
        return res;
    }
};