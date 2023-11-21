#ifndef GENERALMISSION_H
#define GENERALMISSION_H

#include "Quests.h"

class GeneralMissions : public Quests {

    friend ostream& operator<<(ostream& out, const GeneralMissions& generalMissions);

public:
    GeneralMissions();
    GeneralMissions(const string& nome, const string& icon, int recompensa, const string& subtitulo,const string& descricao);
    GeneralMissions(const GeneralMissions& other);
    ~GeneralMissions();

    // Getters
    string getDescription() const;
    string getSubtitle() const;

    // Setters
    void setDescription(const string& descricao);
    void setSubtitle(const string& subtitle);

    // Operadores
    GeneralMissions& operator=(const GeneralMissions& other);
    bool operator==(const GeneralMissions& other) const;
    bool operator!=(const GeneralMissions& other) const;
    bool operator!() const;

private:

    string description;
    string subtitle;
};

#endif // GENERALMISSION_H


