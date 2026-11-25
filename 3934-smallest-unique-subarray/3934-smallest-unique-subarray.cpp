class Solution {
    static constexpr long long MOD1 = 1000000007LL;
    static constexpr long long MOD2 = 1000000009LL;
    static constexpr long long P1 = 1315423911LL;
    static constexpr long long P2 = 2654435761LL;

    bool checkLen(int len, const vector<long long>& h1, const vector<long long>& h2,
                  const vector<long long>& pw1, const vector<long long>& pw2) {
        int n = (int)h1.size() - 1;
        unordered_map<unsigned long long, int> seen;
        seen.reserve((n - len + 1) * 2);

        for (int i = 0; i + len <= n; i++) {
            long long a = (h1[i + len] - h1[i] * pw1[len]) % MOD1;
            if (a < 0) a += MOD1;

            long long b = (h2[i + len] - h2[i] * pw2[len]) % MOD2;
            if (b < 0) b += MOD2;

            unsigned long long combined = ((unsigned long long)a << 32) | (unsigned long long)b;
            seen[combined]++;
        }

        for (auto& entry : seen) {
            if (entry.second == 1) return true;
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<long long> pw1(n + 1, 1), pw2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        long long base1 = P1 % MOD1;
        long long base2 = P2 % MOD2;

        for (int i = 0; i < n; i++) {
            pw1[i + 1] = pw1[i] * base1 % MOD1;
            pw2[i + 1] = pw2[i] * base2 % MOD2;
            h1[i + 1] = (h1[i] * base1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * base2 + nums[i]) % MOD2;
        }

        int left = 1, right = n, ans = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (checkLen(mid, h1, h2, pw1, pw2)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};