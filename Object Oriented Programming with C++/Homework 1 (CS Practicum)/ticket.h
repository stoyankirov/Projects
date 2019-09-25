#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

class ticket
{
    public:
        ticket();
        ticket(const char* firstSt,const char* dest,int pr,char* travellingW);
        ticket(const ticket& right);
        ticket& operator= (const ticket& right);

        char* getFirstStation() const;
        char* getDestination() const;
        int getPrice() const;
        char* getTravellingWith() const;

        void setFirstStation(const char* firstSt);
        void setDestination(const char* dest);
        void setPrice(int pr);
        void setTravellingWith(const char* travellingW);

        ~ticket();

    private:
        char* firstStation;
        char* destination;
        int price;
        char* travellingWith;
};

#endif // TICKET_H_INCLUDED
