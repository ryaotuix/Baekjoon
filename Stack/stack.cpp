#include <iostream>
#include <stack>

using namespace std;

int main() { // 백준 17608 막대기
  // 동기화해서 cin cout 빠르게 해주는것들
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  stack<int> sticks;

  int numsticks;
  cin >> numsticks;

  for (int i=0; i<numsticks; i++) {
    int length;
    cin >> length;
    sticks.push(length); // add each height input to a stack
  }

  int right = sticks.top(); // this is the hieght you see from the right
  sticks.pop();

  int count = 1;
  while (!sticks.empty()) {
    if (sticks.top() > right) {
      count++;
      right = sticks.top(); // !!!!
    }

    sticks.pop(); // in C++ pop is void
  }
  cout << count;
  return 0;
}
