#include "Plataforma.hpp"

// IMPLMENTACIÓ DE LA CLASSE PLATAFORMA
// (implementació del codi de tots els mètodes especificats en el fitxer Plataforma.hpp)

// Pre: cert
// Post: el resultat és una Plataforma sense nom, sense films i sense usuaris.
Plataforma::Plataforma(){
    nom = "";
    films = vector<Film>(0);
    usuaris = vector<Usuari>(0);
}

// Pre: cert
// Post: el resultat és una Plataforma igual a p.
Plataforma::Plataforma(const Plataforma &p){
    (*this) = p;
}

// Pre: cert
// Post: el resultat és una Plataforma amb nom a, sense films i sense usuaris.
Plataforma::Plataforma(const string &a){
    nom = a;
    films = vector<Film>(0);
    usuaris = vector<Usuari>(0);
}

// Pre: cert
// Post: el resultat és una Plataforma sense nom, amb f films, i sense usuaris.
Plataforma::Plataforma(const vector<Film> &f){
    nom = "";
    this->films = f;
    usuaris = vector<Usuari>(0);
}
// Pre: cert
// Post: el resultat és una Plataforma sense nom, sense films i amb u usuaris.
Plataforma::Plataforma(const vector<Usuari> &u){
    nom = "";
    films = vector<Film>(0);
    this->usuaris = u;
}

// Pre: cert
// Post: el resultat és una Plataforma sense nom, amb f films, i amb u usuaris.
Plataforma::Plataforma(const vector<Film> &f, const vector<Usuari> &u){
    nom = "";
    this->films = f;
    this->usuaris = u;
}

// Pre: cert
// Post: el resultat és una Plataforma amb nom a, amb f films, i amb u usuaris.
Plataforma::Plataforma(const string &a, const vector<Film> &f, const vector<Usuari> &u){
    this->nom = a;
    this->films = f;
    this->usuaris = u;
}

// Pre: cert
// Post: retorna una plataforma igual a p
Plataforma& Plataforma::operator=(const Plataforma &p){
    this->nom = p.nom;
    this->films = p.films;
    this->usuaris = p.usuaris;
    return *this;
}

// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat
Plataforma::~Plataforma(){
}

// Pre: cert
// Post: retorna el nom de la plataforma
string Plataforma::nomPlataforma() const{
    return nom;
}

// Pre: cert
// Post: retorna un vector amb tots els films que conte la plataforma
vector<Film> Plataforma::llistaFilms() const{
    return films;
}

// Pre: cert
// Post: retorna un vector amb tots els usuaris que conté la plataforma
vector<Usuari> Plataforma::llistaUsuaris() const{
    return usuaris;
}

// Pre: g no está buit i mida de films > 0
// Post: retorna un vector amb els films de la plataforma, dels quals el seu gènere coincideix amb l'especificat a g.
vector<Film> Plataforma::llistaFilmsGenere(const string &g) const{
    vector<Film> gaux;
    for(int i = 0; i < int(films.size()); ++i){
        if (films[i].genereFilm() == g){
            gaux.push_back(films[i]);
        }
    }
    return gaux;
}

// Pre: mida de films > 0
// Post: retorna el film de la plataforma amb la millor valoració mitjana.
Film Plataforma::millorFilm() const{
    Plataforma paux = (*this);
    paux.films = llistaFilmsOrdenats();
    return paux.films[0];
}

// Pre: mida de films > 0
// Post: retorna un vector amb els tots films de plataforma, ordenats per mitjana de valoracions, i en cas de ser iguals, lexicogràficament
vector<Film> Plataforma::llistaFilmsOrdenats() const{
    vector<Film> millors;
    vector<Film> faux = films;
    vector<Film> faux2(2); 
    // Insertion sort
    for(int i = 1; i < int(faux.size()); ++i){
        Film x = faux[i];
        int j = i;
        while(j > 0 and faux[j - 1].punts() < x.punts()){
            if(faux[j - 1].punts() < x.punts()){
                faux[j] = faux[j - 1];
            }
            --j;
        }
        faux[j] = x;
    }

    for(int i = 1; i < int(faux.size()); ++i){
        Film x = faux[i];
        int j = i;
        while(j > 0 and faux[j - 1].punts() == x.punts()){
           if(faux[j - 1].punts() == x.punts()){
               if(faux[j - 1].nomFilm() > faux[j].nomFilm()){
                   faux2[0] = faux[j-1];
                   faux2[1] = faux[j];
                   faux[j-1] = faux2[1];
                   faux[j] = faux2[0];
               }
            }
            --j;
        }
    }
    return faux;
}

// Pre: n > 0 i mida de films > 0
/* Post: retorna un vector amb dels n films de la plataforma amb les millors valoracions mitjanes, en ordre de millor a pitjor. En cas d'empat, l'ordre és 
 * lexcogràfic */
