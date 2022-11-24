#include <iostream>

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  bool flag = false; // flase then increment
  int i = 1;
  while (i != 0)
  {
    if (i == n) flag = true; // if num starts became input n decrement

    int l;
    for (l=0; l<n-i; l++)
      cout << " ";

    for (l =0; l<i; l++)
      cout << "*";

    cout << "\n";

    if (flag == false) i++;
    else i--;
  }
}
