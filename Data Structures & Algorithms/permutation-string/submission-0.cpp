class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int charMap[26] = {0};
        for (char c : s1) {
            int val = c - 'a';
            charMap[val]++;
        }

        int left = 0;
        int currMap[26] = {0};
        for (int i = 0; i < s2.length(); i++) {
            int val = s2[i] - 'a';
            currMap[val]++;
            //cout << "Current letter: " << s2[i] << "\nCurrent value: " << val << '\n';
            // cout << "Current letter: " << s2[i] << "\nCurrent count: " << currMap[val] << '\n';
            int disc_val = s2[left] - 'a';
            //cout << "Condition: " << (charMap[val] - currMap[val]) << "\n";
            while (charMap[val] - currMap[val] < 0) {
                currMap[disc_val]--;
                // cout << "Discarded letter: " << s2[left] << "\nDiscarded value: " << disc_val << '\n';
                left++;
                disc_val = s2[left] - 'a';
            }

            if (i - left + 1 == s1.length()) {
                return true;
            }
        }
        return false;
    }
};
