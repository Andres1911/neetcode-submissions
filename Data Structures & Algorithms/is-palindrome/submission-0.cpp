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
        cout<<s<<"\n";
        int right = s.length() - 1;
        int left = 0;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
