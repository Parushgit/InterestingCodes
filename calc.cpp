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
        int result;
        expression = expression + '.';
        for(int i = 0; i < expression.length(); i++) {
            if (isdigit(expression[i])) {
                num += expression[i];
            }
            else {
                if (sign == '*') {
                    if (!stk.empty()) {
                        int a = stk.top();
                        stk.pop();
                        stk.push(a * stoi(num));
                    }
                }
                else if (sign == '+') {
                    stk.push(stoi(num));
                }
                num = "";
                sign = expression[i];
            }
        }

        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};

int main() {
    Problem1 *obj = new Problem1;
    string expression = "20+20+20*2*30+10*2";
    cout<<obj->eval(expression)<<endl;
    return 0;
}