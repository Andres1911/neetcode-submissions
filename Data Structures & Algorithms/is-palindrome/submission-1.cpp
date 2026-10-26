class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(
        std::remove_if(s.begin(), s.end(), [](unsigned char c) { 
            return !std::isalnum(c); 
        }), 
        s.end()
    );

    // 2. Convert the remaining string to lowercase
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { 
        return std::tolower(c); 
    });
        int right = s.length() - 1;
        int left = 0;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (left > right || tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};
