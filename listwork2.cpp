#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ValueType;

struct ListNode
{
  ValueType v;
  ListNode* next;

  ListNode(ValueType v, ListNode* next=0)
    : v(v), next(next) {}
};

void InsertFront(ListNode* header, ValueType v)
{
    ListNode* tmp = header->next;
    header->next = new ListNode(v);
    header->next->next = tmp;
}

void Append(ListNode* header, ValueType v)
{
    ListNode* tmp = header;
    while (tmp->next != 0)
    {
        tmp = tmp->next;
    }
    tmp->next = new ListNode(v);
}

void Delete(ListNode*& header, int index){
    index = index-1;
    ListNode* p = header;
    ListNode* q;
    if(p == 0) return;
    for(int i=0; i<index;i++){
        if(p->next != 0)
          p = p->next;
        else return;
    }
    if(p->next == 0)
    {
        q = 0;
    }
    else
    {
        q = p->next->next;
    }
    delete p->next;
    p->next = q;
}

void Free(ListNode*& header)
{
    ListNode* tmp = header->next;
    ListNode* tmp2;
    while(tmp->next != 0){
        tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
}


int main()
{
    ListNode* header = new ListNode(0);
    header->next = 0;
    int N, V;
    char command;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> command >> V;
        if(command == 'I'){
            InsertFront(header, V);
        }
        else if(command == 'A'){
            Append(header, V);
        }
        else{
            Delete(header, V);
        }
        
    }
    while(header->next != 0){
        cout << header->next->v << endl;
        header = header->next;
    }
}