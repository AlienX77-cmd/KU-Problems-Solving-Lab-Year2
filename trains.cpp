#include <iostream>
#include <stdio.h>
#include <cstdlib>

typedef int ValueType;

using namespace std;

struct Train
{
  ValueType ID_Train;
  Train* next;

  Train(ValueType ID_Train, Train* next=0)
    : ID_Train(ID_Train), next(next) {}
};

void ADD(Train* tail, ValueType ID_Train)
{
    tail->next->next = new Train(ID_Train);
    tail->next = tail->next->next;
}

void MOVE(Train* src_header, Train* src_tail, Train* dst_tail)
{
    dst_tail->next->next = src_header->next;
    if(src_header->next != 0){
        dst_tail->next = src_tail->next;
    }
    src_header->next = 0;
    src_tail->next = src_header;
}

int main()
{
    Train* headers[100000];
    Train* tails[100000];
    
    int i;
    for(i = 0; i <= 100000-1; i++){
        headers[i] = new Train(0);
        tails[i] = new Train(0, headers[i]);
    }
    
    int M, X, Y, j;
    char cmd;
    cin >> M;
    for(j = 0; j < M; j++){
        cin >> cmd >> X >> Y;
        
        if(cmd == 'N') ADD(tails[Y-1], X);
        else MOVE(headers[X-1], tails[X-1], tails[Y-1]); 
        
    }
    
    int k;
    for(int k = 0; k<100000; k++){
        while (headers[k]->next != 0)
        {
            headers[k] = headers[k]->next;
            cout << headers[k]->ID_Train << endl;
        }
    }
    return 0;
}