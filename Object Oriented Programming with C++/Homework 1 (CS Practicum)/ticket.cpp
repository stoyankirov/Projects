#include "ticket.h"
#include<iostream>
using namespace std;

ticket::ticket():firstStation(NULL),destination(NULL),price(0),travellingWith(NULL)
{   cout<<"Ticket()"<<endl;
}
ticket::ticket(const char* firstSt,const char* dest,int pr,char* travellingW):firstStation(NULL),destination(NULL),price(pr),travellingWith(NULL)
{   assert(firstSt);
    assert(dest);
    assert(travellingW);

    cout<<"In ticket(const char*,const char*,int,const char*)"<<endl;

    setFirstStation(firstSt);
    setDestination(dest);
    setPrice(pr);
    setTravellingWith(travellingW);
}
ticket::ticket(const ticket& right)
{
    cout<<"ticket(const ticket&)"<<endl;
    assert(right.firstStation);
    assert(right.destination);
    assert(right.travellingWith);

    setFirstStation(right.firstStation);
    setDestination(right.destination);
    this->price=right.price;
    setTravellingWith(right.travellingWith);
}
ticket& ticket::operator= (const ticket& right);
{
    cout<<"ticket::operator= "<<endl;
}
ticket::~ticket()
{   cout<<"~ticket()"<<endl;
    delete [] firstStation;
    firstStation=NULL;
    delete [] destination;
    destination=NULL;
    delete [] travellingWith;
    travellingWith=NULL;
}
char* ticket::getFirstStation() const
{
    return firstStation;
}
char* ticket::getDestination() const
{
    return destination;
}
int ticket::getPrice() const
{
    return price;
}
char* ticket::getTravellingWith() const
{
    return travellingWith;
}
void ticket::setFirstStation(const char* firstSt)
{
    assert(firstSt);
    delete [] firstStation;
    firstStation=new char[strlen(firstSt)+1];
    strcpy(firstStation,firstSt);
}
void ticket::setDestination(const char* dest)
{
    assert(dest);
    delete [] destination;
    destination=new char[strlen(dest)+1];
    strcpy(destination,dest);
}
void ticket::setPrice(int pr)
{
    price=pr;
}
void ticket::setTravellingWith(const char* travellingW)
{
    assert(travellingW);
    delete [] travellingWith;
    travellingWith=new char[strlen(travellingW)+1];
    strcpy(travellingWith,travellingW);
}
