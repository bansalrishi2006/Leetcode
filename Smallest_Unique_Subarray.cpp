class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        static constexpr long long BASE = 100003LL;
        static constexpr long long MOD1 = 1000000007LL;
        static constexpr long long MOD2 = 1000000009LL;

        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = (pow1[i] * BASE) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE) % MOD2;
            long long val = static_cast<long long>(nums[i]) + 1LL;
            pref1[i + 1] = (pref1[i] * BASE + val) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE + val) % MOD2;
        }

        auto hasUniqueOfLen = [&](int len) -> bool {
            unordered_map<unsigned long long, int> freq;
            freq.reserve(static_cast<size_t>(n - len + 1) * 2);

            for (int l = 0; l + len <= n; ++l) {
                int r = l + len;
                long long h1 = (pref1[r] - (pref1[l] * pow1[len]) % MOD1 + MOD1) % MOD1;
                long long h2 = (pref2[r] - (pref2[l] * pow2[len]) % MOD2 + MOD2) % MOD2;
                unsigned long long key = (static_cast<unsigned long long>(static_cast<uint32_t>(h1)) << 32) |
                                         static_cast<uint32_t>(h2);
                ++freq[key];
            }

            for (const auto& [_, count] : freq) {
                if (count == 1) {
                    return true;
                }
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLen(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
