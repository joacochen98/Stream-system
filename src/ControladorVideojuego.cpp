#include "../include/ControladorVideojuego.h"
#include "../include/Puntaje.h"
#include "../include/Fabrica.h"
#include "../include/Desarrollador.h"
#include "../include/TotalHorasJugadas.h"
#include "../include/Genero.h"
#include "../include/TipoGenero.h"
#include "../include/CantidadTotalJugadores.h"
#include "../include/TotalHorasJugadas.h"

#include <exception>

const string MSJ_VID_NO_EXISTE = "El videojuego ingresado no esta en el Sistema";
const string MSJ_USUARIO_SESION_ERR = "No se ha iniciado sesion";
const string MSJ_JUGADOR_SESION_ERR = "No se ha iniciado sesion como Jugador";
const string MSJ_DESARROLLADOR_SESION_ERR = "No se ha iniciado sesion como Desarrollador";
const string MSJ_VID_SEL_ERR = "No se ha seleccionado un Videojuego";
const string MSJ_ESTADISTICA_NO_EXISTE = "La estadistica seleccionada no existe en el sistema";

#include <iostream>

ControladorVideojuego::ControladorVideojuego() {
	this->cargarEstadisticasSistema();
	this->datosCategoria = NULL;
};

ControladorVideojuego* ControladorVideojuego::instancia = NULL;

ControladorVideojuego *ControladorVideojuego::getInstancia() {
	if (instancia == NULL) instancia = new ControladorVideojuego();
	return instancia;
};

// OPERACIONES SISTEMA

void ControladorVideojuego::agregarNuevoVideojuego(string nombre, string descripcion, DtCosto* costos) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->costo = costos;
};

set<DtGenero*> ControladorVideojuego::listarGenero() {
	set<DtGenero*> res;
	map<string,Genero*>::iterator it;
	for (it = this->GeneroSis.begin(); it != this->GeneroSis.end(); it++) {
		DtGenero *aux = new DtGenero(it->second->getNombre(),it->second->getDescripcion(),it->second->getGenero());
		res.insert(aux);
	}
	return res;
};

void ControladorVideojuego::agregarGenero(string nombreGenero) {
	this->nombreGeneros.insert(nombreGenero);
};

set<DtPlataforma*> ControladorVideojuego::listarPlataformas() {
	set<DtPlataforma*> res;
	map<string,Plataforma*>::iterator it;
	for (it = this->PlataformaSis.begin(); it != this->PlataformaSis.end(); it++) {
		DtPlataforma *aux = new DtPlataforma(it->second->getNombre(),it->second->getDescripcion(),it->second->getPlataforma());
		res.insert(aux);
	}
	return res;

};
void ControladorVideojuego::agregarPlataforma(string nombrePlataforma) {
	this->nombrePlataformas.insert(nombrePlataforma);
};

set<DtCategoria*> ControladorVideojuego::listarCategorias() {
	set<DtCategoria*> res;
	map<string,Categoria*>::iterator it;
	for (it = this->CategoriaSis.begin(); it != this->CategoriaSis.end(); it++) {
		DtCategoria *aux = new DtCategoria(it->second->getNombre(), it->second->getDescripcion());
		res.insert(aux);
	}
	return res;
};

set<string> ControladorVideojuego::listarNombreTodasCategorias() {
	set<string> res;
	map<string,Categoria*>::iterator it;
	map<string,Genero*>::iterator it2;
	map<string,Plataforma*>::iterator it3;

	for (it = this->CategoriaSis.begin(); it != this->CategoriaSis.end(); it++) {
		res.insert(it->second->getNombre());
	}
	for (it2 = this->GeneroSis.begin(); it2 != this->GeneroSis.end(); it2++) {
		res.insert(it2->second->getNombre());
	}
	for (it3 = this->PlataformaSis.begin(); it3 != this->PlataformaSis.end(); it3++) {
		res.insert(it3->second->getNombre());
	}
	return res;
};

void ControladorVideojuego::agregarCategoria(string nombreCategoria) {
	this->nombreCategorias.insert(nombreCategoria);
};

void ControladorVideojuego::confirmarNuevoVideojuego() {
	Videojuego* nuevoVj = new Videojuego(this->nombre, this->descripcion, this->costo);
	this->VideojuegoSis.insert({nuevoVj->getNombre(),nuevoVj});
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);
	desarrolladorSesion->agregarVideojuegoPublicado(nuevoVj);

	if (usuarioSesion != NULL) {
		Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);
		desarrolladorSesion->agregarVideojuegoPublicado(nuevoVj);
	};
	set<Genero*> g = ControladorVideojuego::obtenerGeneros();
	set<Plataforma*> p = ControladorVideojuego::obtenerPlataformas();
	set<Categoria*> c = ControladorVideojuego::obtenerCategorias();

	nuevoVj->setGenPlatCat(g,p,c);

	ControladorVideojuego::borrarMemoriaSistema();
};

