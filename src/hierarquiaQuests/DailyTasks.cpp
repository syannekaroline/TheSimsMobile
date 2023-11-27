#include "DailyTasks.h"
#include "Data.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>

using std::cout;
using std::setw;
using std::setfill;
using std::chrono::system_clock;
using std::time_t;
using std::tm;

DailyTasks::DailyTasks()
:Quests(), endsIn(Data::getDataAtual()) 
{

}

DailyTasks::DailyTasks(const string& nome, const string& icon, int recompensa)
: Quests(nome, icon, recompensa), endsIn(Data::getDataAtual()) 
{
}

DailyTasks::DailyTasks(const DailyTasks& other) 
:Quests(other), endsIn(other.endsIn) 
{
}
DailyTasks::~DailyTasks()
{
}

void DailyTasks::showEndsIn() const {
    endsIn.print();
}

const DailyTasks& DailyTasks::operator=(const DailyTasks& other) {
    if (this != &other) {
        // Copie os atributos da missão
        *static_cast< Quests * >( this ) = static_cast< Quests >( other );
        endsIn = other.endsIn;
    }
    return *this;
}

bool DailyTasks::operator==(const DailyTasks& other) const {
    // Compare os atributos da missão
    return (endsIn == other.endsIn && static_cast< Quests >( *this ) == static_cast< Quests >( other ));
}

bool DailyTasks::operator!=(const DailyTasks& other) const {
    // Use o operador == para verificar a diferença
    return !(*this == other);
}

bool DailyTasks::operator!() const {
    // Verifique se a missão expirou
    return endsIn != Data::getDataAtual();
}

bool DailyTasks::hasExpired() const {
    // Verifique se a data de término (endsIn) é anterior à data atual
    return endsIn != Data::getDataAtual();
}
ostream& operator<<(ostream& out, const DailyTasks& dailyMission) {
    // Exiba de forma estilizada os atributos da missão
    if (dailyMission.hasExpired()){
        out<<"Missão expirada.\n";
        return out;
    }
    out << static_cast< Quests>( dailyMission );
    out << "| Data: ";
    dailyMission.showEndsIn();
    out << "\n| Atualiza em: 🕗 "<< dailyMission.tempoRestanteAteFinalDoDia();
    out << "\n+-----------------------+\n";


    return out;
}

string DailyTasks::tempoRestanteAteFinalDoDia() const {
    // Obtém o relógio atual
    auto agora = system_clock::now();

    // Converte para o tipo de tempo local
    auto tempoLocal = system_clock::to_time_t(agora);
    tm* infoTempo = localtime(&tempoLocal);

    // Calcula o tempo restante até o final do dia
    int horasRestantes = 23 - infoTempo->tm_hour;
    int minutosRestantes = 59 - infoTempo->tm_min;

    // Formata o resultado
    std::stringstream resultado;
    resultado << setw(2) << setfill('0') << horasRestantes<< ":"
              << setw(2) << setfill('0') << minutosRestantes;

    return resultado.str();
}
