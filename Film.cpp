#include "Film.hpp"
#include <iomanip>

// IMPLMENTACIÓ DE LA CLASSE FILM
// (implementació del codi de tots els mètodes especificats en el fitxer Film.hpp)

// Constructors

// Pre: cert
// Post: el resultat és un film sense nom, génere i amb 0 valoracions i puntuacio 0.
Film::Film(){
    nom = "";
    genere = "";
    puntuacio = 0.0;
    nval = 0;
}

// Pre: cert
// Post: el resultat és un film igual a f.
Film::Film(const Film &f){
    (*this) = f;
}

// Pre: cert
// Post: el resultat és un film amb nom a, de génere b i amb 0 valoracions i puntuacio 0.
Film::Film(const string &a, const string &b){
    nom = a;
    genere = b;
    puntuacio = 0.0;
    nval = 0;
}

// Pre: cert
// Post: el resultat és un film amb nom a, de génere b i amb puntuacio c i d valoracions.
Film::Film(const string &a, const string &b, const double &c, const int &d){
    nom = a;
    genere = b;
    puntuacio = c;
    nval = d;
}

// Pre: cert
// Post: retorna un film igual a f
Film& Film::operator=(const Film &f){
    this->nom = f.nom;
    this->genere = f.genere;
    this->puntuacio = f.puntuacio;
    this->nval = f.nval;
    return *this;
}

// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Film::~Film(){
}

// Consultors

// Pre: cert
// Post: retorna el títol del film
string Film::nomFilm() const{
    return nom;
}

// Pre: cert
// Post: Retorna el gènere del film
string Film::genereFilm() const{
    return genere;
}

// Pre: cert
// Post: retorna la puntuació del film
double Film::punts() const{
    return puntuacio;
}

// Pre: cert
// Post: retorna el nombre de vots del film
int Film::numvots() const{
    return nval;
}

// Pre: cert
// Post: retorna si f està millor valorat.
bool Film::millorValorat(const Film &f) const{
    bool millor = false;
    if(this->puntuacio > f.puntuacio){
        millor = true;
    }
    else if(this->puntuacio == f.puntuacio){
        if(this->nval > f.nval){
            millor = true;
        }
    }
    return millor;
}

// Modificadors

// Pre: 1 <= novaval >= 5.
// Post: puntuacio conté la puntuació mitjana contant la nova valoració, i nval augmenta en 1.
void Film::novaValoracio(const int &novaval){
    puntuacio = ((puntuacio*nval + novaval)/(nval + 1));
    ++nval;
}

// Lectura i escriptura

// Pre: cert
// Post: s'han escrit els atributs del Film f al canal estandard de sortida
ostream& operator<<(ostream &os, const Film &f){
    os << " (" << f.nom << ", " << f.genere << ", ";
    if(int(f.puntuacio * 10) % 10 == 0){
        os << f.puntuacio << ".0";
    }
    else{
        os << setprecision(2) << f.puntuacio;
    }
    os << ", " << f.nval << ")" << endl;
    return os;
}

// Pre: cert
// Post: el film f passa a tenir els atributs llegits del canal estandard d'entrada
istream& operator>>(istream &is, Film &f){
    is >> f.nom >> f.genere;
    return is;
}

