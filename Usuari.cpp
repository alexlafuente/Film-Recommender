#include "Usuari.hpp"
#include "Film.hpp"

// IMPLMENTACIÓ DE LA CLASSE USUARI
// (implementació del codi de tots els mètodes especificats en el fitxer Usuari.hpp)

// Pre: cert
// Post: el resultat és un usuari amb sobrenom buit, amb identificador 0 i sense cap valoració enregistrada.
Usuari::Usuari(){
    nickname = "";
    id = 0;
    numval = 0;
}

// Pre: cert
// Post: el resultat és un usuari igual a u.
Usuari::Usuari(const Usuari &u){
    (*this) = u;
}

// Pre: cert
// Post: el resultat és un usuari amb sobrenom a, amb identificador 0 i sense cap valoració enregistrada.
Usuari::Usuari(const string &a){
    nickname = a;
    id = 0;
    numval = 0;   
}

// Pre: cert
// Post: el resultat és un usuari amb sobrenom a, amb identificador i, amb 0 valoracions enregistrades.
Usuari::Usuari(const string &a, const int &i){
    nickname = a;
    id = i;
    numval = 0;
}

// Pre: cert
// Post: retorna un Usuari igual a u.
Usuari& Usuari::operator=(const Usuari &u){
    this->id = u.id;
    this->nickname = u.nickname;
    this->numval = u.numval;
    return *this;
}

// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Usuari::~Usuari(){
}

// Pre: cert
// Post: retorna l'identificador de l'usuari.
int Usuari::identificador() const{
    return id;
}

// Pre: cert
// Post: retorna el sobrenom de l'usuari.
string Usuari::sobrenom() const{
    return nickname;
}

// Pre: cert
// Post: retorna el nombre de valoracions enregistrades per l'usuari.
int Usuari::valoracions() const{
    return numval;
}

// Pre: cert
// Post: el nombre de valoracions enregistrades augmenta en 1
void Usuari::augmentaValoracions(){
    ++numval;
}

// Pre: cert
// Post: s'assigna l'identificador i a l'usuari.
void Usuari::assignaIdentificador(const int &i){
    id = i;
}

// Pre: cert
// Post: s'han escrit els atributs de l'Usuari u al canal estandard de sortida
ostream& operator<<(ostream &os, const Usuari &u){
    os << " " << u.id << " | " << u.nickname << " | " << u.numval << endl;
    return os;
}

// Pre: cert
// Post: l'Usuari u passa a tenir els atributs llegits del canal estandard d'entrada
istream& operator>>(istream &is, Usuari &u){
    is >> u.nickname;
    return is;
}