class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        int max_val = 1500;

        vector<int> mult_count(max_val + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            for (int m = f; m <= max_val; m += f) {
                mult_count[m]++;
            }
        }

        vector<int> free_gain(n, 0);
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            free_gain[i] = mult_count[f] - 1;
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            if (items[a][0] != items[b][0]) {
                return items[a][0] < items[b][0];
            }
            return items[a][1] < items[b][1];
        });

        const int INF = 1e9;
        vector<int> dp(budget + 1, -INF);
        dp[0] = 0;

        for (int idx : order) {
            int price = items[idx][1];
            int gain = free_gain[idx];

            for (int b = budget; b >= price; --b) {
                if (dp[b - price] != -INF) {
                    dp[b] = max(dp[b], dp[b - price] + 1 + gain);
                }
            }

            for (int b = price; b <= budget; ++b) {
                if (dp[b - price] != -INF) {
                    dp[b] = max(dp[b], dp[b - price] + 1);
                }
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};
