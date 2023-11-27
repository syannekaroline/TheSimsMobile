#ifndef CAREERSTORIES_H
#define CAREERSTORIES_H
#include "Stories.h"
#include "Sims.h"
#include <vector>
using std::vector;

enum eventType { QUICKSHIFT, STANDARDSHIFT };

class CareerStories : public Stories {

    friend ostream& operator<<(ostream& out, const CareerStories& story);

    public:
    
        CareerStories();
        CareerStories(const string&, const string&, const string&, const map<int, string> &,const string &,const string &,const vector<string>&);
        CareerStories(const CareerStories& other);
        ~CareerStories();

        const CareerStories& operator=(const CareerStories& other);
        bool operator==(const CareerStories& other) const;
        bool operator!=(const CareerStories& other) const;
        bool operator!() const;

        inline string getSimWorker() const {return worker;};
        inline string getSimWorkplace() const {return workplace;};
        inline int getMaxPointsCareer() const { return MAX_POINTS_CAREER; };

        inline void setWorker(string worker) {this->worker = worker;};
        inline void setWorkplace(string workplace){this->workplace = workplace;};
        inline int getPontosCarreira() const {return pontosDeCarreira;};
        void iniciarEvento(Sims*,const eventType&);

    private:

        string worker;
        string workplace;
        int pontosDeCarreira=0;
        static const int MAX_POINTS_CAREER = 100;
        
        static const map<string,int> STANDARD_SHIFT;
        static const map<string,int> QUICK_SHIFT ;

        vector<string> actions;

};

#endif // CAREERSTORIES_H