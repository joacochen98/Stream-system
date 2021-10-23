#include "../include/ControladorPartida.h"
#include "../include/Fabrica.h"
#include "../include/FechaHoraSistema.h"

ControladorPartida::ControladorPartida() { // Constructor
	this->IdGenerado = 0;
	map<int, Partida*> coleccionPartidas;
};

ControladorPartida* ControladorPartida::instancia = NULL;

ControladorPartida *ControladorPartida::getInstancia() {
	if (instancia == NULL) instancia = new ControladorPartida();
	return instancia;
};

// OPERACIONES SISTEMA

set<string> ControladorPartida::listarNombresVideojuegos() {
	Fabrica* fabrica = Fabrica::getInstancia();
  	IUsuario* interfazUsuario = fabrica->getIUsuario();
	Usuario* usuarioSesion = interfazUsuario->getUsuarioSesion();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	set<string> res = jugadorSesion->nombresVideojuegos();
	return res;
};

void ControladorPartida::setIdGenerado(int IdGenerado){
	this->IdGenerado = IdGenerado;
};

int ControladorPartida::getIdGenerado(){
	return this->IdGenerado;
};

void ControladorPartida::seleccionarVideojuegoSuscripcion(string nombreVideojuego) {
	this->nombreVideojuego = nombreVideojuego;
};

void ControladorPartida::continuarPartida(bool cont) {
	this->continuaPartida = cont;
};

set<DtInfoBasicaPartidaIndividual*> ControladorPartida::historialPartidasFinalizadas(string nombreVideojuegoSeleccionado) {
	Fabrica* fabrica = Fabrica::getInstancia();
  	IUsuario* interfazUsuario = fabrica->getIUsuario();
	Usuario* usuarioSesion = interfazUsuario->getUsuarioSesion();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	set<DtInfoBasicaPartidaIndividual*> res = jugadorSesion->infoPartidasFinalizadas(nombreVideojuegoSeleccionado);
	return res;
};

void ControladorPartida::ingresarPartida(int indentificador) {
	this->indentificador = indentificador;
};

void ControladorPartida::esPartidaEnVivo(bool enVivo) {
	this->enVivo = enVivo;
};

set<DtJugador*> ControladorPartida::listarNicknamesJugadores() {
	Fabrica* fabrica = Fabrica::getInstancia();
	IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
	Videojuego* videojuego = interfazVideojuego->obtenerVideojuego(this->nombreVideojuego);
	set<DtJugador*> res = videojuego->obtenerNicknamesJugadores();
	return res;
};

void ControladorPartida::agregarNicknamePartida(string nickname) {
	this->Nicknames.insert(nickname);
};

set<DtPartida*> ControladorPartida::obtenerInfoPartidas() {
	set<DtPartida*> res;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Jugador* JugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	res = JugadorSesion->obtenerInfoPartidas();
	return res;
};

void ControladorPartida::finalizarPartida(int indentificador) {
	map<int, Partida*>::iterator it;
	it = this->coleccionPartidas.find(indentificador);
	(it->second)->finalizarPartida();

};

void ControladorPartida::confirmarAltaPartida(bool tipoPartida) {
	int idGen = this->getIdGenerado() + 1; //se genera el id de la partida
	this->setIdGenerado(idGen);
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* interfazUsuario = fabrica->getIUsuario();
	Jugador* jugador = dynamic_cast<Jugador*>(interfazUsuario->getUsuarioSesion());
	IVideojuego* interfazVideojuego = fabrica->getIVideojuego();
	Videojuego* videojuego = interfazVideojuego->obtenerVideojuego(this->nombreVideojuego);
	string nicknameJugadorInicio = jugador->getNickname();
	FechaHoraSistema* fechaSistema = FechaHoraSistema::getInstancia();
	DtFechaHora* fechaComienzo = fechaSistema->getFechaHoraSistema();

	if (tipoPartida == true) {
		PartidaIndividual* partidaIndividual = new PartidaIndividual(idGen, fechaComienzo, videojuego, false, nicknameJugadorInicio, this->continuaPartida);
		if (this->continuaPartida == true) {
			partidaIndividual->setIdPartidaAnterior(this->indentificador);
		}
		this->coleccionPartidas.insert({idGen, partidaIndividual});
		jugador->agregarNuevaPartida(partidaIndividual);
		videojuego->agregarPartida(partidaIndividual);

	}
	else if (tipoPartida == false) {
		PartidaMultijugador* partidaMultijugador = new PartidaMultijugador(idGen, fechaComienzo, videojuego, false, nicknameJugadorInicio, enVivo);
		set<JugadorUnido*> jugadores;
		for (set<string>::iterator it = this->Nicknames.begin(); it != this->Nicknames.end() ; it++) {
			Jugador* jugadorUnir = interfazUsuario->buscarJugador(*it);
			JugadorUnido* jugadorUnido = new JugadorUnido(jugadorUnir);
			jugadores.insert(jugadorUnido);
		}
		partidaMultijugador->setJugadoresUnidos(jugadores);
		this->coleccionPartidas.insert({idGen, partidaMultijugador});
		jugador->agregarNuevaPartida(partidaMultijugador);
		videojuego->agregarPartida(partidaMultijugador);
	}
	videojuego->sumarCantPartidas();

};

