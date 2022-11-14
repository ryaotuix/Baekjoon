#include <iostream>
#include <stack>

using namespace std;



int main() { // 괄호 9012

  // 동기화해서 cin cout 빠르게 해주는것들
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int sentences;
  cin >> sentences;

  string * answers = new string[sentences];
  int ind = 0;

  for (int i=0; i<sentences; i++) {
    bool answered = false;
    stack<char> pars; // initialize parenthesis stack

    string input;
    cin >> input;

    for (int j =0; j<input.length(); ++j) {
      if (input[j] == '(') {
        pars.push(input[j]);
      }
      else { // if input[j] == ')'
        if (pars.empty()) {
          answers[ind++] = "NO";
          answered = true;
          break;
        } else {
          pars.pop();
        }
      }
    }

    if (!answered) {
      if(pars.empty()) {
        answers[ind++] = "YES";
      } else {
        answers[ind++] = "NO";
      }
    }

  }


  for (int i=0; i<sentences; i++) {
    cout << answers[i] << endl;
  }
  return 0;
}
