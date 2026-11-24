#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
    long long lcmLL(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;
        const __int128 CAP = static_cast<__int128>(1e30);

        for (int i = 0; i < n; ++i) {
            __int128 prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long val = nums[j];
                prod *= val;
                g = (g == 0) ? val : std::gcd(g, val);
                l = lcmLL(l, val);

                if (prod == static_cast<__int128>(l) * g) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > CAP) {
                    break;
                }
            }
        }

        return ans;
    }
};