#ifndef STANDARDSHIFT_H
#define STANDARDSHIFT_H
#include "StoriesCareer.h"
#include "Sims.h"

#include <vector>
using std::vector;

class StandardShift : public StoriesCareer {
    
    friend ostream& operator<<(ostream& out, const StandardShift& story);

public:
    StandardShift();
    StandardShift(const StoriesCareer& carreiraHistoria,const vector<string>& actions);
    StandardShift(const StandardShift& other);
    ~StandardShift();

    StandardShift& operator=(const StandardShift& other);
    bool operator==(const StandardShift& other) const;
    bool operator!=(const StandardShift& other) const;
    bool operator!() const;
    void iniciarEvento(Sims*);

private:
    static const int DURACAO = 4;// duração em "hora"
    static const int RECOMPENSA_SIMCASH = 135;
    static const int RECOMPENSA_PC = 90;// recompensa em pontos de carreira
    vector<string> actions;
};

#endif // STANDARDSHIFT_H

