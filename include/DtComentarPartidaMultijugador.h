#ifndef _DTCOMENTARPARTIDAMULTIJUGADOR_H
#define _DTCOMENTARPARTIDAMULTIJUGADOR_H
#include <string>
#include <set>

using namespace std;

class DtComentarPartidaMultijugador{
	
	private:
		// Atributos
		int identificador;
		string nombreVideojuego;
		string nicknameJugadorInicial;
		set<string> nicknameJugadoresUnidos;

	public:
		// Constructores y Destructores
		DtComentarPartidaMultijugador(int id, string nombrevideojuego,string nicknamejugador,
		set<string> nickanmesJugadores);
		~DtComentarPartidaMultijugador();

		// Getters
		int getIdentificador();
		string getNombreVideojuego();
		string getNicknameJugadorInicial();
		set<string> getNicknameJugadoresUnidos();
};
#endif
