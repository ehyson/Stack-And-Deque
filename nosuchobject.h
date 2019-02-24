#ifndef nosuchobject_h
#define nosuchobject_h


using namespace std;

/****************************************************************************
 *                                                                          *
 *                   class NoSuchObject declaration                         *
 *                                                                          *
 ****************************************************************************/


class NoSuchObject : public logic_error
{
public:
    NoSuchObject(string msg = "no such object");
    
}; //END definition class no_such_object



NoSuchObject::NoSuchObject(string msg) : std::logic_error(msg)
{
    //nothing else to do
}


#endif
