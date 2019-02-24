#ifndef DLNode_h
#define DLNode_h

using namespace std;

template <typename T>
class DLNode {
public:
    T info;
    DLNode<T>* next;
    DLNode<T>* previous;
    
    DLNode( T=T(), DLNode<T>* next = NULL, DLNode<T>* previous = NULL);
    
};




template <typename T>
DLNode<T>::DLNode( T infoValue, DLNode<T>*nextPtr, DLNode<T>*prevPtr)
{
    this->info = infoValue;
    this->next = nextPtr;
    this->previous = prevPtr;
}


#endif
