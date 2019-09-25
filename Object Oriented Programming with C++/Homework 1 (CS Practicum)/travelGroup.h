#ifndef TRAVELGROUP_H_INCLUDED
#define TRAVELGROUP_H_INCLUDED

#include "passenger.h"

class travelGroup
{
    public:
        travelGroup();
        travelGroup(int num, const passenger* arr);
        travelGroup(const travelGroup& other);
        ~travelGroup();

        int getNum() const;
        void setPassengers(int n,const passenger* arr);

    private:
        void copyTravelGroup(const travelGroup& other);
        void deleteTravelGroup();

        int num;
        passenger* arr;
};

#endif // TRAVELGROUP_H_INCLUDED
