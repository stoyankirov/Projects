#include "luggage.h"
#include<iostream>
using namespace std;

luggage::luggage():capacity(0),subjects(0),weight(0),id(0)
{
    cout<<"Luggage()"<<endl;
}
luggage::luggage(double cap,int subj,double wei,int i)
{
    cout<<"In luggage(double,int,double,int)"<<endl;

    setCapacity(cap);
    setSubjects(subj);
    setWeight(wei);
    setId(i);
}
double luggage::getCapacity() const
{
    return capacity;
}
int luggage::getSubjects() const
{
    return subjects;
}
double luggage::getWeight() const
{
    return weight;
}
int luggage::getId() const
{
    return id;
}
void luggage::setCapacity(double cap)
{
    capacity=cap;
}
void luggage::setSubjects(int subj)
{
    subjects=subj;
}
void luggage::setWeight(double wei)
{
    weight=wei;
}
void luggage::setId(int i)
{
    id=i;
}
