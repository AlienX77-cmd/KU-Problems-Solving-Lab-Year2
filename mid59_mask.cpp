#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

int NUM;
int XX[1205];

bool Sorting(int A, int B);

int main()
{
    cin >> NUM;
    vector<int> Competitor;

    int i;
    for(i = 0; i < 4*NUM; i++){
    cin >> XX[i];
    Competitor.push_back(i);
    }

    vector<int> Round_1(Competitor.begin(), Competitor.begin() + NUM);
    vector<int> Round_2(Competitor.begin() + NUM, Competitor.begin() + (2*NUM));
    vector<int> Round_3(Competitor.begin() + (2*NUM), Competitor.begin() + (3*NUM));
    vector<int> Round_4(Competitor.begin() + (3*NUM), Competitor.begin() + (4*NUM));

    sort(Round_1.begin(),Round_1.end(), Sorting);
    sort(Round_2.begin(),Round_2.end(), Sorting);
    sort(Round_3.begin(),Round_3.end(), Sorting);
    sort(Round_4.begin(),Round_4.end(), Sorting);

    int Lost_of_RoundA;
    int Win_of_RoundA;
    int Lost_of_RoundB;
    int Win_of_RoundB;

    if (XX[Round_1[0]] > XX[Round_2[0]])
    {
        Win_of_RoundA = Round_1[0];
        Lost_of_RoundA = Round_2[0];
    }
    else
    {
        Win_of_RoundA = Round_2[0];
        Lost_of_RoundA = Round_1[0];
    }

    if (XX[Round_3[0]] > XX[Round_4[0]])
    {
        Win_of_RoundB = Round_3[0];
        Lost_of_RoundB = Round_4[0];
    }
    else
    {
        Win_of_RoundB = Round_4[0];
        Lost_of_RoundB= Round_3[0];
    }

    if (XX[Win_of_RoundA] > XX[Win_of_RoundB]) cout << Win_of_RoundA + 1 << " ";
    else cout << Win_of_RoundB + 1 << " ";

    if (XX[Win_of_RoundA] < XX[Win_of_RoundB]) cout << Win_of_RoundA + 1 << " ";
    else cout << Win_of_RoundB + 1 << " ";

    cout << Lost_of_RoundA + 1 << " " << Lost_of_RoundB + 1;

  return 0;

}

bool Sorting(int A, int B)
{
  return XX[B] < XX[A];
}