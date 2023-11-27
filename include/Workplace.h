#ifndef WORKPLACE_H
#define WORKPLACE_H

#include "CareerStories.h"
#include "Building.h"

class Workplace : public Building
{
        friend ostream &operator<<(ostream &, const Workplace &);

    public:
        Workplace();
        Workplace(const tuple<int, int> &, const CareerStories &,const string & = "Sem Proprietário", const string & = "", const string & = "");
        Workplace(const Workplace &other);
        ~Workplace();

        // Métodos get e set
        void setCareerStories(const CareerStories &);
        CareerStories getCareerStories() const;

        void goToWork(Sims *sims);
        // Operadores
        const Workplace &operator=(const Workplace &);
        bool operator==(const Workplace &) const;
        bool operator!=(const Workplace &) const;
        bool operator!() const;
    private:
    
        CareerStories careerStorie;

};

#endif // WORKPLACE_H