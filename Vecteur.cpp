#include <iostream>
#include <cstring>
#include "Vecteur.hpp"

Vecteur::Vecteur(int taille) : capa(taille), s(0), tableau(new double[capa])
{
}

Vecteur::Vecteur(const Vecteur& vecteur_bis):
    capa(vecteur_bis.capa),
    s(vecteur_bis.s),
    tableau(new double[capa])
{
    memcpy(tableau, vecteur_bis.tableau, vecteur_bis.size()*sizeof(double));
}

Vecteur::~Vecteur()
{
    delete [] tableau;
}

int Vecteur::capacity() const
{
    return capa;
}

int Vecteur::size() const
{
    return s;
}

void Vecteur::push_back(double x)
{
    if (size() == capacity())
    {
        capa *= 2;

        double * temp_tableau = new double[capa];
        memcpy(temp_tableau, tableau, size()*sizeof(double));

        delete [] tableau;
        tableau = temp_tableau;
    }
    
    tableau[size()] = x;
    ++s;
}

double Vecteur::operator[](int index) const
{
    if (index < 0)
    {
        throw Vecteur::OutOfRangeException();
    }
    else if (index > capa)
    {
        throw std::bad_alloc();
    }
    else
    {
        return tableau[index];
    }
    
   
}

const char * Vecteur::OutOfRangeException::what() const noexcept
{
    return "Erreur de domaine !";
}