#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Problem1 {
public:
    int eval(string expression) {
        stack<int> stk;
        char sign = '+';
        string num;
        for(int i = 0; i <= expression.length(); i++) {
            if (i == expression.length()) {
                if (sign == '+') {
                    return num + stk.top();
                }
                else if (sign == '*')
                    return num * stk.top();
            }
            if (isdigit(expression[i])) {
                num += expression[i];
            }
            else {
                if (sign == '*') {
                    if (!stk.empty()) {
                        int a = stk.top();
                        stk.pop();
                        stk.push(a * num);
                    }
                }
                else if (sign == '+') {
                    stk.push(stoi(num));
                }
                sign = expression[i];
            }
        }
        return -1;
    }
}

int main() {
    Problem1 *obj = new Problem1;
    string expression = "20*3+6";
    cout<<obj->eval(expression)<<endl;
    return 0;
}