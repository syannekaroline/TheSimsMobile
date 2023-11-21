#include "Data.h"

#include <iostream>
using std::cout;

Data::Data(int d, int m, int a) 
{
    if ( m > 0 && m <= 12 ) // validate the month
        mes = m;
    if ( a < 0 )
        ano = 1900;
    else
        ano = a;
   
    dia = VerificaDia(d);

}

void Data::print() const
{
   cout << dia << '/' << mes << '/' << ano;
   
}

int Data::VerificaDia(int diaTeste) const
{
    static const int diasPorMes[ 13 ] = 
       { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] )
        return diaTeste;
    
    if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 ||
            ( ano % 4 == 0 && ano % 100 != 0 ) ) ) 
        return diaTeste;
    
    cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
    return 1;
}

Data Data::getDataAtual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int diaAtual = now->tm_mday;
    int mesAtual = now->tm_mon + 1;  // tm_mon começa de 0
    int anoAtual = now->tm_year + 1900;  // tm_year é o ano desde 1900

    return Data(diaAtual, mesAtual, anoAtual);
}

bool Data::operator==(const Data& other) const {
    return (dia == other.dia && mes == other.mes && ano == other.ano);
}

bool Data::operator!=(const Data& other) const {
    return !(*this == other);
}
