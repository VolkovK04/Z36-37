#include <vector>

using namespace std;

class Solution36 {
public:
    int numTrees(int n) {
        int* a = new int[n + 1];
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; ++i) {
            a[i] = 0;
            for (int j = 1; j <= i; ++j) {
                a[i] += a[j - 1] * a[i - j];
            }
        }
        return a[n];
    }
};

class Solution37 {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return dp[0][0];
    }
};