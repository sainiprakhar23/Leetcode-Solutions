class Solution {
public:
        // BRUTEFORCE
    int value(vector<vector<int>>& mat,
              int Rmin, int Rmax,
              int Cmin, int Cmax) {
        int sum = 0;
        for(int i = Rmin; i <= Rmax; i++) {
            for(int j = Cmin; j <= Cmax; j++) {
                sum += mat[i][j];
            }
        }
        return sum;
    }

        // BRUTEFORCE
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {

        //         int Rmin = max(0, i-k);
        //         int Rmax = min(n-1, i+k);

        //         int Cmin = max(0, j-k);
        //         int Cmax = min(m-1, j+k);

        //         ans[i][j] = value(mat, Rmin, Rmax, Cmin, Cmax);
        //     }
        // }
        // return ans;

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n = mat.size();       // Number of rows
        int m = mat[0].size();    // Number of columns

        // Answer matrix: same size as original matrix
        vector<vector<int>> ans(n, vector<int>(m, 0));



        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));


        // Build prefix matrix
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // IMPORTANT:
                //
                // prefix[i][j] corresponds to mat[i-1][j-1]
                //
                // We take:
                //
                // current element
                // + everything above
                // + everything on the left
                // - top-left because it was counted twice

                prefix[i][j] =
                    mat[i-1][j-1]
                    + prefix[i-1][j]
                    + prefix[i][j-1]
                    - prefix[i-1][j-1];
            }
        }


        // =========================================================
        // STEP 2: CALCULATE EACH ans[i][j]
        // =========================================================

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // -------------------------------------------------
                // Find the block around (i, j)
                // -------------------------------------------------
                //
                // Example:
                //
                // k = 1
                //
                // For (1,1):
                //
                // rows = [0,2]
                // cols = [0,2]
                //
                // For a boundary cell, we clip the range.
                //

                int r1 = max(0, i - k);
                int c1 = max(0, j - k);

                int r2 = min(n - 1, i + k);
                int c2 = min(m - 1, j + k);


                // -------------------------------------------------
                // Convert ORIGINAL matrix coordinates
                // to PREFIX matrix coordinates.
                // -------------------------------------------------
                //
                // Prefix matrix has one extra row and column.
                //
                // mat[i][j] corresponds to prefix[i+1][j+1]
                //
                // Therefore add 1 to all boundaries.

                r1++;
                c1++;
                r2++;
                c2++;


                // -------------------------------------------------
                // Rectangle Sum Formula
                // -------------------------------------------------
                //
                //        c1       c2
                //         ↓        ↓
                //      ┌────────────┐
                // r1 → │    BLOCK   │
                //      │            │
                // r2 → └────────────┘
                //
                // Rectangle sum =
                //
                // bottom-right
                // - area above
                // - area left
                // + top-left
                //
                // Why + top-left?
                // Because it was subtracted twice.
                //

                ans[i][j] =
                    prefix[r2][c2]           // Total up to bottom-right
                    - prefix[r1-1][c2]      // Remove area above
                    - prefix[r2][c1-1]      // Remove area on left
                    + prefix[r1-1][c1-1];   // Add overlapping area back
            }
        }


        return ans;
    }
};
