class Solution {
public:
    // If token is a number, push to stack
    // If it's an operation, pop the last two elements of the stack, do the operation, and put result back into the stack
    // return last element of the stac

    int evalRPN(vector<string>& tokens) {
        stack<int> calculator;
        unordered_map<string, function<double(int, int)>> ops;
        ops["+"] = [](int a, int b) { return a + b; };
        ops["-"] = [](int a, int b) { return a - b; };
        ops["*"] = [](int a, int b) { return a * b; };
        ops["/"] = [](int a, int b) { 
            return a / b; 
        };

        for (string token : tokens) {
            if (ops.contains(token)) {
                int b = calculator.top();
                calculator.pop();
                int a = calculator.top();
                calculator.pop();
                int result = ops[token](a, b);
                //cout<<"Performing op with "<<a<<" and "<<b<<" with token "<<token<<"\n";
                calculator.push(result);
            }
            else {
                calculator.push(stoi(token));
                //cout<<"Pushing int: "<<token<<"\n";
            }
        }
        return calculator.top();
    }
};
