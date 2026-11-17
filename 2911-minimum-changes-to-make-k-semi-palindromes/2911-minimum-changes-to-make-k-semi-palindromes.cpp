class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * d <= len; ++d) {
                if (len % d == 0) {
                    if (d < len) divisors[len].push_back(d);
                    if (d != len / d && (len / d) < len) {
                        divisors[len].push_back(len / d);
                    }
                }
            }
        }
        
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    for (int rem = 0; rem < d; ++rem) {
                        int left = i + rem;
                        int right = j - (d - 1 - rem);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[n][0] = 0;
        
        for (int parts = 1; parts <= k; ++parts) {
            for (int i = 0; i <= n - 2 * parts; ++i) {
                for (int x = i + 1; x <= n - 2 * (parts - 1) - 1; ++x) {
                    if (dp[x + 1][parts - 1] != INF) {
                        dp[i][parts] = min(dp[i][parts], cost[i][x] + dp[x + 1][parts - 1]);
                    }
                }
            }
        }
        
        return dp[0][k];
    }
};