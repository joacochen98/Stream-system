#include "../include/Fabrica.h"
#include "../include/ControladorPartida.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorVideojuego.h"

Fabrica::Fabrica() {
};

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstancia() {
	if (instancia == NULL) instancia = new Fabrica();
	return instancia;
};

void Fabrica::releaseInstancia() {
	if ( instancia != NULL) {
		delete instancia;
		instancia = NULL;
	};
};

IPartida* Fabrica::getIPartida() {
	return ControladorPartida::getInstancia();
};

IUsuario* Fabrica::getIUsuario() {
	return ControladorUsuario::getInstancia();
};

IVideojuego* Fabrica::getIVideojuego() {
	return ControladorVideojuego::getInstancia();
};

Fabrica::~Fabrica() {
};