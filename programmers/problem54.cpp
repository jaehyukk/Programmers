// dp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0] - 1;
        int y = puddles[i][1] - 1;
        dp[y][x] = -1;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;

            if (dp[i][j] == -1) continue;

            if (i == 0 && j != 0) {
                if (dp[i][j - 1] == -1) continue;
                dp[i][j] = dp[i][j - 1] % 1000000007;
            }
            else if (j == 0 && i != 0) {
                if (dp[i - 1][j] == -1) continue;
                dp[i][j] = dp[i - 1][j] % 1000000007;
            }
            else {
                if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j] % 1000000007;
                else if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1] % 1000000007;
                else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }
    }
    answer = dp[n - 1][m - 1];

    return answer;
}
