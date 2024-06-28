#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Film.hpp"
#include "Usuari.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Plataforma {
    // Tipus de mòdul: dades
    // Descripció del tipus: Representa una plataforma de registre de valoracions
    // de films que fan els usuaris. Una plataforma té un nom, està formada per un conjunt
    // d'usuaris i un conjunt de films.

public:

    // ESPECIFICACIÓ DE LA CLASSE PLATAFORMA
    // (especificació Pre/Post de tots els mètodes)


    // Constructors
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, sense films i sense usuaris.
    Plataforma();
    
    // Pre: cert
    // Post: el resultat és una Plataforma igual a p.
    Plataforma(const Plataforma &p);
    
    // Pre: cert
    // Post: el resultat és una Plataforma amb nom a, sense films i sense usuaris.
    Plataforma(const string &a);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, amb f films, i sense usuaris.
    Plataforma(const vector<Film> &f);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, sense films i amb u usuaris.
    Plataforma(const vector<Usuari> &u);
    
    // Pre: cert
    // Post: el resultat és una Plataforma sense nom, amb f films, i amb u usuaris.
    Plataforma(const vector<Film> &f, const vector<Usuari> &u);
    
    // Pre: cert
    // Post: el resultat és una Plataforma amb nom a, amb f films, i amb u usuaris.
    Plataforma(const string &a, const vector<Film> &f, const vector<Usuari> &u);
    
    // Pre: cert
    // Post: retorna un plataforma igual a p
    Plataforma& operator=(const Plataforma &p);

    // Destructor
    
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
    ~Plataforma();
                
    // Consultors
    
    // Pre: cert
    // Post: retorna el nom de la plataforma
    string nomPlataforma() const;
    
    // Pre: cert
    // Post: retorna un vector amb tots els films que conte la plataforma
    vector<Film> llistaFilms() const;
    
    // Pre: cert
    // Post: retorna un vector amb tots els usuaris que conté la plataforma
    vector<Usuari> llistaUsuaris() const;
    
    // Pre: g no está buit i mida de films > 0
    // Post: retorna un vector amb els films de la plataforma, dels quals el seu gènere coincideix amb l'especificat a g.
    vector<Film> llistaFilmsGenere(const string &g) const;
    
    // Pre: mida de films > 0
    // Post: retorna el film de la plataforma amb la millor valoració mitjana.
    Film millorFilm() const;
    
    // Pre: mida de films > 0
    // Post: retorna un vector amb els tots films de plataforma, ordenats per mitjana de valoracions, i en cas de ser iguals, lexicogràficament
    vector<Film> llistaFilmsOrdenats() const;
    
    // Pre: n > 0 i mida de films > 0
    /* Post: retorna un vector amb dels n films de la plataforma amb les millors valoracions mitjanes, en ordre de millor a pitjor. En cas d'empat, l'ordre és 
    * lexcogràfic */
    vector<Film> millorsFilms(const int &n) const;
    
    // Pre: f no està buit i mida de films > 0
    // Post: retorna true si a la plataforma existeix algun film de nom f
    bool existeixFilm(const string &f) const;
    
    // Pre: g no está buit i mida de films > 0
    // Post: retorna true si a la plataforma existeix algun film amb gènere g
    bool existeixGenere(const string &g) const;
    
    // Pre: u no està buit i mida d'usuaris > 0
    // Post: retorna true si a la plataforma existeix algun usuari de nom u
    bool existeixUsuari(const string &u) const;
    
    // Pre: cert
    // Post: retorna true si la plataforma conté algun film
    bool hiHaFilms() const;
    
    // Pre: cert
    // Post: retorna true si la plataforma conté algun usuari
    bool hiHaUsuaris() const;
    
    // Modificadors
    
    // Pre: 1 <= n >= 5 i mida d'usuaris > 0
    /* Post: calcula la valoració mitjana d'aquell film que el seu nom correspon a l'string f, afegint la valoració en forma de l'enter n, aportada per 
     * l'usuari u.
     * També s'augmenten en 1 el nombre de valoracions d'aquest film, i el nombre de valoracions enregistrades d'aquell usuari que el seu nom correspon a 
     * l'string u.
    */
    void enregistrarValoracio(const string &u, const string &f, const int &n);
    
    // Pre: mida d'usuaris > 0
    // Post: Assgina els identificadors dels usuaris, en ordre de registre (els identificadors són enters > 0, i s'assignen en ordre consecutiu).
    void assignaIdentificadors();
                
    // Lectura i escriptura
    
    // Pre: mida d'usuaris > 0
    // Post: s'han escrit els atributs de la Plataforma p al canal estandard de sortida
    friend ostream& operator<<(ostream &os, const Plataforma &p);
    
    // Pre: cert
    // Post: la plataforma p passa a tenir els atributs llegits del canal estandard d'entrada
    friend istream& operator>>(istream &is, Plataforma &p);

private:

    // Implementació de la classe Plataforma 
    // (definició del tipus i nom de cada atribut)
    string nom;
    vector<Film> films; // Para detectar si la pelicula existe, antes de hacer push al vector, i augmentar en 1 la variable del id, usar los consultores.
    vector<Usuari> usuaris; // Para detectar si el usuario existe, antes de hacer push al vector, i augmentar en 1 la variable del id, usar los consultores.
};
#endif
