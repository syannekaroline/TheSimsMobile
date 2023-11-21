#include <iostream>
#include <iomanip>
#include "Stories.h"
using std::ostream;
using std::cerr;
using std::cout;
using std::setw;
using std::setfill;

Stories::Stories() : title("História Inicial"), subtitle("História padrão de um sim"), description("História mais básica que pode ser editada posteriormente"), parte(1) 
{
    capitulos[1] = "Parte 1";
    capitulos[2] = "Parte 2";
    capitulos[3] = "Parte 3";

}

Stories::Stories(const string& title, const string& subtitle, const string& description, const map<int, string> capitulos)
: title(title), subtitle(subtitle), description(description), capitulos(capitulos), parte(1)
{

}

Stories::Stories(const Stories& other)
    : title(other.title), subtitle(other.subtitle), description(other.description), capitulos(other.capitulos), parte(other.parte) {}

Stories::~Stories()
{
    
}

string Stories::getTitle() const {
    return title;
}

string Stories::getSubtitle() const {
    return subtitle;
}

string Stories::getDescription() const {
    return description;
}

Stories& Stories::operator=(const Stories& other) {
    if (this != &other) {
        title = other.title;
        subtitle = other.subtitle;
        description = other.description;
        capitulos = other.capitulos;
        parte = other.parte;
    }
    return *this;
}

bool Stories::operator==(const Stories& other) const {
    return (title == other.title && subtitle == other.subtitle && description == other.description &&
            capitulos == other.capitulos && parte == other.parte);
}

bool Stories::operator!=(const Stories& other) const {
    return !(*this == other);
}

bool Stories::operator!() const {
    return parte <= 0;
}

void Stories::operator++() {
    cout << "🥳 🎉 🎊 Bom Trabalho! Você alcançou um novo Capítulo  🥳 🎉 🎊\n";
    parte++;
}
ostream& operator<<(ostream& out, const Stories& story) {
    int lineWidth = 80;  // Suponha uma largura de linha padrão para ilustração

    // Centraliza o título
    int titleWidth = static_cast<int>(story.getTitle().length());
    int leftPaddingTitle = (lineWidth - titleWidth) / 2;

    // Centraliza o subtítulo
    int subtitleWidth = static_cast<int>(story.getSubtitle().length());
    int leftPaddingSubtitle = (lineWidth - subtitleWidth) / 2;

    // Centraliza a descrição
    int descriptionWidth = static_cast<int>(story.getDescription().length());
    int leftPaddingDescription = (lineWidth - descriptionWidth) / 2;

    out << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- História =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    out << setw(leftPaddingTitle) << "" << "\033[1m" << story.getTitle() << "\033[0m\n";  // Adiciona negrito
    out << setw(leftPaddingSubtitle) << "" << story.getSubtitle() << "\n";
    out << setw(leftPaddingDescription) << "" << story.getDescription() << "\n";

    out << "| Parte: " << story.getParte() << "\n";
    // Exiba os capítulos
    out << "| Capítulos:\n";
    int i = 1;
    for (const auto& [recompensa, nome] : story.capitulos) {
        // Verifique se o índice coincide com a parte atual
        if (i == story.getParte()) {
            // Use ciano para destacar o capítulo atual
            out << "|   Parte " << i << ": \033[1;36m" << nome << " | " << recompensa << "SimsCash e xp \033[0m\n";
        } else {
            out << "|   Parte " << i << ": " << nome << " | " << recompensa << "SimsCash e xp\n";
        }
        i++;
    }
    return out;
}

int Stories::getRecompensaCap(int index) const{
  // Verifica se o índice está dentro dos limites do vetor
    if (index-1 >= 0 && index-1 < capitulos.size()) {
        // Itera até a posição desejada e retorna a recompensa
        auto it = capitulos.begin();
        std::advance(it, index-1);
        return it->first;  // Retorna o valor int do mapa
    } 
    // Índice fora dos limites, pode tratar isso de acordo com suas necessidades
    std::cerr << "Erro: Índice fora dos limites." << std::endl;
    return -1;  // Valor de erro

}

// #include "StoryMissions.h"



// StoryMissions::StoryMissions()
// :SimsMissions("Conversas de Geeks", "Uma Aliança Geek", 50), parte(1)
// {


// }

// StoryMissions::StoryMissions(const string& nome, const string& descricao, int recompensa, const map<int, string>& capitulos)
// : SimsMissions(nome, descricao, recompensa), capitulos(capitulos), parte(1){
//     // Certifique-se de que os capítulos foram fornecidos
//     if (capitulos.empty()) {
//         // Lidar com erro, lançar exceção, ou adotar outra estratégia dependendo dos requisitos
//         // Aqui estamos apenas imprimindo uma mensagem de erro
//         cerr << "Erro: A lista de capítulos não pode estar vazia.\n";
//     }
// }

// // Construtor de cópia
// StoryMissions::StoryMissions(const StoryMissions& other)
// : SimsMissions(other), capitulos(other.capitulos), parte(other.parte)
// {

// }

// StoryMissions::~StoryMissions()
// {
// }
// int StoryMissions::getParte() const {
//     return parte;
// }

// StoryMissions& StoryMissions::operator=(const StoryMissions& other) {
//     if (this != &other) {
//         // Copie os atributos da missão da classe base
//         SimsMissions::operator=(other);
//         // Copie os atributos específicos da classe derivada
//         parte = other.parte;
//         capitulos = other.capitulos;
//     }
//     return *this;
// }

// bool StoryMissions::operator==(const StoryMissions& other) const {
//     // Compare os atributos da missão da classe base
//     if (!(SimsMissions::operator==(other))) {
//         return false;
//     }
//     // Compare os atributos específicos da classe derivada
//     return (parte == other.parte && capitulos == other.capitulos);
// }

// bool StoryMissions::operator!=(const StoryMissions& other) const {
//     // Use o operador == para verificar a diferença
//     return !(*this == other);
// }

// bool StoryMissions::operator!() const {
//     // Verifique se a missão está concluída
//     return parte == capitulos.size();
// }

// ostream& operator<<(ostream& out, const StoryMissions& storyMission) {
//     // Exiba de forma estilizada os atributos da missão
//     out << static_cast<SimsMissions>(storyMission);
//     out << "| -=-=-= Story Mission-=-=-=\n";
//     

//     return out;
// }

// void StoryMissions::iniciarEvento() {
//     parte++;
// }