void ControladorVideojuego::cancelar() {
};

void ControladorVideojuego::cancelarCategoria() {
	if (this->datosCategoria != NULL)
	{
		delete this->datosCategoria;
		this->datosCategoria = NULL;
	};
	this->nombre = this->descripcion = "";

};

set<DtInfoSusc*> ControladorVideojuego::listarVidConSuscActivas() {
	set<DtInfoSusc*> res;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
	map<string, HistorialSuscripciones*> historialesJugador = jugadorSesion->getHistoriales_de_suscripciones();
	map<string, HistorialSuscripciones*>::iterator it;
	for (it = historialesJugador.begin(); it != historialesJugador.end(); it++){
		if (it->second->tieneSuscripcionActiva()) res.insert(it->second->pedirDatos());	
	}
	return res;
};

set<DtInfoSusc*> ControladorVideojuego::listarVidSinSuscActivas() {
	set<DtInfoSusc*> res;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion(); //ES JUGADOR
	Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);

	string nombreJugador = jugadorSesion->getNickname();
	map<string, HistorialSuscripciones*> historialesJugador = jugadorSesion->getHistoriales_de_suscripciones();

	map<string, Videojuego*>::iterator it;
	for (it = this->VideojuegoSis.begin(); it != this->VideojuegoSis.end(); it++){
		Videojuego* videojuegoActual = it->second;
		bool tieneSuscActiva = videojuegoActual->usuarioTieneSuscActiva();
		if (!tieneSuscActiva)
		{
			string nombreActual = videojuegoActual->getNombre();
			DtCosto* costoActual = videojuegoActual->getCosto();
			// hay que hacer una copia, no pueden compartir la instancia de DtCosto
			DtCosto* costo = new DtCosto(costoActual->getUnMes(), costoActual->getTresMeses(), costoActual->getUnAnio(), costoActual->getVitalicia());
			DtInfoSusc *DtIS = new DtInfoSusc(videojuegoActual->getNombre(), costo);
			res.insert(DtIS);
		}
	}
	return res;
};

void ControladorVideojuego::seleccionarVideojuego(string nombreVid){
	this->nombre = nombreVid;
	map<string, Videojuego*>::iterator it = this->VideojuegoSis.find(nombreVid);
	if (it == this->VideojuegoSis.end()) {
		throw invalid_argument(MSJ_VID_NO_EXISTE);
	};
	this->videojuegoSeleccionado = it->second;
}

void ControladorVideojuego::terminar() {
	this->nombre = "";
};

void ControladorVideojuego::cancelarSuscripcion() {
	map<string,Videojuego*>::iterator itVideojuegoSis = this->VideojuegoSis.find(this->nombre);
	Videojuego* juegoACancelarSuscripcion = itVideojuegoSis->second;
	juegoACancelarSuscripcion->cancelarSuscripcion();
};

void ControladorVideojuego::infoNuevaSusc(TipoSuscripcion tipoSusc, TipoPago pago) {
	this->tipoSuscripcion = tipoSusc;
	this->pago = pago;
};

void ControladorVideojuego::ingresarDatosCategoria(DtInfoCategoria* datoscategoria){
	this->datosCategoria = datoscategoria;
};

TipoGenero ControladorVideojuego::pasajeTipoGenero(string tipocategoria){
	TipoGenero tipogenero;
	if (tipocategoria.compare("Accion") == 0){
		tipogenero = Accion;
	}else if (tipocategoria.compare("Aventura") == 0){
		tipogenero = Aventura;
	}else if (tipocategoria.compare("Estrategia") == 0){
		tipogenero = Estrategia;
	}else if (tipocategoria.compare("Deporte") == 0){
		tipogenero = Aventura;
	}else if (tipocategoria.compare("Supervivencia") == 0){
		tipogenero = Supervivencia;
	}
	return tipogenero;
};

