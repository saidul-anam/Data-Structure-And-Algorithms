#include "1_a_queue.cpp"
template<class t>
class Stack{
AQueue<t>arr,temp;
void Insert(t a){
 arr.enqueue(a);
}
public:
  t pop();
  t topValue();
int Length();
bool isEmpty();
void Clear();
void push(t a);
void print();
};
