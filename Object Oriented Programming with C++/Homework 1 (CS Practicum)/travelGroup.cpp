#include "travelGroup.h"
#include<iostream>
using namespace std;

travelGroup::travelGroup():arr(NULL),num(0)
{
    cout<<"travelGroup()"<<endl;
}
travelGroup::travelGroup(int num, const passenger* arr):arr(NULL),num(num)
{
    cout<<"travelGroup(int,const passenger* )"<<endl;

    this->arr=new passenger[num];
    for(int i=0;i<num;i++)
    {
        this->arr[i]=arr[i];
    }
}
travelGroup::travelGroup(const travelGroup& other):arr(NULL)
{
    cout<<"travelGroup(const travelGroup&"<<endl;
    copyTravelGroup(other);
}
travelGroup& travelGroup::operator= (const travelGroup& other)
{
    cout<<"operator= (const travelGroup&)"<<endl;
    if(this!=&other)
    {
        deleteTravelGroup();
        copyTravelGroup(other);
    }
    return *this;
}
travelGroup::~travelGroup()
{
    cout<<"~travelGroup()"<<endl;
    deleteTravelGroup();
}
void travelGroup::copyTravelGroup(const travelGroup& other)
{
    this->num=other.num;
    this->arr=new passenger[num];
    for(int i=0;i<num;i++)
    {
        this->arr[i]=other.arr[i];
    }
}
void travelGroup::deleteTravelGroup()
{
    delete [] arr;
    arr=NULL;
}
int travelGroup::getNum() const
{
    return num;
}
void travelGroup::setPassengers(int n,const passenger* arr)
{
    delete [] this->arr;
    this->num=n;
    this->arr=new passenger[n];

    for(int i=0;i<n;i++)
    {
        this->arr[i]=arr[i];
    }
}
