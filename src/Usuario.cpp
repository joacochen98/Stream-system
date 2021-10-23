#include "../include/Usuario.h"
#include "../include/Jugador.h"
#include "../include/Desarrollador.h"

Usuario::Usuario(){
};

Usuario::Usuario(string email, string contrasenia) {
  this->email = email;
  this->contrasenia = contrasenia;
};

string Usuario::getContrasenia() {
  return this->contrasenia;
};

string Usuario::getEmail() {
  return this->email;
};

Usuario::~Usuario() {
};

ostream& operator<< (ostream& out, Usuario* &u){
	if (dynamic_cast<Jugador*>(u) != NULL) {
		Jugador* j = dynamic_cast<Jugador*>(u);
		cout << *j << endl;            
    }
    else {
    	Desarrollador* d = dynamic_cast<Desarrollador*>(u);
    	cout << *d << endl;
    }
	return out;
};