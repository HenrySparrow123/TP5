#include "Chaine.hpp"
#include <cstring>

int Chaine::getCapacite() const
{
    return capa;
}

char * Chaine::c_str() const
{
    return c_string;
}

void Chaine::afficher() const
{
    for (int i = 0; i<capa; i++) std::cout << c_string[i];
    std::cout << std::endl;
}

void Chaine::afficher(std::stringstream& ss) const
{
    for (int i = 0; i<capa; i++) 
    {
        ss << c_string[i];
        std::cout << c_string[i];
    }
    std::cout << std::endl;
}

Chaine::Chaine() : capa(-1), c_string(nullptr) {}

/*Chaine::Chaine(char * text) : capa(strlen(text))
{
    c_string = new char[capa];
    strcpy(c_string,text);
}*/

Chaine::Chaine(const Chaine& chaine_a_copier) : capa(chaine_a_copier.capa),
c_string(new char[capa])
{
    strcpy(c_string,chaine_a_copier.c_string);
}

Chaine::Chaine(const char * text) : capa(strlen(text))
{
    c_string = new char[capa];
    strcpy(c_string,text);
}

Chaine::Chaine(int capacite) : capa(capacite)
{
     c_string = new char[1];
     strcpy(c_string,"");
}

/*const std::stringstream& Chaine::operator2<<(std::stringstream& flux)
{
        flux << this->c_string;
        return flux;    
}*/

const std::stringstream& Chaine::operator<<(std::stringstream& flux)
{
        for (int i =0; i<this->capa;i++) flux << this->c_string[i];
        return flux;    
}

const Chaine& Chaine::operator=(const Chaine& s2)
{
    if (this != &s2)
    {
        this->capa = s2.capa;
        this->c_string = new char[capa];
        strcpy(this->c_string,s2.c_string);
    }

    return *this;
}

char& Chaine::operator[](int index)
{
    if ( index < 0) throw (Chaine::OutOfRangeException());
    else if ( index >= capa) throw (std::bad_alloc());
    else return this->c_string[index];
}

const char& Chaine::operator[](int index) const
{
    return this->c_string[index];
}

const char * Chaine::OutOfRangeException::what() const noexcept
{
    return "Hors domaine.";
}