TipoPlataforma ControladorVideojuego::pasajeTipoPlataforma(string tipocategoria){
	TipoPlataforma tipoplataforma;
	if (tipocategoria.compare("PC") == 0){
		tipoplataforma = PC;
	}else if(tipocategoria.compare("Switch") == 0){
		tipoplataforma = Switch;
	}else if(tipocategoria.compare("PS4") == 0){
		tipoplataforma = PS4;
	}else if(tipocategoria.compare("PS5") == 0){
		tipoplataforma = PS5;
	}else if (tipocategoria.compare("XboxOne") == 0){
		tipoplataforma = XboxOne;
	}else if (tipocategoria.compare("XboxX") == 0){
		tipoplataforma = XboxX;
	}
	return tipoplataforma;
};

void ControladorVideojuego::confirmarCategoria(){
	string tipoCategoria = this->datosCategoria->getTipoCategoria();
	string nombre = this->datosCategoria->getNombre();
	string descripcion = this->datosCategoria->getDescripcion();

	if (tipoCategoria.compare("Genero") == 0){
		TipoGenero tipogenero = pasajeTipoGenero(nombre);
	 	Genero* genero = new Genero(tipogenero,nombre,descripcion);
	 	this->GeneroSis.insert({nombre,genero});
	} 
	else if (tipoCategoria.compare("Plataforma") == 0){
		TipoPlataforma tipoplataforma = pasajeTipoPlataforma(nombre);
	 	Plataforma* plataforma = new Plataforma(tipoplataforma,nombre,descripcion);
        this->PlataformaSis.insert({nombre,plataforma});
	}
	else{
	 	Categoria* categoria = new Categoria(nombre,descripcion);
	 	this->CategoriaSis.insert({nombre,categoria});
	}
	this->cancelarCategoria();
};

void ControladorVideojuego::confirmarSuscripcion() {
	map<string,Videojuego*>::iterator itVideojuegoSis = this->VideojuegoSis.find(this->nombre);
	itVideojuegoSis->second->confirmarSuscripcion(this->tipoSuscripcion, this->pago);
};

set<DtInfoBasicaVideojuego*> ControladorVideojuego::listarVideojuegos() {
	set<DtInfoBasicaVideojuego*> res;
	map<string,Videojuego*>::iterator it;
	for (it = this->VideojuegoSis.begin(); it != this->VideojuegoSis.end(); it++)
	{	
		DtInfoBasicaVideojuego* aux = new DtInfoBasicaVideojuego(it->first);
		res.insert(aux);
	}
	return res;

};

set<DtInfoBasicaVideojuego*> ControladorVideojuego::listarVideojuegosPublicadosDesarrollador() {
	set<DtInfoBasicaVideojuego*> res;
	map<string,Videojuego*>::iterator it;
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);
	
	map<string,Videojuego*> videojuegosPublicados = desarrolladorSesion->getVideojuegosPublicados();
	for (it = videojuegosPublicados.begin(); it != videojuegosPublicados.end(); it++)
	{
		DtInfoBasicaVideojuego* aux = new DtInfoBasicaVideojuego(it->first);
		res.insert(aux);
	}

	return res;
};

void ControladorVideojuego::eliminarVideojuego(string nombrevideojuego) {
	this->nombre = nombrevideojuego;
};

void ControladorVideojuego::confirmarEliminar() {
	
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iU = fabrica->getIUsuario();
	Usuario* usuarioSesion = iU->getUsuarioSesion();
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);
	
	
	map<string, Videojuego*>::iterator it1;
	it1 = VideojuegoSis.find(this->nombre);
		
	if (it1 != VideojuegoSis.end()){
		Videojuego* videojuegoEliminar = it1->second;
		it1->second = NULL;
	    VideojuegoSis.erase(it1);
	
		desarrolladorSesion->eliminarVideojuegopublicado(videojuegoEliminar->getNombre());

		videojuegoEliminar->EliminarHistorialSuscripciones();

		videojuegoEliminar->EliminarPuntajes();

		videojuegoEliminar->EliminarPartidas();

		delete videojuegoEliminar;
	}
	else{
		cout << "No existe el videojuego"<< endl;
	}
};

set<Genero*> ControladorVideojuego::obtenerGeneros() {
	set<Genero*> res;
	set<string>::iterator it;
	map<string,Genero*>::iterator it2;
	for (it = this->nombreGeneros.begin(); it != this->nombreGeneros.end(); it++) {
		it2 = this->GeneroSis.find(*it);
		if (it2 != this->GeneroSis.end()) res.insert(it2->second);
	}
	return res;
};

set<Plataforma*> ControladorVideojuego::obtenerPlataformas() {
	set<Plataforma*> res;
	set<string>::iterator it;
	map<string,Plataforma*>::iterator it2;
	for (it = this->nombrePlataformas.begin(); it != this->nombrePlataformas.end(); it++) {
		it2 = this->PlataformaSis.find(*it);
		if (it2 != this->PlataformaSis.end()) {
			res.insert(it2->second);
		}
	}
	return res;

};

