class Solution {
public:
    int calculate(string s) {

        stack<int> nums;
        int num = 0;
        char opt = '+';

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            
            // if digit, get digit
            if (isdigit(c))
            {
                num = num*10 + (c - '0');
            }  

            // if new operator or last digit
            if (!isdigit(c) && !iswspace(c) || i == s.length()-1)
            {
                if (opt == '+')
                {
                    nums.push(num);
                }
                else if (opt == '-')
                {
                    nums.push(-num);
                }
                else if (opt == '*')
                {
                    int before = nums.top(); nums.pop();
                    nums.push(before * num);
                }
                else if (opt == '/')
                {
                    int before = nums.top(); nums.pop();
                    nums.push(before / num);
                }


                // update opt and num
                opt = c;
                num = 0;
            }
        }

        int res = 0;
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};