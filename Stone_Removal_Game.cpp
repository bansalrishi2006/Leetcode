class Solution {
public:
    bool canAliceWin(int n) {
        int removeCount = 10;
        bool aliceTurn = true;
        
        while (n >= removeCount && removeCount > 0) {
            n -= removeCount;
            removeCount--;
            aliceTurn = !aliceTurn;
        }
        
        return !aliceTurn;
    }
};
