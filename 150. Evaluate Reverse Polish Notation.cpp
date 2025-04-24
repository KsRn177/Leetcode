class Solution {
public:
int S_stoi(const std::string& str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;
    
    // Handle empty string
    if (str.empty()) {
        return 0;
    }
    
    // Skip whitespace
    while (i < str.size() && isspace(str[i])) {
        i++;
    }
    
    // Handle sign
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    while (i < str.size() && isdigit(str[i])) {
        int digit = str[i] - '0';
        
        // Check for overflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        
        result = result * 10 + digit;
        i++;
    }
    
    return sign * result;
}

     int evalRPN(vector<string>& tokens)
    {
        stack <int> STK;
        for ( int i = 0; i < tokens.size(); i++)
        {
            if ( tokens[i] != "+" && tokens[i] != "-" &&
            tokens[i] != "*" && tokens[i] != "/")
            {
                STK.push(S_stoi(tokens[i]));
            }

            if (tokens[i] == "+")
            {

                    int b = STK.top();
                    STK.pop();
                    int a = STK.top();
                    STK.pop();
                    
                    STK.push(a+b);
            }
            if (tokens[i] == "-")
            {
                   int b = STK.top();
                    STK.pop();
                    int a = STK.top();
                    STK.pop();
                    
                    STK.push(a-b);
            }
            if (tokens[i] == "*")
            {
                    int b = STK.top();
                    STK.pop();
                    int a = STK.top();
                    STK.pop();
                    
                    STK.push(a*b);
            }
            if (tokens[i] == "/")
            {
                int b = STK.top();
                STK.pop();
                int a = STK.top();
                STK.pop();
                
                STK.push(a/b);
               
            }

        }
        return STK.top();
        
    }

};
