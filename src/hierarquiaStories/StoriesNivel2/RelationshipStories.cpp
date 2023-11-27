#include "RelationshipStories.h"

RelationshipStories::RelationshipStories() :
Stories(),simInvolved("eu mesmo(a)")
{

}

RelationshipStories::RelationshipStories(const string& titulo, const string& subtitulo, const string& descricao, const map<int, string>& capitulos,const string& sim)
: Stories(titulo,subtitulo,descricao,capitulos),simInvolved(sim)
{

}

RelationshipStories::RelationshipStories(const RelationshipStories& other)
: Stories(static_cast< Stories >( other )), simInvolved(other.simInvolved)
{

}

RelationshipStories::~RelationshipStories() {}

const RelationshipStories& RelationshipStories::operator=(const RelationshipStories& other) {
    if (this != &other) {
        *static_cast<Stories*>(this) = static_cast<Stories>(other);
        simInvolved = other.simInvolved;
    }
    return *this;
}

bool RelationshipStories::operator==(const RelationshipStories& other) const {
    return static_cast< Stories >( *this ) == static_cast< Stories >( other ) && (simInvolved == other.simInvolved);
}

bool RelationshipStories::operator!=(const RelationshipStories& other) const {
    return !(*this == other);
}

bool RelationshipStories::operator!() const {
    return !(*static_cast<const Stories*>(this));
}

ostream& operator<<(ostream& out, const RelationshipStories& story) {
    out << static_cast<const Stories&>(story);
    out << "| Sim Envolvido: " << story.getSimInvolved() << "\n";
    return out;
}
