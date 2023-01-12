#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node_of_IC
{
  int Value;
  Node_of_IC* NEXT_POS;

  Node_of_IC(int Value, Node_of_IC* NEXT_POS = 0)
    : Value(Value), NEXT_POS(NEXT_POS) {}
};

void Left_Insertion(Node_of_IC* Header, int Value);

void Right_Insertion(Node_of_IC*& Header, int Value);

void Left_Rotation(Node_of_IC* Header);

void Right_Rotation(Node_of_IC*& Header);

int main()
{
    int N;
    int Value;
    char COMMANDS[3];

    Node_of_IC* Header = new Node_of_IC(0);
    Node_of_IC* Pointer;

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> COMMANDS;
        if(COMMANDS[1] == 'i'){
            cin >> Value;
            if(COMMANDS[0] == 'r') Right_Insertion(Header, Value);
            if(COMMANDS[0] == 'l') Left_Insertion(Header, Value);
        }
        else if(COMMANDS[1] == 'r' && Header->NEXT_POS != 0)
        {
            if(COMMANDS[0] == 'r') Right_Rotation(Header);
            if(COMMANDS[0] == 'l') Left_Rotation(Header);
        }
    }
    
    if(Header->NEXT_POS != 0){
        Pointer = Header->NEXT_POS;
        do{
            Left_Rotation(Header);
            cout << Header->NEXT_POS->Value << endl;
        }while(Header->NEXT_POS != Pointer);
    }
}

void Left_Insertion(Node_of_IC* Header, int Value)
{
    if(Header->NEXT_POS == 0)
    {
        Header->NEXT_POS = new Node_of_IC(Value);
        Header->NEXT_POS->NEXT_POS = Header->NEXT_POS;
    }
    else Header->NEXT_POS->NEXT_POS = new Node_of_IC(Value, Header->NEXT_POS->NEXT_POS);
}

void Right_Insertion(Node_of_IC*& Header, int Value)
{
    Left_Insertion(Header, Value);
    Header->NEXT_POS = Header->NEXT_POS->NEXT_POS;
}

void Left_Rotation(Node_of_IC* Header)
{
    Header->NEXT_POS = Header->NEXT_POS->NEXT_POS;
}

void Right_Rotation(Node_of_IC*& Header)
{
    Node_of_IC* pointer = Header->NEXT_POS;
    while(Header->NEXT_POS->NEXT_POS != pointer) Left_Rotation(Header);
}