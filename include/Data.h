/* 
 * File:   Data.h
 * Author: Deitel
 *
 * Created on 9 de Junho de 2012, 14:47
 */

#ifndef DATA_H
#define	DATA_H

class Data 
{
public:
    
    Data( int = 1, int = 1, int = 1900 );
    
    void print() const;
    
    inline int getDia() const { return dia;};
    inline int getMes() const { return mes;};
    inline int getAno() const { return ano;};
    bool operator==(const Data& other) const;
    bool operator!=(const Data& other) const;
    static Data getDataAtual();
    
private:
    
    int mes;
    int dia;
    int ano;
    
    int VerificaDia( int ) const;
};

#endif	/* DATA_H */