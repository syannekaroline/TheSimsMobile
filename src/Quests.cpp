#include "Quests.h"

Quests::Quests() : nome("Faça um intervalo"), icon("🛋️"), rewardsSimsCash(5), concluida(false)
{

}

Quests::Quests(const string& nome, const string icon, int rewardsSimsCash)
:rewardsSimsCash(rewardsSimsCash),concluida(false) 
{
    setNome(nome);
    setIcon(icon);
}

Quests::Quests(const Quests& other)
    : nome(other.nome),
      icon(other.icon),
      rewardsSimsCash(other.rewardsSimsCash),
      concluida(other.concluida) {}

Quests::~Quests() {}

string Quests::getNome() const {
    return nome;
}

string Quests::getIcon() const {
    return icon;
}

int Quests::getRewards() const {
    return rewardsSimsCash;
}

bool Quests::isConcluida() const {
    return concluida;
}
//sets
void Quests::setNome(const std::string& nome) {
    this->nome = limitarTamanhoString(nome);
}

void Quests::setIcon(const std::string& icon) {
    this->icon = icon;
}

void Quests::setRewards(int rewardsSimsCash) {
    this->rewardsSimsCash = rewardsSimsCash;
}

void Quests::concluirMissao() {
    concluida = true;
}

Quests& Quests::operator=(const Quests& other) {
    if (this != &other) {
        nome = other.nome;
        icon = other.icon;
        rewardsSimsCash = other.rewardsSimsCash;
        concluida = other.concluida;
    }
    return *this;
}

bool Quests::operator==(const Quests& other) const {
    return (nome == other.nome && icon == other.icon && rewardsSimsCash == other.rewardsSimsCash && concluida == other.concluida);
}

bool Quests::operator!=(const Quests& other) const {
    return !(*this == other);
}

bool Quests::operator!() const {
    return concluida;
}

string Quests::limitarTamanhoString(const string& str) {
    return (str.length() >MAX_STRING_LENGTH) ? str.substr(0,MAX_STRING_LENGTH) : str;
}

ostream& operator<<(ostream& out, const Quests& mission) {
    out << "\n+-----------------------+\n";
    out << "|       Quest       |\n";
    out << "+-----------------------+\n";
    out << "| "<< mission.getNome() <<" "<< mission.getIcon() << "\n";
    out << "| Rewards: " << mission.getRewards() << " SimsCash\n";
    out << "| Completed: " << (mission.isConcluida() ? "Yes" : "No") << "\n";
    return out;
}