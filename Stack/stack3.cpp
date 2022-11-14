#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() { // 균형잡힌 세상 4949

  // 동기화 해제 해서 cin cout 빠르게 해주는것들
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  queue<string> answers;

  while(true) {
    string s;
    getline(cin, s);

    if (s == ".") break; //

    stack<char> pars;

    bool extraClosing = false;

    for (int i=0; i<s.length(); i++) {
      // 여는 괄호면
      if ((s[i] == '(') || (s[i] == '['))
      {
        pars.push(s[i]);
      }
      else if (s[i] == ')') // ')' 일때
      {
        if (!pars.empty() && pars.top() == '(') pars.pop();
        else
        {
          extraClosing = true;
          break;
        }
      }
      else if (s[i] == ']') // ']' 일때
      {
        if (!pars.empty() && pars.top() == '[') pars.pop();
        else {
          extraClosing = true;
          break;
        }
      }
      else // 괄호가 아닐때
      {
        continue;
      }
    }

    if (pars.empty() && !extraClosing) answers.push("yes");
    else answers.push("no");
  }

  // printing the answers
  while (!answers.empty()) {
    cout << answers.front() << endl;
    answers.pop();
  }

  return 0;
}
