#ifndef _FABRICA_H
#define _FABRICA_H


#include "IPartida.h"
#include "IUsuario.h"
#include "IVideojuego.h"
#include <string>


class Fabrica {
	
	private:
		Fabrica();
		static Fabrica* instancia;
		~Fabrica();
	public:
		static Fabrica* getInstancia();
		static void releaseInstancia();
		IPartida* getIPartida();
		IUsuario* getIUsuario();
		IVideojuego* getIVideojuego();
		
};
#endif
