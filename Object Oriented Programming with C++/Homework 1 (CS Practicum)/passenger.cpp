#include "passenger.h"
#include<iostream>
using namespace std;

passenger::passenger():myName(NULL)
{
    luggage myLuggage;
    ticket myTicket;
    cout<<"Passenger()"<<endl;
}
passenger::passenger(char* name ,luggage lugg,ticket tick)
{
    assert(name);
    assert(tick.getFirstStation());
    assert(tick.getDestination());
    assert(tick.getTravellingWith());

    cout<<"In passenger(char*,luggage,ticket)"<<endl;

    setMyName(name);
    setMyLuggage(lugg);
    setMyTicket(tick);
}
passenger::passenger(const passenger& right)
{
    cout<<"passenger(const passenger&)"<<endl;
    assert(right.myName);
    assert(right.myTicket.getFirstStation());
    assert(right.myTicket.getDestination());
    assert(right.myTicket.getTravellingWith());

    setMyName(right.myName);
    setMyLuggage(right.myLuggage);
    setMyTicket(right.myTicket);
}
passenger& passenger::operator= (const passenger& right);
{
    cout<<"passenger::operator= "<<endl;
}
passenger::~passenger()
{   cout<<"~passenger()"<<endl;

    delete [] myName;
    myName=NULL;

    myTicket.~ticket();
}
char* passenger::getMyName() const
{
    return myName;
}
luggage passenger::getMyLuggage() const
{
    return myLuggage;
}
ticket passenger::getMyTicket() const
{
    return myTicket;
}
void passenger::setMyName(const char* name)
{
    assert(name);
    delete [] name;
    name=new char(strlen(name)+1);
    strcpy(myName,name);
}
void passenger::setMyLuggage(const luggage lugg)
{
    this->myLuggage.setCapacity(lugg.getCapacity());
    this->myLuggage.setSubjects(lugg.getSubjects());
    this->myLuggage.setWeight(lugg.getWeight());
    this->myLuggage.setId(lugg.getId());
}
void passenger::setMyTicket(const ticket tick)
{   this->myTicket.setFirstStation(tick.getFirstStation());
    this->myTicket.setDestination(tick.getDestination());
    this->myTicket.setPrice(tick.getPrice());
    this->myTicket.setTravellingWith(tick.getTravellingWith());
}
