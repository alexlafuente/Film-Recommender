#include "Film.hpp"
#include "Usuari.hpp"
#include "Plataforma.hpp"
#include <iostream>
using namespace std;

int main(){
	// llegir_dades_plataforma (nom, films i usuaris)
	Plataforma p;
	cin >> p;
	// llegir_opció
	string opcio;
	cin >> opcio;
	// mentre opció != acabar:
	while(opcio != "acabar"){
	//	tractar_opció
		if(opcio == "mostrarFilms"){
			cout << "Films a " << p.nomPlataforma() << " (ordre d'alta):" << endl;
			if(not p.hiHaFilms()){
				cout << " No hi ha films enregistrats a " << p.nomPlataforma() << endl;
			}
			else{
				vector<Film> faux = p.llistaFilms();
				for(int i = 0; i < int(faux.size()); ++i){
					cout << faux[i];
				}
			}
		}
		else if(opcio == "mostrarUsuaris"){
			cout << "Usuaris de " << p.nomPlataforma() << " (ordre d'alta):" << endl;
			if(not p.hiHaUsuaris()){
				cout << " No hi ha usuaris enregistrats a " << p.nomPlataforma() << endl;
			}
			else{
				vector<Usuari> paux = p.llistaUsuaris();
				for(int i = 0; i < int(paux.size()); ++i){
					cout << paux[i];
				}
			}
		}
		else if(opcio == "mostrarFilmsGenere"){
			string genere;
			cin >> genere;
			cout << "Films del gènere " << genere << " a " << p.nomPlataforma() << ":" << endl;
			if(not p.hiHaFilms()){
				cout << " No hi ha films enregistrats a " << p.nomPlataforma() << endl;
			}
			else{
				if(not p.existeixGenere(genere)){
					cout << " No hi ha films del gènere " << genere << " a " << p.nomPlataforma() << endl;
				}
				else{
					vector<Film> faux = p.llistaFilmsGenere(genere);
					for(int i = 0; i < int(faux.size()); ++i){
						cout << faux[i];
					}
				}
			}
		}
		else if(opcio == "enregistrarValoracio"){
			cout << "Nova valoració:" << endl;
			string unom;
			cin >> unom;
			string fnom;
			cin >> fnom;
			int fval;
			cin >> fval;
			if(not p.existeixUsuari(unom)){
				cout << " Error: " << unom << " usuari no enregistrat a " << p.nomPlataforma() << endl;
			}
			else{
				if(not p.existeixFilm(fnom)){
					cout << " Error: " << fnom << " film no enregistrat a " << p.nomPlataforma() << endl;
				}
				else{
					if(fval < 1 or fval > 5){
						cout << " Error: " << fval << " nombre de punts no vàlid, no s'ha afegit" << endl;
					}
					else{
						p.enregistrarValoracio(unom, fnom, fval);
						cout << " " << unom << ", " << fnom << ", " << fval << endl;
					}
				}
			}	
		}
		else if(opcio == "recomanarMillorFilm"){
			cout << "Film recomanat a " << p.nomPlataforma() << ":" << endl;
			if(not p.hiHaFilms()){
				cout << " No hi ha films amb valoracions a " << p.nomPlataforma() << endl;
			}
			else{
				cout << p.millorFilm();
			}
		}
		else if(opcio == "mostrarMillorsFilms"){
			int n;
			cin >> n;
			cout << "Films amb millors valoracions a " << p.nomPlataforma() << " (" << n << " millors):" << endl;
			if(n < 1){
				cout << " Error: " << n << " valor no vàlid" << endl;
			}
			else if(not p.hiHaFilms()){
				cout << " No hi ha films amb valoracions a " << p.nomPlataforma() << endl;
			}
			else{
				vector<Film> faux = p.millorsFilms(n);
				for(int i = 0; i < int(faux.size()); ++i){
					cout << faux[i];
				}
			}
		}
		else{
			cout << "Error: Opció no vàlida" << endl;
		}
	//  llegir_opció
		cin >> opcio;
	}
}
