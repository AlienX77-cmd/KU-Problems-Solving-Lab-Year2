#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

struct Node
{
    int Data;
    int TOP;
    int LAST;
    Node *PREVIOUS = NULL;
    Node *NEXT = NULL;
    Node(int Data)
        : Data(Data) {}
};

void Int_Scanner(int &X);

void LIST_Printer(Node *HEAD);

void Line_Reverser(Node *HEAD);

void Node_Reverser(Node *HEAD);

void Last_Updater(Node *&Current_Pos, int &LastTOP, int &LastLAST);

Node *Nodes[100010];

int main()
{
    int i,j,k;
    for (i = 1; i <= 100000; i++) 
        Nodes[i] = new Node(i);
    for (j = 1; j <= 100000; j++)
    {
        Nodes[j]->TOP = 0;
        Nodes[j]->LAST = 0;
        if (j >= 2) Nodes[j]->PREVIOUS = Nodes[j - 1];
        if (j < 100000) Nodes[j]->NEXT = Nodes[j + 1];
    }

    int m; 
    int n;
    int LastI = 0;
    int TEMP;

    Int_Scanner(m);
    Int_Scanner(n);

    int mm;
    for (mm = 0; mm <= m-1; mm++)
    {
        Int_Scanner(TEMP);

        Nodes[LastI + 1]->PREVIOUS = NULL;
        Nodes[LastI + 1]->TOP = 0;
        Nodes[LastI + 1]->LAST = LastI + TEMP;

        Nodes[LastI + TEMP]->NEXT = NULL;
        Nodes[LastI + TEMP]->TOP = 0;
        Nodes[LastI + TEMP]->LAST = LastI + TEMP;

        LastI = LastI + TEMP;
    }

    Node *Current_Pos = Nodes[1];
    Current_Pos->TOP = 1;
    Node *TEMP2;

    int LastTOP = Current_Pos->TOP;
    int LastLAST = Current_Pos->LAST;

    char COMMANDS;

    int nn; 

    for (nn = 0; nn <= n-1; nn++)
    {
        scanf(" %c", &COMMANDS);

        Last_Updater(Current_Pos, LastTOP, LastLAST);

        if (Current_Pos->TOP == 0) Current_Pos->TOP = LastTOP;

        switch (COMMANDS)
        {
        case 'F':
            if (Current_Pos->NEXT != NULL)
            {
                if (Current_Pos->NEXT != NULL && Current_Pos->NEXT->NEXT == Current_Pos) Node_Reverser(Current_Pos->NEXT);
                Current_Pos = Current_Pos->NEXT;
            }
            break;
        case 'B':
            if (Current_Pos->PREVIOUS != NULL) Current_Pos = Current_Pos->PREVIOUS;
            break;
        case 'C':
            int Current_Index;

            Int_Scanner(Current_Index);
            
            if (Current_Pos->NEXT != NULL)
            {
                if (Current_Pos->NEXT->NEXT == Current_Pos) Node_Reverser(Current_Pos->NEXT);

                TEMP2 = Current_Pos->NEXT;
                Nodes[LastLAST]->TOP = TEMP2->Data;

                TEMP2->PREVIOUS = NULL;
                TEMP2->TOP = TEMP2->Data;
                TEMP2->LAST = LastLAST;

                LastLAST = Current_Pos->Data;
                Nodes[LastTOP]->LAST = LastLAST;
                Current_Pos->LAST = LastLAST;

                Last_Updater(Current_Pos, LastTOP, LastLAST);
            }

            if (Nodes[Current_Index]->NEXT != NULL || Nodes[Current_Index]->PREVIOUS == NULL) {}
            else Node_Reverser(Nodes[Current_Index]);

            if (Current_Pos->NEXT != NULL) Current_Pos->NEXT->PREVIOUS = NULL;

            Nodes[Current_Index]->TOP = LastTOP;
            Nodes[Nodes[Current_Index]->LAST]->TOP = LastTOP;
            Nodes[LastTOP]->LAST = Nodes[Current_Index]->LAST;
            Nodes[Current_Index]->PREVIOUS = Current_Pos;

            Current_Pos->NEXT = Nodes[Current_Index];
            Current_Pos = Current_Pos->NEXT;
            Last_Updater(Current_Pos, LastTOP, LastLAST);
            break;
        }

        cout << Current_Pos->Data << endl;
    }

    return 0;
}

void Int_Scanner(int &X)
{
    register int CC = getchar_unlocked();
    X = 0;
    int NEGATIVE = 0;

    for (; ( (CC < 48 || CC > 57) && CC != '-'); CC = getchar_unlocked())
        ;
    if (CC == '-')
    {
        NEGATIVE = 1;
        CC = getchar_unlocked();
    }

    for (; (CC > 47) && (CC < 58); CC = getchar_unlocked()) X = (X << 1) + (X << 3) + CC - 48;
    if (NEGATIVE) X = -X;
}

void LIST_Printer(Node *HEAD)
{
    Node *point_head = HEAD;
    while (point_head != NULL)
    {
        if (point_head->PREVIOUS != NULL) cout << " <- ";
        cout << point_head->Data;

        if (point_head->NEXT != NULL)cout << " -> ";

        point_head = point_head->NEXT;
    }
}

void Line_Reverser(Node *HEAD)
{
    Node *TEMP;
    Node *point_head = HEAD;
    while (point_head != NULL)
    {
        TEMP = point_head->NEXT;
        point_head->NEXT = point_head->PREVIOUS;
        point_head->PREVIOUS = TEMP;
        point_head = point_head->NEXT;
    }
}

void Node_Reverser(Node *HEAD)
{
    Node *pointer_HEAD = HEAD;
    Node *TEMP = pointer_HEAD->NEXT;
    pointer_HEAD->NEXT = pointer_HEAD->PREVIOUS;
    pointer_HEAD->PREVIOUS = TEMP;
}

void Last_Updater(Node *&Current_Pos, int &LastTOP, int &LastLAST)
{
    if (Current_Pos->TOP != 0)
    {
        if (Current_Pos->TOP != LastTOP) LastTOP = Current_Pos->TOP;
    }
    if (Current_Pos->LAST != 0)
    {
        if (Current_Pos->LAST != LastLAST) LastLAST = Current_Pos->LAST;
    }
}