set<Categoria*> ControladorVideojuego::obtenerCategorias() {
	set<Categoria*> res;
	set<string>::iterator it;
	map<string,Categoria*>::iterator it2;
	for (it = this->nombreCategorias.begin(); it != this->nombreCategorias.end(); it++) {
		it2 = this->CategoriaSis.find(*it);
		if (it2 != this->CategoriaSis.end()) res.insert(it2->second);
	}
	return res;

};

Videojuego* ControladorVideojuego::obtenerVideojuego(string nombreVideojuego) {
	map<string, Videojuego*>::iterator it;
	it = this->VideojuegoSis.find(nombreVideojuego);
	Videojuego *res = it->second;
	return res;
	
};

set<DtInfoVideojuego*> ControladorVideojuego::listarInfoVideojuegos() {
	set<DtInfoVideojuego*> resultado;
	for (map<string, Videojuego*>::iterator it = this->VideojuegoSis.begin();
		it != this->VideojuegoSis.end(); ++it)
	{
		Videojuego* vid = it->second;
		DtInfoVideojuego* dtVideojuego = new DtInfoVideojuego(vid->getNombre(), vid->getDescripcion());
		resultado.insert(dtVideojuego);
	};

	return resultado;
};

void ControladorVideojuego::puntuarVideojuego(int puntaje) {
	if (puntaje > 0 && puntaje < 6)
	{
		if (this->videojuegoSeleccionado == NULL)
		{
			throw invalid_argument(MSJ_VID_SEL_ERR);
		};

		Fabrica* fabrica = Fabrica::getInstancia();
		IUsuario* iu = fabrica->getIUsuario();
		Usuario* usuarioSesion = iu->getUsuarioSesion();
		if (usuarioSesion == NULL)
		{
			throw invalid_argument(MSJ_USUARIO_SESION_ERR);
		};
		Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);
		if (jugadorSesion == NULL)
		{
			throw invalid_argument(MSJ_JUGADOR_SESION_ERR);
		};


		Puntaje* newPuntaje = new Puntaje(puntaje, jugadorSesion);
		this->videojuegoSeleccionado->agregarPuntaje(newPuntaje);

	} else {
		throw invalid_argument("El puntaje ingresado no es valido\n");
	}
	
};

string ControladorVideojuego::getDescripcionVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	return this->videojuegoSeleccionado->getDescripcion();
};

DtCosto* ControladorVideojuego::getCostosVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	return this->videojuegoSeleccionado->getCosto();
};

set<string> ControladorVideojuego::getCategoriasVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	set<string> resultado;

	set<Categoria*> categoriasVideojuegoSeleccionado = this->videojuegoSeleccionado->getCategorias();
	for (set<Categoria*>::iterator it = categoriasVideojuegoSeleccionado.begin(); it != categoriasVideojuegoSeleccionado.end(); ++it)
	{
		Categoria* categoria = *it;
		resultado.insert(categoria->getNombre());
	};
	set<Genero *> generosVideojuegoSeleccionado = this->videojuegoSeleccionado->getGeneros();
	for (set<Genero *>::iterator it = generosVideojuegoSeleccionado.begin(); it != generosVideojuegoSeleccionado.end(); ++it)
	{
		Genero *genero = *it;
		resultado.insert(genero->getNombre());
	};
	set<Plataforma *> plataformasVideojuegoSeleccionado = this->videojuegoSeleccionado->getPlataformas();
	for (set<Plataforma *>::iterator it = plataformasVideojuegoSeleccionado.begin(); it != plataformasVideojuegoSeleccionado.end(); ++it)
	{
		Plataforma *plataforma = *it;
		resultado.insert(plataforma->getNombre());
	};

	return resultado;
};

string ControladorVideojuego::getEmpresaDesarrolladoraVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iu = fabrica->getIUsuario();
	set<Desarrollador*> desarrolladoresSistema = iu->getDesarrolladores();
	set<Desarrollador*>::iterator it = desarrolladoresSistema.begin();
	bool encontrado = false;
	while (it != desarrolladoresSistema.end() && !encontrado) {
		Desarrollador* desarrollador = *it;
		map<string, Videojuego*> videojuegosPublicados = desarrollador->getVideojuegosPublicados();
		map<string, Videojuego*>::iterator itVid = videojuegosPublicados.find(this->videojuegoSeleccionado->getNombre());
		if (itVid != videojuegosPublicados.end()) //if (itVid->second != NULL)
		{
			encontrado = true;
			return desarrollador->getEmpresa();
		};
		it++;
	};
	return "";
};

