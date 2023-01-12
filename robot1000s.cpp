#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    char INPUT[102];
    int N;

    int NUB_COUNTING[4];
    int First_Reduction = 0;
    int Second_Reduction = 2;

    bool TheBestChoice = true;

    cin >> INPUT;
    cin >> N;

    NUB_COUNTING[0] = 0;
    NUB_COUNTING[1] = 0;
    NUB_COUNTING[2] = 0;
    NUB_COUNTING[3] = 0;

    int n;
    for(n = 0; INPUT[n] != '\0'; n++){
        switch (INPUT[n])
        {
        case 'N':
            NUB_COUNTING[0] = NUB_COUNTING[0] + 1;
            break;
        case 'S':
            NUB_COUNTING[1] = NUB_COUNTING[1] + 1;
            break;
        case 'E':
            NUB_COUNTING[2] = NUB_COUNTING[2] + 1;
            break;
        case 'W':
            NUB_COUNTING[3] = NUB_COUNTING[3] + 1;
            break;
        }
    }


    if(NUB_COUNTING[1] < NUB_COUNTING[0]) First_Reduction = 1;
    if(NUB_COUNTING[3] < NUB_COUNTING[2]) Second_Reduction = 3;

    while(N != 0){

        if (NUB_COUNTING[First_Reduction] >= 1){
            NUB_COUNTING[First_Reduction] = NUB_COUNTING[First_Reduction ] - 1;
            N--;
        }


        else if (NUB_COUNTING[Second_Reduction ] >= 1){
            NUB_COUNTING[Second_Reduction ] = NUB_COUNTING[Second_Reduction ] - 1;
            N--;
        }

        else if(TheBestChoice == true){
            //if (First_Reduction  == 1) First_Reduction = 0;
            //else First_Reduction = 1;
            First_Reduction = (First_Reduction == 1)? 0:1;

            //if (Second_Reduction  == 2) Second_Reduction  == 3;
            //else Second_Reduction  == 2;
            Second_Reduction = (Second_Reduction == 2)? 3:2;

            TheBestChoice = false;
        }

        if (NUB_COUNTING[0] + NUB_COUNTING[1] + NUB_COUNTING[2] + NUB_COUNTING[3] == 0) break;
    }

    cout << ( abs(NUB_COUNTING[0] - NUB_COUNTING[1]) + abs(NUB_COUNTING[2] - NUB_COUNTING[3]) ) * 2 << endl;
}