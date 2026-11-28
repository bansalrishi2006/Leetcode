class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        long long cheapest = LLONG_MAX;
        int maxFactor = 0;

        for (const auto& item : items) {
            cheapest = min(cheapest, static_cast<long long>(item[1]));
            maxFactor = max(maxFactor, item[0]);
        }

        vector<long long> freq(maxFactor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<long long> multCount(maxFactor + 1, 0);
        for (int d = 1; d <= maxFactor; ++d) {
            for (int m = d; m <= maxFactor; m += d) {
                multCount[d] += freq[m];
            }
        }

        map<long long, long long> costToBoostedUnits;
        long long remBudget = budget;

        for (const auto& item : items) {
            int f = item[0];
            long long price = item[1];
            long long gain = multCount[f] - 1;
            if (gain > 0 && price <= 2LL * cheapest) {
                costToBoostedUnits[price] += gain;
            }
        }

        long long totalItems = 0;
        for (const auto& [price, units] : costToBoostedUnits) {
            long long buy = min(units, remBudget / price);
            totalItems += 2LL * buy;
            remBudget -= buy * price;
        }

        totalItems += remBudget / cheapest;
        return static_cast<int>(totalItems);
    }
};
