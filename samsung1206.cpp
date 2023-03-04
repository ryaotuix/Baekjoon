#include <bits/stdc++.h>

using namespace std;

// 양옆 2개씩 0으로 만들어주기
int buildings[2 + 1000 + 2];


int jomangkwon(int numBuildings)
{
    // building array initalize as 0
    memset(buildings, 0, sizeof(buildings));
    // read information about buildings STARTING AT IND 2
    for (int i = 0+2; i < numBuildings+2; ++i) 
        cin >> buildings[i];

    int jomang = 0;

    for (int i = 2; i < numBuildings + 2; ++i)
    {
        // find the talles building next to neighbors
        int neighbors = max(max(buildings[i-2], buildings[i-1]), max(buildings[i+1], buildings[i+2]));

        // if there is no neighboring building taller than current building,
        if (neighbors < buildings[i])
        {
            jomang += buildings[i] - neighbors;
        }
    }

    return jomang;
}

int main()
{

    int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T; /// 이 병신같은 부분!!!!!!!!!!!!!!!!!!!
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int numBuildings; cin >> numBuildings;
        int res = jomangkwon(numBuildings);
        cout << "#" << test_case << " " << res << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.

}