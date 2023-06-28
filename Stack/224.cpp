#include <bits/stdc++.h>

using namespace std;

string evaluateOneParenthesis(stack<string> s)
{
    int res = 0;
    int opt = 1;
    while (!s.empty())
    {
        string k = s.top();
        s.pop();

        // change operator
        if (k == "+" || k == "-")
        {
            opt = (k == "+") ? 1 : -1;
        }
        // if digit
        else
        {
            int i = stoi(k);
            // cout << opt * i << endl;
            res += opt * i;
        }
    }

    return to_string(res);
}

int calculate(string s)
{
    // get rid of white spaces
    string newS = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            newS += s[i];
    }

    s = newS;

    // cout << "NEW STRING "  << s << endl;

    // string stack
    stack<string> st;
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // i) if c is digit
        if (isdigit(c))
        {
            temp += c;
        }

        // ii) if c is open parenthesis
        else if (c == '(')
        {
            // if it has number before push it
            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }

            temp += c;
            st.push(temp);
            temp = "";
        }

        // iii) if c is closing parenthesis
        else if (c == ')')
        {
            // if it has number before push it
            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }

            stack<string> reverse;

            while (st.top() != "(")
            {
                reverse.push(st.top());
                st.pop();
            }
            st.pop(); // get rid of "("

            string smallRes = evaluateOneParenthesis(reverse);
            st.push(smallRes);
        }

        // iv) if c is operator
        else
        {
            // if it has number before push it
            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }

            temp += c;
            st.push(temp);
            temp = "";
        }
    }

    // if last part has string remaining
    if (temp != "")
    {
        st.push(temp);
        temp = "";
    }

    // test printing
    // while (!st.empty())
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }

    stack<string> fin;
    while (!st.empty())
    {
        fin.push(st.top());
        st.pop();
    }

    string finS = evaluateOneParenthesis(fin);

    return stoi(finS);
}

int main()
{
    cout << calculate("1 + 1");
}