float ControladorVideojuego::getPuntajePromedioVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	return this->videojuegoSeleccionado->getPuntajePromedio();
};

float ControladorVideojuego::getTotalHorasJugadasVideojuegoSeleccionado() {
	if (this->videojuegoSeleccionado == NULL) {
		throw invalid_argument(MSJ_VID_SEL_ERR);
	};

	Estadistica* totalHorasJugadas = this->estadisticasSistema.find("TotalHorasJugadas")->second;
	float resultado = totalHorasJugadas->calcularValor(this->videojuegoSeleccionado);
	return resultado;
};

void ControladorVideojuego::borrarMemoriaSistema() {
	this->nombreGeneros.clear();
	this->nombrePlataformas.clear();
	this->nombreCategorias.clear();

	this->costo = NULL; 
	if (this->datosCategoria != NULL)
	{
		delete this->datosCategoria;
		this->datosCategoria = NULL;
	};
	this->nombre = this->descripcion = "";
	this->videojuegoSeleccionado = NULL;
};

void ControladorVideojuego::cargarEstadisticasSistema() {
	CantidadTotalJugadores* cantidadTotalJugadores = new CantidadTotalJugadores("CantidadTotalJugadores", "Cantidad de jugadores que se han suscrito al videojuego");
	TotalHorasJugadas* totalHorasJugadas = new TotalHorasJugadas("TotalHorasJugadas", "Total de horas jugadas al videojuego");

	this->estadisticasSistema.insert({cantidadTotalJugadores->getNombre(), cantidadTotalJugadores});
	this->estadisticasSistema.insert({totalHorasJugadas->getNombre(), totalHorasJugadas});
};

set<DtInfoEstadistica *> ControladorVideojuego::listarEstadisticas() {
	set<DtInfoEstadistica*> resultado;
	for (map<string, Estadistica*>::iterator it = this->estadisticasSistema.begin(); it != this->estadisticasSistema.end(); it++)
	{
		Estadistica* estadistica = it->second;
		DtInfoEstadistica* dt = new DtInfoEstadistica(estadistica->getNombre(), estadistica->getDescripcion());
		resultado.insert(dt);
	};

	return resultado;
};

void ControladorVideojuego::seleccionarEstadistica(string nombreNuevaEstadistica) {
	Fabrica* fabrica = Fabrica::getInstancia();
	IUsuario* iu = fabrica->getIUsuario();
	if (!iu->usuarioSesionEsDesarrollador())
	{
		throw invalid_argument(MSJ_DESARROLLADOR_SESION_ERR);
	};

	Usuario* usuarioSesion = iu->getUsuarioSesion();
	Desarrollador* desarrolladorSesion = dynamic_cast<Desarrollador*>(usuarioSesion);

	Estadistica* estadisticaSeleccionada = this->estadisticasSistema.find(nombreNuevaEstadistica)->second;
	if (estadisticaSeleccionada == NULL)
	{
		throw invalid_argument(MSJ_ESTADISTICA_NO_EXISTE);
	};
	
	desarrolladorSesion->agregarEstadistica(estadisticaSeleccionada);
};

void ControladorVideojuego::setearVideojuegoSeleccionado(Videojuego* vidSel){
	this->videojuegoSeleccionado = vidSel;
}

ControladorVideojuego::~ControladorVideojuego() {
	map<string, Genero*>::iterator itG;
	map<string, Plataforma*>::iterator itP;
	map<string, Categoria*>::iterator itC;
	map<string, Videojuego*>::iterator itV;
	map<string, Estadistica*>::iterator itE;

	for (itG = GeneroSis.begin(); itG != GeneroSis.end(); itG++)
		delete itG->second;

	for (itP = PlataformaSis.begin(); itP != PlataformaSis.end(); itP++)
		delete itP->second;

	for (itC = CategoriaSis.begin(); itC != CategoriaSis.end(); itC++)
		delete itC->second;

	for (itV = VideojuegoSis.begin(); itV != VideojuegoSis.end(); itV++)
		delete itV->second;

	for (itE = estadisticasSistema.begin(); itE != estadisticasSistema.end(); itE++)
		delete itE->second;

	nombreGeneros.clear();
	nombrePlataformas.clear();
	nombreCategorias.clear();
	estadisticasSistema.clear();

	if (this->datosCategoria != NULL)
	{
		delete this->datosCategoria;
		this->datosCategoria = NULL;
	};

};