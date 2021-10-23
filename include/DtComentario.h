#ifndef _DTCOMENTARIO_H
#define _DTCOMENTARIO_H
#include "../include/DtFechaHora.h"


#include <string>



using std::string;

class DtComentario{
	
	private:
		// Atributos
		string autor;
		string texto;
		int id;
		DtFechaHora* fechaComentario;

	public:
		// Constructores y Destructores
		DtComentario(string autor, string texto, int id, DtFechaHora* fechacomentario);
		~DtComentario();

		// Getters
		string getAutor();
		string getTexto();
		int getId();
		DtFechaHora* getFechaHora();
};
#endif