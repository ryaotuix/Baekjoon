#include <bits/stdc++.h>

using namespace std;



stack<string> st;

void putIn(string s)
{
    int ind = 0;
    string temp = "";
    while (ind < s.size())
    {
        char curr = s[ind];

        // 1. if current is slash, 
        if (curr == '/')
        {
            // check string temp

            // . -> do nothing
            if (temp == ".")
            {
                
            }
            // .. -> pop
            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            // other directory name -> push
            else if (temp.length() != 0)
            {
                st.push(temp);
            }

            // refresh string temp
            temp = "";
        }

        // 2. otherwise, get the 
        else
        {
            temp += curr;
        }

        ind++;
    }

    // if there is remaining string
    if (temp.length() != 0)
    {
        if (temp == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else if (temp == ".")
            // do nothing
        else
            st.push(temp);
    }    
}

void checkStack()
{
    if (st.empty())
    {
        cout << "EMPTY" << endl;
        return;
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

string simplifyPath(string s)
{
    putIn(s);

    string res = "/";

    // now , move it to another stack
    stack<string> st2;

    // start with /
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
        st2.push("/");
    }
    // do not end with /
    if (st2.size() > 1 && st2.top() == "/")
        st2.pop();
    
    while (!st2.empty())
    {
        res += st2.top(); st2.pop();
    }

    return res;
}


int main()
{
    // string s = "/a/b///c/.././d/../f";
    string s = "/home/";

    cout << simplifyPath(s);   

}