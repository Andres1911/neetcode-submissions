#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;

        int totalWindow[128] = {0};
        int currWindow[128] = {0};

        for (char c : t) {
            int value = c;
            totalWindow[value]++;
        }

        int formed = 0;
        int required = t.length();
        
        int bestStart = 0;
        int bestLength = INT_MAX;

        while (right < s.length()) {
            char c = s[right];
            currWindow[c]++;
            if (currWindow[c] <= totalWindow[c]) {
                formed++;
            }

            while (formed >= required) {
                if ((right - left + 1) < bestLength) {
                    bestStart = left;
                    bestLength = right - left + 1;
                }

                char d = s[left];
                currWindow[d]--;
                if (currWindow[d] < totalWindow[d]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return bestLength == INT_MAX ? "" : s.substr(bestStart, bestLength);
    }
};
