#pragma once

#include <exception>

class Vecteur
{

    int capa;
    int s;
    double * tableau;

    public:
        Vecteur(int = 10);
        Vecteur(const Vecteur&);
        ~Vecteur();

        int capacity() const;
        int size() const;
        void push_back(double);

        double operator[](int) const;

        class OutOfRangeException : public std::exception {
             virtual const char * what() const noexcept;
        };
};
