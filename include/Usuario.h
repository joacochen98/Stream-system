#ifndef _USUARIO_H
#define _USUARIO_H

#include <string>

using namespace std;

class Usuario
{
private:
	string email;
	string contrasenia;

public:
	Usuario();
	Usuario(string email, string contrasenia);
	string getEmail();
	string getContrasenia();
	virtual ~Usuario();
};

ostream& operator<< (ostream& out, Usuario* &u);

#endif