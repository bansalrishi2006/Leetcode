class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [](int num) {
            int totalSum = 0;
            while (num > 0) {
                int d = num % 10;
                num /= 10;
                totalSum += d * d;
            }
            return totalSum;
        };

        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
