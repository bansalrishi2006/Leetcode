class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long current_number = 0;
        int result = 0;
        int sign = 1;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                current_number = current_number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * current_number;
                current_number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * current_number;
                current_number = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * current_number;
                current_number = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        
        result += sign * current_number;
        return result;
    }
};
