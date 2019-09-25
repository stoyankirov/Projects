#ifndef LUGGAGE_H_INCLUDED
#define LUGGAGE_H_INCLUDED

class luggage
{   public:
        luggage();
        luggage(double cap,int subj,double wei,int i);

        double getCapacity() const;
        int getSubjects() const;
        double getWeight() const;
        int getId() const;

        void setCapacity(double cap);
        void setSubjects(int subj);
        void setWeight(double wei);
        void setId(int i);
    private:
        double capacity;
        int subjects;
        double weight;
        int id;
};

#endif // LUGGAGE_H_INCLUDED
