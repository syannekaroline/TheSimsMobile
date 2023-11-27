#include "GeneralMissions.h"
using std::cout;
// Códigos de cores ANSI para o terminal
const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

int GeneralMissions::nCompleted = 0;
GeneralMissions::GeneralMissions()
:Quests(), description("Que dia produtivo! Faça um intervalo no sofá."), subtitle("Descansar no sofá")
{

}

GeneralMissions::GeneralMissions(const string& nome, const string& icon, int recompensa, const string& subtitulo, const string& descricao )
: Quests(nome, icon, recompensa)
{
    setSubtitle(subtitulo);
    setDescription(descricao);
}

GeneralMissions::GeneralMissions(const GeneralMissions& other)
: Quests(other),
    description(other.description),
    subtitle(other.subtitle)
{}

GeneralMissions::~GeneralMissions() {}

string GeneralMissions::getDescription() const {
    return description;
}

string GeneralMissions::getSubtitle() const {
    return subtitle;
}

void GeneralMissions::setDescription(const string& description) {
    this->description = Quests::limitarTamanhoString(description);
}

void GeneralMissions::setSubtitle(const string& subtitle) {
    this->subtitle = Quests::limitarTamanhoString(subtitle);
}

const GeneralMissions& GeneralMissions::operator=(const GeneralMissions& other) {
    if (this != &other) {
        *static_cast< Quests * >( this ) = static_cast< Quests >( other );
        description = other.description;
        subtitle = other.subtitle;
    }
    return *this;
}

bool GeneralMissions::operator==(const GeneralMissions& other) const {
    return (static_cast< Quests >( *this ) == static_cast< Quests >( other ) 
    && description == other.description 
    && subtitle == other.subtitle);
}

bool GeneralMissions::operator!=(const GeneralMissions& other) const {
    return !(*this == other);
}

bool GeneralMissions::operator!() const {
    return Quests::operator!();
}

ostream& operator<<(ostream& out, const GeneralMissions& generalMissions) {
    out << "| -=-=-= General Mission-=-=-=\n";
    out << static_cast<const Quests&>(generalMissions);  // Mostra os atributos da classe base
    out << "| " << generalMissions.getDescription() << "\n";
    out << "| Descrição: " << generalMissions.getSubtitle() << "\n";
    out << "+-----------------------+\n";
    return out;
}

void GeneralMissions::completed()
{
    nCompleted++;
    if (nCompleted == BONUS_MAX){
        completeObjectiveBonus();
        return;
    }
    concluirMissao();
    cout<<*this;
    return;
}
void GeneralMissions::completeObjectiveBonus(){

    cout << VERDE<<"\nParabés vc concluíu suas "<<BONUS_MAX<<" primeiras missões!\n"<<RESET<<"\n";
    cout << "\nAs recompensas serão duplicadas!!!\n";

    setRewards(getRewards() * 2);  // Dobrar as recompensas no contexto do jogo
    concluirMissao();
    cout<<*this;
    return;
}