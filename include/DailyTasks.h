#ifndef DailyTasks_H
#define DailyTasks_H

#include <iostream>
using std::ostream;
using std::cout;
#include <string>
using std::string;
using std::ostream;

#include "Quests.h"
#include "Data.h"

class DailyTasks : public Quests {
    friend ostream& operator<<(ostream& out, const DailyTasks& dailyMission);

public:
    DailyTasks();
    DailyTasks(const string&, const string&, int);
    DailyTasks(const DailyTasks& other);
    ~DailyTasks();

    void showEndsIn() const;
    bool hasExpired() const;
    // Operadores
    DailyTasks& operator=(const DailyTasks& other);
    bool operator==(const DailyTasks& other) const;
    bool operator!=(const DailyTasks& other) const;
    bool operator!() const;

    string tempoRestanteAteFinalDoDia() const;

private:
    Data endsIn;
};

#endif // DailyTasks_H
