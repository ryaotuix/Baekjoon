#include <iostream>

using namespace std;

char convertToValid(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c;
    else
    {
        return convertToValid(c - 26);
    }
}

void printTriangle(const int n)
{
    // Init Matrix n+1 x n+1
    char ** matrix = new char * [n+1];
    for (int i = 0; i < n+1; i++)
    {
        matrix[i] = new char[n+1];
    }
    // Fill it with empty char (O(n2))
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            matrix[i][j]= ' ';
        }
    }

    // Solve
    int row = 1;
    int col = n;
    int cnt = 1;
    char put = 'A';
    while (col != n || row != n)
    {
        // cout << row << ' ' << col << convertToValid(put) << "\n";
        
        matrix[row][col] = convertToValid(put);
        
        row++;
        col--;
        put++;

        if (col < cnt)
        {
            cnt++;
            row = cnt;
            col = n;
        }
    }
    matrix[row][col] = convertToValid(put);

    // Print
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < n+1; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void printTriangle2(const int n)
{
     // Init Matrix n+1 x n+1
    char ** matrix = new char * [n+1];
    for (int i = 0; i < n+1; i++)
    {
        matrix[i] = new char[n+1];
    }
    // Fill it with empty char (O(n2))
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            matrix[i][j]= ' ';
        }
    }

    // solve
    char input = 'A';
    int i, j, k;
    for (i = 1; i < n+1; ++i)
    {
        for (j = i, k = n; j <= n; j++, k--)
        {
            matrix[j][k] = input++;
            if (input > 'Z')
                input = 'A';
        }
    }

    // Print
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
    printTriangle2(n);
}


// Question!
// Why did printTriangle didn't work?