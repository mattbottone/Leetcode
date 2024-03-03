class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        std::string test;
        for (int i = 0; i < s.length(); i++){
            if (stack.empty()) {
                stack.push(s[i]);
            }
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            else {
                test = string(1, stack.top()) + s[i];

                if (test == "()" || test == "{}" || test == "[]"){
                    stack.pop();
                }
                else {
                    cout << test;
                    return false;
                }
            }
        }
        if (stack.size() > 0) return false;
        else return true;
    }
};
