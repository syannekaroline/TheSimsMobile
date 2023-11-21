#ifndef STORIESCAREER_H
#define STORIESCAREER_H
#include "Stories.h"

class StoriesCareer : public Stories {

    friend ostream& operator<<(ostream& out, const StoriesCareer& story);

public:
    StoriesCareer();
    StoriesCareer(const string&, const string&, const string&, const map<int, string> &,const string &,const string &);
    StoriesCareer(const StoriesCareer& other);
    ~StoriesCareer();

    StoriesCareer& operator=(const StoriesCareer& other);
    bool operator==(const StoriesCareer& other) const;
    bool operator!=(const StoriesCareer& other) const;
    bool operator!() const;

    inline string getSimWorker() const {return worker;};
    inline string getSimWorkplace() const {return workplace;};
    inline int getMaxPointsCareer() const { return MAX_POINTS_CAREER; };

    inline void setWorker(string worker) {this->worker = worker;};
    inline void setWorkplace(){this->workplace = workplace;};
    inline int getPontosCarreira() const {return pontosDeCarreira;};
    inline int resetPontosDeCarreira() { pontosDeCarreira = 0;};
    inline int addPontosDeCarreira(int pontos) { pontosDeCarreira+=pontos;};

    string worker;
    string workplace;
    int pontosDeCarreira=0;
    static const int MAX_POINTS_CAREER = 100;
};

#endif // STORIESCAREER_H

