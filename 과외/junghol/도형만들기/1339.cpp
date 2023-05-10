#include <iostream>

using namespace std;

void printMatrix(const int n)
{
    if (n < 1 || n > 100 || n%2 != 1)
    {
        cout << "INPUT ERROR";
        return;
    }
    
    // 1. init matrix
    char ** matrix = new char*[n+1];
    for (int i = 0; i < n+1; ++i)
    {
        matrix[i] = new char[n+1];
    }
    
    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < n+1; ++j)
        {
            matrix[i][j] = ' ';
        }
    }

    // 2. fill it 
    int start = n/2 + 1;
    int cnt = 0;
    char c = 'A';
    for (int col = start; col > 0; --col)
    {
        for (int row = start-cnt; row <= start + cnt; ++row)
        {
            matrix[row][col] = c++;
            if (c > 'Z')
                c = 'A';
        }
        cnt++;
    }

    // 3. print
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < n+1; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    printMatrix(n);

}