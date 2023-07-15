#include<bits/stdc++.h>
using namespace std;
template<class t>
class node{
    public:
    t value;
    node *next;
    node(){
    next=NULL;
    }
    node(t a,node *next){
    value=a;
   this->next=next;
    }
};
template <class t>
class linklist{
node<t> *head;
int length,cur;
public:

    void init();
    linklist();
    ~linklist();
    void Insert(t a);
t Remove();
void moveToStart();
void moveToEnd();
void prev();
void next();
int Length();
int currPos();
void moveTopos(int pos);
t getvalue();
 void print();
 void Clear();
 void Append(t a);
};

template <typename t>
class Queue{
linklist <t> arr;
public:
    void enqueue(t a);
    t dequeue();
    int length();
    t Front();
    t Back();
    bool isEmpty();
    void Clear();
    void print();
};
