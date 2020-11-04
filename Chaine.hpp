#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Chaine  {

    int capa;
    char * c_string;

    public :
        Chaine();
        //Chaine(char *);
        Chaine (const char *);
        Chaine (int);
        Chaine (const Chaine&);
        void afficher() const;
        void afficher(std::stringstream&) const;
        int getCapacite() const;
        char * c_str() const;
        const std::stringstream& operator<<(std::stringstream&);
        const Chaine& operator=(const Chaine& s2);
        char& operator[](int);
        const char& operator[](int) const;

        class OutOfRangeException : public std::exception
        {
            virtual const char * what() const noexcept;
        };
};

#endif
