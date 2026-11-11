class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ban = *max_element(piles.begin(), piles.end());
        int left = 1;
        int right = max_ban;

        while(left < right) {
            int mid_point = (left + right)/2;
            if (hoursTaken(mid_point, piles) <= h) {
                right = mid_point;
            }
            else {
                left = mid_point + 1;
            }
        }
        
        return left;
    }

    long hoursTaken(int rate, vector<int>& piles) {
        long hours = 0;
        for (int pile : piles) {
            hours += (pile + rate - 1) / rate;
        }
        return hours;
    }
};

/*

Wait I can just say: ok the best is simply to pick max piles[i], that's my initial rate, then if I half it, do I still finish everything within the time?

How to eat everything efficiently? Simple approach, divide piles[i] by k and increase the result, if 0, then make it 1. O(n)

If yes: keep halving
If not: Increase to 3/4 and so on...

Stop until it's 1 k away from the answer (i.e. say k = 3)
Like a bunch of yes, yes, no, yes questions

So O(n*log(n))

*/


