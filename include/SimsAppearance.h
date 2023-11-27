#ifndef SIMSAPPEARANCE_H
#define SIMSAPPEARANCE_H
// diretiva de pré-processamento

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include <map>
using std::map;

struct caracteristicas
{
  string cabeca;
  string olhos;
  string nariz;
  string boca;
  string orelha;
  string cabelo;
  string sobrancelha;
  map<string,string> color;
};  

class SimsAppearance
{

  friend ostream &operator<<(ostream &, const SimsAppearance &);

  public:

    SimsAppearance();
    SimsAppearance(const string &, const string &, const string &, const string &, const string &, const string &, const string &);
    SimsAppearance(const SimsAppearance &);
    ~SimsAppearance();

    // Métodos set e get para cada atributo
    void setCabeca(const string &cabeca);
    string getCabeca() const;

    void setOlhos(const string &olhos);
    string getOlhos() const;

    void setNariz(const string &nariz);
    string getNariz() const;

    void setBoca(const string &boca);
    string getBoca() const;

    void setOrelha(const string &Orelha);
    string getOrelha() const;

    void setCabelo(const string &cabelo);
    string getCabelo() const;

    void setSobrancelha(const string &sobrancelha);
    string getSobrancelha() const;

    void setColor(string opcao, int color=0);
    string getColor(string opcao) const;

    static void mostrarOpcoes(const string listaOpcoes[], const string & titulo);
    static void exibirMenuConfiguracoes(int opcao = -1);
    //operadores
    const SimsAppearance &operator=(const SimsAppearance &);  // assign SimsAppearance
    int operator==(const SimsAppearance &) const; // compare equal
    int operator!=(const SimsAppearance &) const; // compare !equal
    void operator!(); // "zera"/"esvazia" aparência;
    string getColor(int color );
  private:

    caracteristicas config;
    // atributos estáticos
    static const int NUMAXCONFIGURACOES = 3;
    static const string LIST_CABECA[NUMAXCONFIGURACOES];
    static const string LIST_OLHOS[NUMAXCONFIGURACOES];
    static const string LIST_NARIZ[NUMAXCONFIGURACOES];
    static const string LIST_BOCA[NUMAXCONFIGURACOES];
    static const string LIST_ORELHA[NUMAXCONFIGURACOES];
    static const string LIST_CABELO[NUMAXCONFIGURACOES];
    static const string LIST_SOBRANCELHA[NUMAXCONFIGURACOES];

    void limpaCaracteristica( string& caracteristica);

};

#endif // SIMSAPPEARANCE_H