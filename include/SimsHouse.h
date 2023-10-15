#ifndef SIMSHOUSE_H
#define SIMSHOUSE_H
// A classe é protegida contra inclusões múltiplas em outros arquivos usando a diretiva de pré-processamento
#include "Sims.h"
#include <string>
#include <tuple>
using std::string;
using std::tuple;

class SimsHouse 
{
  public:
    // construtores e destrutores sempre começam a parte pública da classe
    SimsHouse(); // Construtor-> método chamado pra inicializar os atributos a classe
    SimsHouse(const tuple<int,int> & , double,const string & , const string & =""); // declarando o construtor com parâmetros.
    SimsHouse( const SimsHouse & ); //construtor de cópia
    ~SimsHouse();//Destrutor -> relacionado a desalocaçao de memória 

    // declarando get e set -> acesso seguro na alteração dos atributos
    void setProporcaoTerreno(const tuple<int,int> & );
    void setValor(double);
    void setProprietario(string);
    
    string getEndereco() const;
    tuple<int,int> getProporcaoTerreno() const;
    bool isPremium() const;
    double getValor() const;
    string getProprietario() const;

    //Demais métodos 
    void overview() const;
    void efetuarVenda(Sims &);

    //métodos statics
    inline static int getNumSimsHouses(){ return numEnderecos;};
    inline static double getMinValorPremiumHouse(){ return MINVALORPREMIUM;};

    static void mostrarVizinhanca();
  private:

    tuple<int,int> proporcaoTerreno;
    bool premium;
    double valor; // em simCash
    string proprietario;

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