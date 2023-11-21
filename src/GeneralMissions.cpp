#include "GeneralMissions.h"

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

GeneralMissions& GeneralMissions::operator=(const GeneralMissions& other) {
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