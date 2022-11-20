#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

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
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
}

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
    // 0. pars 가 비었으면 sum 에 s의 합을 넣기
    if (pars.empty())
    {
      while (!s.empty())
      {
        sums.push(s.top()); s.pop();
      }
    }

    // 1. 두개의 괄호 받기
    char p1 = in[i];
    char p2 = in[i+1];

    // 2. () 나 [] 면 i 는 2올려주고 s에는 알맞은 값 넣어주기
    if (p1=='(')
    {
      if (p2==')') // 2.
      {
        i += 2;
        s.push(2);
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
        cout << "not complete" << endl;
        cout << 1 << endl;
        return 1;
      }
      else
      {
        int add = s.top() * 2; s.pop();
        s.push(add);
        i++;
      }
    }
    else
    {
      if (pars.top() != '[')
      {
        cout << "not complete" << endl;
        cout << 1 << endl;
        return 1;
      }
      else
      {
        int add = s.top() * 2; s.pop();
        s.push(add);
        i++;
      }
    }
    cout << "current sums stack is :" <<endl;
    printStack(sums);
  }

  int res = 0;
  while(!sums.empty())
  {
    res += sums.top();
    sums.pop();
  }

}
