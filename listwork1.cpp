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
    ListNode* temp = header->next;
    header->next = new ListNode(v);
    header->next->next = temp;
}

void Delete(ListNode*& header, int index){
    index--;
    ListNode* p = header;
    ListNode* q;
    if(p == 0) return;
    for(int i=0; i<index; i++){
        if(p->next != 0)
          p = p->next;
        else return;
    }
    
    if(p->next == 0){
        q = 0;
    }
    else{
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
    int N, V;
    char cmd;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> cmd >> V;
        if(cmd == 'I'){
            InsertFront(header, V);
        }else
        {
            Delete(header, V);
        }
        
    }
    while(header->next != 0){
        cout << header->next->v << endl;
        header = header->next;
    }
}