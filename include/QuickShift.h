#ifndef QUICKSHIFT_H
#define QUICKSHIFT_H
#include "StoriesCareer.h"
#include "Sims.h"

#include <vector>
using std::vector;

class QuickShift : public StoriesCareer {
    
    friend ostream& operator<<(ostream& out, const QuickShift& story);

public:
    QuickShift();
    QuickShift(const StoriesCareer& carreiraHistoria,const vector<string>& );
    QuickShift(const QuickShift& other);
    ~QuickShift();

    QuickShift& operator=(const QuickShift& other);
    bool operator==(const QuickShift& other) const;
    bool operator!=(const QuickShift& other) const;
    bool operator!() const;
    void iniciarEvento(Sims*);

private:
    static const int DURACAO = 1;// duração em "hora"
    static const int RECOMPENSA_SIMCASH = 45;
    static const int RECOMPENSA_PC = 30;// recompensa em pontos de carreira
    vector<string> actions;
};

#endif // QUICKSHIFT_H