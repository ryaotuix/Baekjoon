#include <bits/stdc++.h>

using namespace std;

string s = "3[a]2[bc]";

/*
// One stack approach
string decodeString(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c != ']')
            st.push(c);

        // when closing bracket
        else
        {
            string temp = "";
            int multiple = 0;
            int base = 1;

            // get temp string until [
            while(st.top() != '[')
            {
                char c2 = st.top();
                st.pop();
                temp += c2;
            }
            
            // now the top is '['
            st.pop();

            // now get the integer repetition
            while (!st.empty() && st.top() >= '0' && st.top() <= '9')
            {
                multiple += base * (st.top() - '0');
                st.pop();
                base *= 10;
            }

            cout << multiple << endl;

            string toPut  = "";
            for (int j = 0; j < multiple; j++)
            {
                toPut += temp;
            }

            // insert into the stack in reverse order
            for (int j = toPut.length() - 1; j >= 0; j--)
                st.push(toPut[j]);
        }
    }

    // after all of the iterations are done
    stack<char> st2;
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    string res = "";
    while (!st2.empty())
    {
        res += st2.top();
        st2.pop();
    }

    return res;
}
*/


/*
// using two stacks
stack<int> nums;
stack<string> strs;

string decodeString(string s)
{
    int num = 0;
    string currString = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // when the char is number
        if (isdigit(c))
        {
            num = 10*num + (c - '0');   
        }
        // when c is opening bracket        -> push and refresh num and currString
        else if (c == '[')
        {
            nums.push(num);     num = 0;
            strs.push(currString);    currString = "";
        }
        // when c is closing bracket
        else if (c == ']')
        {
            int repeat = nums.top(); nums.pop();
            string decodedString = strs.top(); strs.pop();
            for (int i = 0; i < repeat; i++)            // add decoded string from stack + (num * currString)
            {
                decodedString += currString;
            }

            currString = decodedString;
        }
        // when c is alpabet
        else
        {
            currString += c;
        }
    }

    return currString;
}
*/

int rec = 0;

string recString(string & s, int & ind)   // pass the starting index as parameter
{
    // cout << "rec: " << rec++ << " start : " << start << endl;

    int num = 0;
    string res = "";


    while (ind < s.length() && s[ind] != ']')
    {
        // 1. if not digit (alphabet)
        if (!isdigit(s[ind]))
        {
            res += s[ind];  //  -> add it to string 
            ind++;          //  -> increment the index
        }
        // 2. starting pointing at digit
        else
        {
            // 2-1. get the digit
            while (isdigit(s[ind]) && ind < s.length())
            {
                num = num * 10 + (s[ind] - '0');
                ind++;
            }

            // 2-2, now pointing at '[' 
            ind++;  // -> skip it

            string decoded = recString(s, ind);         // !!! Recursion

            // 2-3, now pointing at ']'
            ind++; // -> skip it

            // cout << "num : " << num << endl;
            for (int i = 0 ; i < num ; i++)
                res += decoded;
            cout << endl;

            num = 0;                // WHY?????
            /* When 3[a]2[bc], 2 becomes 32 */
        }
    }

    // Base Case : when we meet ']
    return res;
}

// Using recursion
string decodeString(string s)
{
    int start = 0;
    return recString(s, start);
}

int main()
{
    cout << decodeString(s);
}