void ControladorPartida::cancelar() {
	this->nombreVideojuego = "";
	this->indentificador = 0;
	this->continuaPartida = false;
	this->enVivo = false;
	this->Nicknames.clear();
};

map<int, DtAbandonarPartidaMultijugador *> ControladorPartida::obtenerInfoPartidasMultijugador() {
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iu = fabrica->getIUsuario();
	Usuario* usuarioSesion = iu->getUsuarioSesion();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	if (jugadorSesion == NULL) throw invalid_argument("No se ha iniciado sesion como Jugador\n");

	map<int, DtAbandonarPartidaMultijugador*> resultado;
	for (map<int, Partida*>::iterator it = this->coleccionPartidas.begin(); it != this->coleccionPartidas.end(); it++)
	{
		Partida* partida = it->second;
		if (!partida->getFinalizada())
		{
			PartidaMultijugador* partidaMultijugador = dynamic_cast<PartidaMultijugador*>(partida);
			if (partidaMultijugador != NULL)
			{
				if (partidaMultijugador->jugadorUnido(jugadorSesion->getNickname()))
				{

					if (!partidaMultijugador->jugadorAbandono(jugadorSesion->getNickname())){
						DtFechaHora* fechaComienzo = partidaMultijugador->getFechaComienzo();
						DtFechaHora* fechaComienzoResultado = new DtFechaHora(
							fechaComienzo->getDia(),
							fechaComienzo->getMes(),
							fechaComienzo->getAnio(),
							fechaComienzo->getHora(),
							fechaComienzo->getMinuto()
						);
						bool enVivo = partidaMultijugador->getEnVivo();
						DtPartida* dtPartida = partidaMultijugador->getDatosPartida();
						DtPartidaMultijugador* dtPartidaMulti = dynamic_cast<DtPartidaMultijugador*>(dtPartida);
						set<string> nicknamesJugadoresUnidos = dtPartidaMulti->getNicknameJugadoresUnidos();
						string jugadorInicio = partidaMultijugador->getNicknameJugadorInicio();
						string nombreVideojuego = partidaMultijugador->getVideojuego()->getNombre();

						DtAbandonarPartidaMultijugador* dt = new DtAbandonarPartidaMultijugador(
							fechaComienzoResultado,
							0,
							enVivo,
							it->first,
							0,
							nicknamesJugadoresUnidos,
							jugadorInicio,
							nombreVideojuego
						);
						resultado.insert({it->first, dt});
						delete dtPartida;
					}
				}
			}
		}
	};
	return resultado;
};

void ControladorPartida::abandonarPartidaMultijugador(int idPartida) {
	map<int,Partida*>::iterator it = this->coleccionPartidas.find(idPartida);
	if (it == this->coleccionPartidas.end()) {
		throw invalid_argument("La partida seleccionada no existe\n");
	};
	PartidaMultijugador* partidaMultijugador = dynamic_cast<PartidaMultijugador*>(it->second);
	if (partidaMultijugador == NULL) {
		throw invalid_argument("La partida seleccionada no es Multijugador\n");
	};
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iu = fabrica->getIUsuario();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(iu->getUsuarioSesion());
	if (jugadorSesion == NULL)
	{
		throw invalid_argument("No se ha iniciado sesion como Jugador\n");
	};
	partidaMultijugador->abandonarPartida(jugadorSesion->getNickname());
};

map<int, Partida*> ControladorPartida::getColeccionPartidas(){
	return this->coleccionPartidas;
};

ControladorPartida::~ControladorPartida(){
};

void ControladorPartida::agregarPartidaInterfaz(Partida* p){
	this->coleccionPartidas.insert({p->getIdPartida(), p});
};
