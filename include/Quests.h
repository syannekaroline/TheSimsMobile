#ifndef QUESTS_H
#define QUESTS_H

#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::ostream;

class Quests {

    friend ostream& operator<<(ostream& out, const Quests& mission);

public:
    Quests();
    Quests(const string& nome, const string icon = "",int rewardsSimsCash=25);
    Quests(const Quests& other);
    ~Quests();

    //gets
    string getNome() const;
    string getIcon() const;
    int getRewards() const;
    bool isConcluida() const;

    //sets
    void setNome(const string& nome);
    void setIcon(const string& icon);
    void setRewards(int rewardsSimsCash);
    void concluirMissao();

    // Operadores
    Quests& operator=(const Quests& other);
    bool operator==(const Quests& other) const;
    bool operator!=(const Quests& other) const;
    bool operator!() const;

    // Função auxiliar para limitar o tamanho da string
    string limitarTamanhoString(const string& str);
private:
    string nome;
    string icon;
    int rewardsSimsCash;
    bool concluida;

    // Limitar o tamanho das strings
    static const int MAX_STRING_LENGTH = 100;
};

#endif // QUESTS_H
