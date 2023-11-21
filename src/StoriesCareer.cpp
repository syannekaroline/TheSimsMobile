#include "StoriesCareer.h"

// Construtor padrão
StoriesCareer::StoriesCareer(): Stories(), worker(""), workplace("") 
{

}

// Construtor com parâmetros
StoriesCareer::StoriesCareer(const string& title, const string& subtitle, const string& content, const map<int, string>& chapters, const string& worker, const string& workplace)
: Stories(title, subtitle, content, chapters), worker(worker), workplace(workplace)
{

}

// Construtor de cópia
StoriesCareer::StoriesCareer(const StoriesCareer& other)
: Stories(other), worker(other.worker), workplace(other.workplace) {}

// Destrutor
StoriesCareer::~StoriesCareer()
{

}

// Operador de atribuição
StoriesCareer& StoriesCareer::operator=(const StoriesCareer& other) {
    if (this != &other) {
        *static_cast<Stories*>(this) = static_cast<Stories>(other);
        worker = other.worker;
        workplace = other.workplace;
    }
    return *this;
}

// Operador de comparação de igualdade
bool StoriesCareer::operator==(const StoriesCareer& other) const {
    return static_cast< Stories >( *this ) == static_cast< Stories >( other ) &&
    worker == other.worker && workplace == other.workplace;
}

// Operador de comparação de desigualdade
bool StoriesCareer::operator!=(const StoriesCareer& other) const {
    return !(*this == other);
}

// Operador lógico de negação
bool StoriesCareer::operator!() const {
    return worker.empty() && workplace.empty();
}

// Operador de saída
ostream& operator<<(ostream& out, const StoriesCareer& story) {
    out << static_cast<const Stories&>(story);  // Chamando o operador de saída da classe base
    out << "| Current Pontos de Carreira no capítulo: " << story.pontosDeCarreira << "\n";
    out << "| Sim: " << story.worker << "\n";
    out << "| local: " << story.workplace << "\n";
    return out;
}
