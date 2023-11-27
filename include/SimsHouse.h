#ifndef SIMSHOUSE_H
#define SIMSHOUSE_H
// A classe é protegida contra inclusões múltiplas em outros arquivos usando a diretiva de pré-processamento
#include "Sims.h"
#include <string>
#include <tuple>
using std::string;
using std::tuple;

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;
#include "Location.h"

struct features
{
  vector <string> comodos;
  int numAndares;
  bool temPiscina;
  string estilo;
};

class SimsHouse : public Location
{
  
  friend ostream &operator<<(ostream &, const SimsHouse &);
  
  public:
    // construtores e destrutores sempre começam a parte pública da classe
    SimsHouse(); // Construtor-> método chamado pra inicializar os atributos a classe
    SimsHouse(const tuple<int,int> & , double,const string & , const string & =""); // declarando o construtor com parâmetros.
    SimsHouse( const SimsHouse & ); //construtor de cópia
    ~SimsHouse();//Destrutor -> relacionado a desalocaçao de memória 

    // declarando get e set -> acesso seguro na alteração dos atributos
    void setValor(double);
    
    string getEndereco() const;
    tuple<int,int> getProporcaoTerreno() const;
    bool isPremium() const;
    double getValor() const;

    //Demais métodos 
    void efetuarVenda(Sims &);
    void setFeatures(const vector<string>& ,int,bool,string);
    void addComodo(const string& );
    void removeComodo(const string&);
    void verFeatures() const;

    //métodos statics
    inline static int getNumSimsHouses(){ return numEnderecos;};
    inline static double getMinValorPremiumHouse(){ return MINVALORPREMIUM;};

    static void mostrarVizinhanca();

    //operadores
    const SimsHouse &operator=(const SimsHouse &);  // assign SimsHouse
    int operator==(const SimsHouse &) const; // compare equal
    int operator!=(const SimsHouse &) const; // compare !equal
    bool operator!() const;

  private:

    bool premium;
    double valor; // em simCash
    features housefeatures;

    const string ENDERECO;
    const int MAXTAMSTRINGS= 25;
    //atributos static
    const static double MINVALORPREMIUM;
    const static int MAXNUMENDERECOS = 9; 
    static int numEnderecos;
    static int numLotesPossuidos;// número de casas vendidas
    static string enderecosList[ MAXNUMENDERECOS ];
};

#endif // SIMSHOUSE_H