class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_struct;
        unordered_map<char, char> dictionnary;
        dictionnary['['] = ']';
        dictionnary['{'] = '}';
        dictionnary['('] = ')';

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack_struct.push(c);
            }

            if (c == ')' || c == '}' || c == ']') {
                if (stack_struct.size() == 0 || dictionnary[stack_struct.top()] != c) {
                    return false;
                } else {
                    // If it matches, safely pop it now
                    stack_struct.pop(); 
                }

            }
        }
        return stack_struct.size() == 0;
    }
};
