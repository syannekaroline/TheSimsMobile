#include "StoriesRelationship.h"

StoriesRelationship::StoriesRelationship() :
Stories(),simInvolved("eu mesmo(a)")
{

}

StoriesRelationship::StoriesRelationship(const string& titulo, const string& subtitulo, const string& descricao, const map<int, string>& capitulos,const string& sim)
: Stories(titulo,subtitulo,descricao,capitulos),simInvolved(sim)
{

}

StoriesRelationship::StoriesRelationship(const StoriesRelationship& other)
: Stories(static_cast< Stories >( other )), simInvolved(other.simInvolved)
{

}

StoriesRelationship::~StoriesRelationship() {}

StoriesRelationship& StoriesRelationship::operator=(const StoriesRelationship& other) {
    if (this != &other) {
        *static_cast<Stories*>(this) = static_cast<Stories>(other);
        simInvolved = other.simInvolved;
    }
    return *this;
}

bool StoriesRelationship::operator==(const StoriesRelationship& other) const {
    return static_cast< Stories >( *this ) == static_cast< Stories >( other ) && (simInvolved == other.simInvolved);
}

bool StoriesRelationship::operator!=(const StoriesRelationship& other) const {
    return !(*this == other);
}

bool StoriesRelationship::operator!() const {
    return !(*static_cast<const Stories*>(this));
}

ostream& operator<<(ostream& out, const StoriesRelationship& story) {
    out << static_cast<const Stories&>(story);
    out << "| Sim Envolvido: " << story.getSimInvolved() << "\n";
    return out;
}
