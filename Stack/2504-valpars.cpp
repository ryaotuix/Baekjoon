#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<char> p;
    
    string input;
    cin >> input;
    int temp = 1;
    int res = 0;

    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] == '(')
        {
            temp *= 2;
            p.push(input[i]);
        }
        else if (input[i] == '[')
        {
            temp *= 3;
            p.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (p.empty() || p.top() != '(')
            {
                cout << 0 << endl;
                return 0;
            }

            if (input[i-1] == '(')
            {
                res += temp;
            }
            temp /= 2;
            p.pop();
        }
        else
        {
            if (p.empty() || p.top() != '[')
            {
                cout << 0 << endl;
                return 0;
            }

            if (input[i-1] == '[')
            {
                res += temp;
            }
            temp /= 3;
            p.pop();
        }
        //cout << "current : " << input[i] << res << endl;
    }

    // 마지막 !! 안빌수도 있다 (())[[] 같은거
    if (!p.empty())
    {
        cout << 0;
        return 0;
    }

    cout << res << endl;
    return 0;

}

int getsum(stack<int> s)
{
  int res =0;
  while (!s.empty())
  {
    res += s.top();
    s.pop();
  }
  return res;
}

void printStack(stack<int> s)
{
    cout << "My s is :";
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  cout << endl;
}


void printStack(stack<char> s)
{
    cout << "My pars is :";
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
}

void printSum(stack<int> s)
{
    cout << "My Sums is :";
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  cout << endl;
}


/*
my algorithm
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string in;
  cin >> in;

  stack<int> sums; // store each closed stack's value
  stack<char> pars; // store pars
  stack<int> s; // temporary stack until pars not empty

  int i = 0;
  while (i < in.length())
  {
    // cout << "current par is " << in[i] << endl;
    

    // 1. 두개의 괄호 받기
    char p1 = in[i];
    char p2 = in[i+1];
    bool flag;

    // 2. () 나 [] 면 i 는 2올려주고 s에는 알맞은 값 넣어주기
    if (p1=='(')
    {
      if (p2==')') // 2.
      {
        i += 2;
        s.push(2);
        // printStack(pars);
        // printStack(s);
        // printSum(sums);
        // cout <<endl;
        continue;
      }
      else
      {
        pars.push(p1);
        i++;
      }
    }
    else if (p1=='[')
    {
      if (p2==']') // 3.
      {
        i += 2;
        s.push(3);
        // printStack(pars);
        // printStack(s);
        // printSum(sums);
        // cout <<endl;
        continue;
      }
      else
      {
        pars.push(p1);
        i++;
      }
    }
    else if (p1==')')
    {
      if (pars.top() != '(')
      {
        cout << 0 << endl;
        return 1;
      }
      else
      {
        pars.pop();
        flag = (pars.empty()) ? true : false;
        i++;
      }

      if (flag) // par is empty
      {
            int t = 0;
            while (!s.empty())
            {
                t += s.top(); s.pop();
            }
            sums.push(t*2);
      }
      else 
      {
        int add = s.top() * 2; s.pop();
        s.push(add);
      }
    }
    else
    {
      if (pars.top() != '[')
      {
        cout << 0 << endl;
        return 1;
      }
      else
      {
        pars.pop();
        flag = (pars.empty()) ? true : false;
        i++;
      }

      if (flag) // par is empty
      {
            int t = 0;
            while (!s.empty())
            {
                t += s.top(); s.pop();
            }
            sums.push(t*3);
      }
      else 
      {
        int add = s.top() * 3; s.pop();
        s.push(add);
      }
    }
    
    // printStack(pars);
    // printStack(s);
    // printSum(sums);
    // cout <<endl;
  }

  int res = 0;
  while(!sums.empty())
  {
    res += sums.top();
    sums.pop();
  }

    cout << res << endl;
}
*/