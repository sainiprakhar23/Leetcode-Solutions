class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        // prev[i] = number of intervals before i
        // that don't overlap with interval i
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(), ends.end(), a[i][0])
                - ends.begin();
        }

        // dp[k][i] = best answer using first i intervals
        // and at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            5,
            vector<pair<long long, vector<int>>>(n + 1)
        );

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {

                // Don't take current interval
                dp[k][i] = dp[k][i - 1];

                // Take current interval
                int idx = i - 1;

                auto candidate = dp[k - 1][prev[idx]];

                candidate.first += a[idx][2];
                candidate.second.push_back(a[idx][3]);

                sort(candidate.second.begin(), candidate.second.end());

                // Better score OR same score but lexicographically smaller
                if (candidate.first > dp[k][i].first ||
                    (candidate.first == dp[k][i].first &&
                     candidate.second < dp[k][i].second)) {

                    dp[k][i] = candidate;
                }
            }
        }

        return dp[4][n].second;
    }
};