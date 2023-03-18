#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	
	int cnt = 0;

	while (B > A)
	{
		// cout << "A: " << A << " B: " << B << endl;
		cnt++;
		if (B%10 == 1)		// if B has the end number of 1  (ex) 81 becomes 8
		{
			B = B/10;
		}
		else if (B%2 == 0)	// otherwise, it has to be divisible by 2
		{
			B = B/2;
		}
		else				// imagine starting with 266, then 133, and A is not 133, cannot make it
		{
			cout << -1;
			return 0;
		}
	}

	if (A == B)
	{
		cout << cnt+1;
	}
	else
	{
		cout << -1;
	}
}