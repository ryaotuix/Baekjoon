#include <bits/stdc++.h>

using namespace std;

string pat = "____";
string line1 = "\"재귀함수가 뭔가요?\"";
string line2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string line3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string line4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string line5 = "라고 답변하였지.";
string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";

int n;  // end base case

void printPat(int x)
{
    for (int i = 0; i < x; i++)
        cout << pat;
}

void printRec(int x)
{
    // base case
    if (x == n)
    {
        printPat(x);
        cout << line1 << endl;
        printPat(x);
        cout << answer << endl;
        printPat(x);
        cout << line5 << endl;
        return;
    }

    printPat(x);
    cout << line1 << endl;
    printPat(x);
    cout << line2 << endl;
    printPat(x);
    cout << line3 << endl;
    printPat(x);
    cout << line4 << endl;

    printRec(x+1);

    printPat(x);
    cout << line5 << endl;
}

int main()
{
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    printRec(0);
}