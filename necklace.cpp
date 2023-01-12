#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node_of_Beads
{
  int NUMBER;
  Node_of_Beads* NEXT_BEADS;

  Node_of_Beads(int NUMBER, Node_of_Beads* NEXT_BEADS=0)
    : NUMBER(NUMBER), NEXT_BEADS(NEXT_BEADS) {}
};


int main()
{
    Node_of_Beads* HEADER[300000];
    bool NeckLaces[300000];
    Node_of_Beads* Pointer;
    int N;
    int A, B;
    cin >> N;

    int i = 1;
    while (i <= N){
        NeckLaces[i] = true;
        HEADER[i] = new Node_of_Beads(0);
        HEADER[i]->NEXT_BEADS = new Node_of_Beads(i);
        
        i++;
    }
    
    int j = 0;
    while (j < (N-1)){
        cin >> A >> B;
        NeckLaces[A] = false;
        Pointer = HEADER[A];
        
        do{
            Pointer = Pointer->NEXT_BEADS;
        }while(Pointer->NEXT_BEADS != 0);
        
        Pointer->NEXT_BEADS = HEADER[B]->NEXT_BEADS->NEXT_BEADS;
        HEADER[B]->NEXT_BEADS->NEXT_BEADS = HEADER[A]->NEXT_BEADS;
        
        j++;
    }
    
    int k = 1;
    while(k <= N){
        if(NeckLaces[k]){
            while (HEADER[k]->NEXT_BEADS != 0)
            {
                HEADER[k] = HEADER[k]->NEXT_BEADS;
                cout << HEADER[k]->NUMBER << ' ';
            }
            break;
        }
        
        k++;
    }

    return 0;
}