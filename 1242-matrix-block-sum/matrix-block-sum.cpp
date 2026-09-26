class Solution {
public:

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

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int Rmin = max(0, i-k);
                int Rmax = min(n-1, i+k);

                int Cmin = max(0, j-k);
                int Cmax = min(m-1, j+k);

                ans[i][j] = value(mat, Rmin, Rmax, Cmin, Cmax);
            }
        }

        return ans;
    }
};