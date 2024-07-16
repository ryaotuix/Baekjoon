#include <bits/stdc++.h>

using namespace std;

int MAX = 8 + 1;

vector<vector<int>> primes(MAX,vector<int>());
// primes[자릿수][] prime numbers

int n;

bool isPrime(int n) {
    // 1과 0은 소수가 아닙니다.
    if (n <= 1) {
        return false;
    }

    // 2와 3은 소수입니다.
    if (n <= 3) {
        return true;
    }

    // n이 2 또는 3의 배수이면 소수가 아닙니다.
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // n이 2와 3의 배수가 아닌 경우
    // n이 소수인지를 판별하기 위해 6k ± 1 형태의 수를 확인합니다.
    // 여기서 k는 자연수입니다.
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    // 위의 조건들을 모두 통과하면 n은 소수입니다.
    return true;
}

void input()
{
    cin >> n;
    primes[1].push_back(2);
    primes[1].push_back(3);
    primes[1].push_back(5);
    primes[1].push_back(7);

    // i는 이번자리
    for (int i = 2; i < MAX; i++)
    {
        // 지난 자리 소수들 순회
        int len = primes[i-1].size();
        for (int j = 0; j < len; j++)
        {
            int prev = primes[i-1][j];

            for (int k = 1; k <= 9; k++)
            {
                int curr = prev*10 + k;    // 이번 숫자 =  지난 소수 * 10 + (1 ~ 9)
                bool isP = isPrime(curr);

                // 이숫자가 소수면 넣기
                if (isP)
                {
                    primes[i].push_back(curr);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    for (int i = 0; i < primes[n].size(); i++)
    {
        cout << primes[n][i] << "\n";
    }
}