vector<Film> Plataforma::millorsFilms(const int &n) const{
    vector <Film> faux;
    vector<Film> fordenats = (*this).llistaFilmsOrdenats();
    if(n > int(films.size())){
        faux = fordenats;
        // for(int i = 0; i < int(films.size()); ++i){}
    }
    else{
        faux = vector<Film>(n);
        for(int i = 0; i < n; ++i){
            faux[i] = fordenats[i];
        }
    }
    return faux;
}

// Pre: f no està buit i mida de films > 0
// Post: retorna true si a la plataforma existeix algun film de nom f
bool Plataforma::existeixFilm(const string &f) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(films.size())){
        if(f == films[i].nomFilm()){
            trobat = true;
        }
        else{
          ++i;  
        }
    }
    return trobat;
}

// Pre: g no está buit i mida de films > 0
// Post: retorna true si a la plataforma existeix algun film amb gènere g
bool Plataforma::existeixGenere(const string &g) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(films.size())){
        if(g == films[i].genereFilm()){
            trobat = true;
        }
        else{
            ++i; 
        }
    }
    return trobat;
}

// Pre: u no està buit i mida d'usuaris > 0
// Post: retorna true si a la plataforma existeix algun usuari de nom u
bool Plataforma::existeixUsuari(const string &u) const{
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(usuaris.size())){
        if(u == usuaris[i].sobrenom()){
            trobat = true;
        }
        else{
            ++i;  
        }   
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si la plataforma conté algun film
bool Plataforma::hiHaFilms() const{
    bool trobat = false;
    if(int(films.size()) != 0){
        trobat = true;
    }
    return trobat;
}

// Pre: cert
// Post: retorna true si la plataforma conté algun usuari
bool Plataforma::hiHaUsuaris() const{
    bool trobat = false;
    if(int(usuaris.size()) != 0){
        trobat = true;
    }
    return trobat;
}

// Pre: 1 <= n >= 5 i mida d'usuaris > 0
/* Post: calcula la valoració mitjana d'aquell film que el seu nom correspon a l'string f, afegint la valoració en forma de l'enter n, aportada per l'usuari u.
* També s'augmenten en 1 el nombre de valoracions d'aquest film, i el nombre de valoracions enregistrades d'aquell usuari que el seu nom correspon a 
* l'string u.
*/
void Plataforma::enregistrarValoracio(const string &u, const string &f, const int &n){
    bool trobat = false;
    int i = 0;
    while(not trobat and i < int(usuaris.size())){
        if(u == usuaris[i].sobrenom()){
            trobat = true;
            usuaris[i].augmentaValoracions();
        }
        else{
            ++i;
        }
    }
    trobat = false;
    i = 0;
    while(not trobat and i < int(films.size())){
        if(f == films[i].nomFilm()){
            trobat = true;
            films[i].novaValoracio(n);
        }
        else{
            ++i;
        }
    }
}

// Pre: mida d'usuaris > 0
// Post: Assgina els identificadors dels usuaris, en ordre de registre (els identificadors són enters > 0, i s'assignen en ordre consecutiu).
void Plataforma::assignaIdentificadors(){
    for(int i = 0; i < int(usuaris.size()); ++i){
        usuaris[i].assignaIdentificador(i + 1);
    }
}

// Pre: mida de films i d'usuaris > 0
// Post: s'han escrit els atributs de la Plataforma p al canal estandard de sortida
ostream& operator<<(ostream &os, const Plataforma &p){
    os << "Films a " << p.nom << " (ordre d'alta):" << endl;
    for(int i = 0; i < int(p.films.size()); ++i){
        os << p.films[i];
    }
    os << "Usuaris de " << p.nom << " (ordre d'alta):" << endl;
    for(int i = 0; i < int(p.usuaris.size()); ++i){
        os << p.usuaris[i];
    }
    return os;
}

// Pre: cert
// Post: la plataforma p passa a tenir els atributs llegits del canal estandard d'entrada
istream& operator>>(istream &is, Plataforma &p){
    is >> p.nom;
    int n;
    is >> n;
    for(int i = 0; i < n; ++i){
        Film f;
        is >> f;
        if(p.existeixFilm(f.nomFilm())){
            cout << " Error: " << f.nomFilm() << " film ja existent a " << p.nom << ", no s'ha afegit" << endl;
        }
        else{
            p.films.push_back(f);
        }
    }
    is >> n;
    for(int i = 0; i < n; ++i){
        Usuari u;
        is >> u;
        if(p.existeixUsuari(u.sobrenom())){
            cout << " Error: " << u.sobrenom() << " usuari ja existent a " << p.nom << ", no s'ha afegit" << endl;
        }
        else{
            p.usuaris.push_back(u);
            p.usuaris[int(p.usuaris.size()) - 1].assignaIdentificador(int(p.usuaris.size()));
        }
    }
    return is;
}
