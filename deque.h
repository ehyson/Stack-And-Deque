#ifndef deque_h
#define deque_h


using namespace std;

template <typename T>
class Deque
{    
public:

    
    Deque();
    Deque( const Deque<T>& ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    void push_front( const T& ) throw ( bad_alloc );
    void push_back( const T& ) throw ( bad_alloc );
    T pop_front() throw ( NoSuchObject );
    T& front() const throw ( NoSuchObject );
    T pop_back() throw ( NoSuchObject );
    T& back() const throw ( NoSuchObject );
    const Deque<T> &operator=( const Deque<T>& ) throw ( bad_alloc );
    void clear();
    void erase( const T& ) throw ( bad_alloc );
    ~Deque();
    
    T begin()const throw ( NoSuchObject );
    T end()const throw ( NoSuchObject );
    
   
    
    
    
    void printInternal() const;
    
private:
    unsigned sz;
    DLNode<T>* frontPtr;
    DLNode<T>* backPtr;
    
    void initialize();
    
}; // Deque class




/*****************************************************************************
*                             constructors                                  *
****************************************************************************/

//Defauly constructor for Deque Class
template <typename T>
Deque<T>::Deque()
{
    //cout << "Entered default constructor of Deque class" << endl;
    
    this->initialize();
    
} // END Deque<T>::Deque()



//Copy constructor for Deque Class
template <typename T>
Deque<T>::Deque( const Deque<T>& otherDeque ) throw ( bad_alloc )
{
    this->initialize();
    *this = otherDeque;
    
} // END Deque<T>::Deque( const Deque<T>& )



/****************************************************************************
 *                             public methods                               *
 ****************************************************************************/

//Returns true if stack is empty
template <typename T>
bool Deque<T>::empty() const
{
    if( sz == 0 )
        return true;
    else
        return false;
    
} // END Deque<T>::empty()



//Returns size of Deque
template <typename T>
unsigned Deque<T>::size() const
{
    return sz;
    
}// END Deque<T>::size()



//Inserts an object to the front of Deque
template <typename T>
void Deque<T>::push_front( const T& val ) throw ( bad_alloc )
{
    DLNode<T> *addMe = new DLNode<T>( val, frontPtr, NULL );
    
    if( frontPtr == NULL )
    {
        frontPtr = backPtr = addMe;
    }
    else
    {
        addMe->next = frontPtr;
        frontPtr->previous = addMe;
        frontPtr = addMe;
    }
    
    sz++;
    
}// END Deque<T>:: push_front( const &T)



//Inserts object to the back of Deque
template <typename T>
void Deque<T>::push_back( const T& val ) throw ( bad_alloc )
{
    DLNode<T> *addMe = new DLNode<T>( val , NULL, backPtr );
    
    if( frontPtr == NULL )
    {
        frontPtr = backPtr = addMe;
    }
    else
    {
        addMe->previous = backPtr;
        backPtr->next = addMe;
        backPtr = addMe;
    }
    
    sz++;
        
}// END Deque<T>::push_back()



//Deletes the front value in the Deque
template <typename T>
T Deque<T>::pop_front() throw ( NoSuchObject )
{
    T returnValue;
    
    if ( this->empty() )
        throw NoSuchObject( "Deque::pop_front(): cannot remove front because Deque is empty" );
    else
    {
        returnValue = this->frontPtr->info;
        DLNode<T>* temp = this->frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        sz--;
    }
    
    if( sz == 0 )
    {
        frontPtr = backPtr = NULL;
    }

    return returnValue;
} // T pop_front()



//Returns the info of the front of the Deque
template <typename T>
T& Deque<T>::front() const throw ( NoSuchObject )
{
    if ( this->empty() )
        throw NoSuchObject("The Deque is empty, cannot return front since it doesn't exist" );
        
    return this->frontPtr->info;

}// END Deque<T>::T& front()



//Deletes the last item in the Deque
template <typename T>
T Deque<T>::pop_back() throw ( NoSuchObject )
{
    T returnValue;
    
    if ((*this).empty())
        throw NoSuchObject("Deque::pop_back(): cannot remove back because Deque is empty");
        
    else
    {
        returnValue = backPtr->info;
        DLNode<T>* temp = backPtr;
        backPtr = backPtr->previous;
        
        if (backPtr == NULL)
            frontPtr = NULL;
        else
            backPtr->next = NULL;
    
        delete temp;
        sz--;
    }
    
    if (sz==0)
        frontPtr = backPtr = NULL;
        
    return returnValue;

}// END Deque<T>::T pop_back()



//Returns the info of the back of the Deque
template <typename T>
T& Deque<T>::back() const throw ( NoSuchObject )
{
    if ( this->empty() )
        throw NoSuchObject("The Deque is empty, cannot return back since it doesn't exist" );
        
        return this->backPtr->info;
    
}// END Deque<T>::T& back()



//Overloaded assignment operator for Deque
template <typename T>
const Deque<T>&Deque<T>::operator =(const Deque<T>& object) throw ( bad_alloc )
{
if( this != &object )
{
    this->clear();
    sz = 0;
    frontPtr = NULL;
    
    DLNode<T> *otherCurrent = object.frontPtr;
    
    if( otherCurrent == NULL )
    {
        cout << "Other stack is empty, cannot copy" << endl;
    }
    else
    {
        Deque<T> temp;
        while( otherCurrent != NULL )
        {
            temp.push_front( otherCurrent->info );
            otherCurrent = otherCurrent->next;
        }
        
        while( !temp.empty() )
        {
            this->push_front( temp.pop_front() );
        }
    }
        
}
            
return object;
    
}// END Deque<T> &operator =


        
//Clears all objects from Deque
template <typename T>
void Deque<T>::clear()
{
    //cout << "Entered clear() method of Deque object" << endl;
    backPtr = NULL;
    while (frontPtr != NULL)
    {
        DLNode<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
    }
    initialize();
   
}// END Deque<T>::clear()

        
template<typename T>
void Deque<T>:: erase( const T& val ) throw (bad_alloc)
{
    
    if (empty())
        return 0;
    
    if( size() == 1 && front() == val )
    {
        frontPtr = NULL;
        backPtr = NULL
        sz--;
    }
    
    for( DLnode<T> *ptr = front(); ptr! = NULL; ptr = ptr->next )
    {
        if(ptr->info == val)
        {
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
            
            sz--;
        }
    }
    
}

    
//Deconstuctor for Deque Class
template <typename T>
Deque<T>::~Deque()
{
    //cout << "Entered destructor for Deque object" << endl;
    
    this->clear();
    
}// END Deque<T>::~Deque()


/****************************************************************************
 *                          private methods                                 *
 ****************************************************************************/

//Initalizes members of Deque to default values
template <typename T>
void Deque<T>:: initialize()
{
    sz = 0;
    frontPtr = NULL;
    backPtr = NULL;
    
} // END Deque<T>::initialize()




        
        
        
        
        
template <typename T>
void Deque<T>::printInternal() const
{
    cout << "Printing Deque" << endl;
    if (frontPtr == NULL)
        cout << "The deque is empty" << endl;
    else
    {
        DLNode<T> *current = frontPtr;
        while (current != NULL)
        {
            cout << current -> info << " ";
            current = current -> next;
        }
        cout << endl;
        }
    
} // Deque<T>::::printInternal


template<typename T>
typename Deque<T>::begin()
{
    if ( this->empty() )
        throw NoSuchObject("The Deque is empty, cannot return front since it doesn't exist" );
    
    return this->frontPtr;
}


template<typename T>
typename Deque<T>::end()
{
    if ( this->empty() )
        throw NoSuchObject("The Deque is empty, cannot return back since it doesn't exist" );
    
    return this->backPtr;
}




#endif

