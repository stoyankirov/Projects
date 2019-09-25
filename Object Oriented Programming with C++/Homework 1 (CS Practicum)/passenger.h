#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

#include "luggage.h"
#include "ticket.h"

class passenger
{   public:
        passenger();
        passenger(char* name ,luggage lugg,ticket tick);
        passenger(const passenger& right);
        passenger& operator= (const passenger& right);

        char* getMyName() const;
        luggage getMyLuggage() const;
        ticket getMyTicket() const;

        void setMyName(const char* name);
        void setMyLuggage(const luggage lugg);
        void setMyTicket(const ticket tick);

        ~passenger();

    private:
        char* myName;
        luggage myLuggage;
        ticket myTicket;
};

#endif // PASSENGER_H_INCLUDED
