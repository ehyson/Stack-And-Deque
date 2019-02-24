//
//  main.cpp
//  eh787_052_P3
//
//  Created by Eric Hyson on 3/22/18.
//  Copyright © 2018 Eric Hyson. All rights reserved.
//

#include "main.h"

using namespace std;

int main()
{
    try
    {

    Deque<double> b;
    
    Stack<int> a;
       
    
    
       
    }
    catch( NoSuchObject &a )
    {
        cout << endl <<"ERROR: NoSuchObject caught in main: " << endl;
        cout << a.what() << endl;
    }
    catch( bad_alloc &a )
    {
        cout << endl << "ERROR: Bad allocation caught in main" << endl;
        cout << a.what() << endl;
    }
    
    
    
    return 0;
}




template <typename T>
const List<T>&List<T>::operator=( const List<T> &obj ) throw ( bad_alloc )
{
    if( this != &obj )
    {
        this->clear();
        cout << "after clear";
        sz = 0;
        
        Node<T> *current = obj.frontPtr;
        
        
        if( current == NULL )
        {
            cout << "Overloaded assignment operator for List<T>. Cannot add object" << endl;
        }
        else
        {
            
            unsigned index = 0;
            sz = obj.sz;
            
            for( unsigned i = 1; i < obj.sz+1; i++ )
            {
                
                if( i == 1 )
                {
                    addFirst( obj.get(i) );
                    //cout << "made it to if" << endl;
                    //cout << obj.get(i) << endl;
                    //frontPtr->getNextPtr()->setNextPtr( new Node<T>( obj.get(i) ) );
                    //add.setPrevPtr( frontPtr->getNextPtr() );
                }
                else if( i < obj.sz)
                {
                    add(i, obj.get(i) );
                    //cout << "made it to else" << endl;
                    //cout << obj.get(i) << endl;
                    //getIthNode(i-1)->setNextPtr( new Node<T>( obj.get(i) ) );
                    //add.setPrevPtr( getIthNode(i-1) );
                }
                else if( i == obj.sz )
                {
                    addLast( obj.get(i) );
                }
                
                cout << "end of first loop" << endl;
                index++;
                cout << "post indx" << endl;
            }
            
            
            //backPtr->getPrevPtr()->setPrevPtr( getIthNode(index) );
        }
        }
        
        return obj;
        }
        //add front se
