#ifndef SIMSGAME_H
#define SIMSGAME_H
// A classe é protegida contra inclusões múltiplas em outros arquivos usando a diretiva de pré-processamento
#include <map>
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include <vector>
using std::vector;

#include "Data.h"
#include "Sims.h"

class SimsGame 
{
    friend ostream &operator<<(ostream &, const SimsGame &);

    public:
        // construtores e destrutores sempre começam a parte pública da classe
        SimsGame( int dia=1, int mes=1, int ano=2010); // Construtor-> método chamado pra inicializar os atributos a classe
        SimsGame( map<string, long int>& infosGame); // declarando o construtor com parâmetros. 
        SimsGame( const SimsGame & ); //construtor de cópia
        ~SimsGame();//Destrutor -> relacionado a desalocaçao de memória 

        // declarando get e set -> acesso seguro na alteração dos atributos

        inline long int getIdUsuario(){ return IDUSUARIO;};
        inline void showDataNascimento(){ DATANASCIMENTO.print();};
        static long int gerarIdAleatorio();
        void setEstiloJogo();
        inline int getEstiloJogo() const { return estiloJogo;};

        //pra manipulação da composição e vector de sims
        void printSimsList( ) const;
        void addSim( const Sims & );
        void deleteLastSim( );

        // operadores
        const SimsGame &operator=(const SimsGame &);  // assign SimsGame
        int operator==(const SimsGame &) const; // compare equal
        int operator!=(const SimsGame &) const; // compare !equal
        bool operator!() const;

    private:        
    
        const long int IDUSUARIO;
        const Data DATANASCIMENTO; //Dependendo do ano de nascimento escolhido, o estilo de jogo vai ser diferente dependendo da faixa etária: criança, adolescente, adulto ou idoso
        int estiloJogo;
        vector< Sims * > simsList;
};

#endif // SIMSGAME_H