
#ifndef stack_h
#define stack_h
#include "nosuchobject.h"
#include "node.h"

using namespace std;

template <typename T>
class Stack
{
public:
    Stack();
    Stack( const Stack<T>& s ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    T& top() const throw ( NoSuchObject );
    T pop() throw ( NoSuchObject );
    void push( const T& ) throw ( bad_alloc );
    const Stack<T>& operator=( const Stack<T>& ) throw ( bad_alloc );
    void printInternal() const;
    void clear();
    ~Stack();
    
private:
    unsigned sz;
    Node<T>* topPtr;
    
    void initialize();
    
}; // Stack<T> class






/*****************************************************************************
 *                            constructors                                  *
 ****************************************************************************/


//Default constructor for Stack Class
template <typename T>
Stack<T>:: Stack()
{
    cout << "Inside default constructor of Stack class\n";
    sz = 0;
    topPtr = NULL;
}

    

//Copy constructor for Stack Class
template <typename T>
Stack<T>:: Stack( const Stack<T>& s ) throw ( bad_alloc )
{
        
    initialize();
    *this = s;

}

/****************************************************************************
 *                            public methods                                *
 ****************************************************************************/

//Returns bool value o0f wheth
template <typename T>
bool Stack<T>::empty() const
{
    if( sz == 0 )
        return true;
    else
        return false;
   
}// END Stack<T>:: empty()



//Returns size of Stack
template <typename T>
unsigned Stack<T>:: size() const
{
    return sz;
    
}// END Stack<T>:: size()



//Returns top object in Stack
template <typename T>
T& Stack<T>::top() const throw ( NoSuchObject )
{
    if( topPtr != NULL )
        return topPtr->getObject();
    else
        throw NoSuchObject( "Cannot return top value because there is none \n" );
    
}// END T& top() throw ( NoSuchObject )


    
//Removes the top object from the stack
template <typename T>
T Stack<T>::pop() throw ( NoSuchObject )
{
    T returnValue;
        
        if( topPtr == NULL )
            throw NoSuchObject( "Cannot pop because the list is already empty" );
        else if( topPtr->Node<T>::getNextPtr() == NULL )
        {
            returnValue = topPtr->Node<T>::getObject();
            delete topPtr;
            topPtr = NULL;
            sz = 0;
        }
        else
        {
            Node<T> *current = topPtr;
            returnValue = topPtr->Node<T>::getObject();
            topPtr = topPtr->Node<T>::getNextPtr();
            delete current;
            sz--;
        }

    
    return returnValue;
    
}// END T pop() throw ( NoSuchArgument )



//Adds object to top of Stack
template <typename T>
void Stack<T>::push( const T& object) throw ( bad_alloc )
{
    Node<T> *temp;
    

     if( topPtr == NULL )
     {
         cout << "\nAdding first node to linked list \n";
     
         topPtr = new Node<T> ( object );
     }
     else
     {
         temp = new Node<T> ( object );
         temp->setNextPtr(topPtr);
         topPtr = temp;
     }
    
     sz++;

        

}// END Stack<T>::push( const T& ) throw ( bad_alloc )



//Prints out information of all objects in Stack
template <typename T>
void Stack<T>::printInternal() const
{
    Node<T>* current = topPtr;
    int i = 0;
    cout << "top: " << topPtr << endl;
    while ( current != NULL ) {
        cout << "Node " << i << endl;
        cout << "  address: " << current << endl;
        cout << "  object: " << current->getObject() << endl;
        cout << "  next: " << current->getNextPtr() << endl;
        current = current->getNextPtr();
        i++;
    } // while
} // Stack<T>::printInternal


    
//Clears the stack
template <typename T>
void Stack<T>::clear()
{
    //cout << "Entered clear() method of Deque object" << endl;
    Node<T> *current = topPtr;
    
    while( current != NULL )
    {
        topPtr = topPtr->getNextPtr();
        delete current;
        current = topPtr;
        sz--;
    }
    
    current = topPtr = NULL;
    
}// END void Stack<T>::clear()
     
 
    
//Overloaded operator for Stack Class
template <typename T>
const Stack<T>&Stack<T>::operator= ( const Stack<T>& value ) throw ( bad_alloc )
{
    
    if (this != &value )
    {
        
        cout << "Inside overloaded assignment operator for class Stack\n";
        
        this->clear();
        
        sz = 0;
        topPtr = NULL;
        
        Node<T> *otherCurrent = value.topPtr;
        
        if (otherCurrent == NULL)
        {
            cout << "other Stack is empty, nothing to do" << endl;
        }
        else
        {
            Stack<T> temp;
            while( otherCurrent != NULL )
            {
                temp.push(otherCurrent->getObject() );
                otherCurrent = otherCurrent->getNextPtr();
            }
            
            
            while(!temp.empty())
            {
                this->push( temp.pop() );
            }
        }
        
    }
    
    return value;
    
}// END Stack<T>::StacStack<T>& operator=( const Stack<T>& ) throw ( bad_alloc )

    
    
//Deconstructor for Stack Class
template <typename T>
Stack<T>::~Stack()
{
    if( topPtr == NULL )
    {
        cout << "Stack is now empty\n";
    }
    else
    {
        
        clear();
        
        topPtr = NULL;
    }
    
}// END Stack<T>::~Stack()
            
             
             
             
//Initializes Stack members to default values
template <typename T>
void Stack<T>::initialize()
{
    sz = 0;
    topPtr = NULL;
    
}// END Stack<T>::initialize()
             


#endif



