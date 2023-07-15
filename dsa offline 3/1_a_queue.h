#include<bits/stdc++.h>
using namespace std;
template<typename t>
class myarray{
t *arr;
int cur,length,capasity;
public:
    void init();
    myarray();
    myarray(int a);
    ~myarray();
void Insert(t a);
t Remove();
int Length();
void moveToEnd();
void moveToStart();
void prev();
void next();
t getValue();
int curPos();
void moveToPos(int a);
void print();
void Clear();
int Capasity();
void setcap(int b);
};
template <typename t>
class AQueue{
    int frront;
    int Rear;
myarray<t> arr;
public:
    AQueue();
    t enqueue(t a);
    t dequeue();
    int length();
    t Front();
    t Back();
    bool isEmpty();
    void Clear();
    void print();
    int ok();
};
