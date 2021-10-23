#ifndef _IUsuario
#define _IUsuario

#include "Usuario.h"
#include "DtValorEstadistica.h"
#include "Jugador.h"
#include <string>
#include "Desarrollador.h"

using std::string;
using namespace std;

class IUsuario {

	public:

		IUsuario() {};

		virtual void tipoUsuarioRegistrar(string tipoUsuario) = 0;
		virtual bool existeEmail(string email) = 0;
		virtual void recordarEmail(string email) = 0;
		virtual bool datosInicioSesion(string email,string contrasenia) = 0;
		virtual void recordarContrasenia(string contrasenia) = 0;
		virtual void ingresarNombreEmpresa(string nombre) = 0;
		virtual bool existeNicknameJugador(string nickname) = 0;
		virtual void recordarNickname(string nickname) = 0;
		virtual void ingresarDescripcion(string descripcion) = 0;
		virtual void confirmarAltaUsuario() = 0;
		virtual void cancelar() = 0;
		virtual void setDesarrolladorSesion(Desarrollador* desarrollador) = 0; 
		virtual void setJugadorSesion(Jugador* jugador) = 0;
		virtual Usuario* getUsuarioSesion() = 0;
		virtual set<string> listarVideojuegosPublicadosPorDesarrolador() = 0;
		virtual void seleccionarVideojuego(string nombreVid) = 0;
		virtual set<DtValorEstadistica*> mostrarEstadistica() = 0;
		virtual Jugador* buscarJugador(string nickname) = 0;
		virtual Desarrollador* buscarDesarrollador(string nombreEmpresa) = 0;
		virtual set<Desarrollador*> getDesarrolladores() = 0;
		virtual bool usuarioSesionEsDesarrollador() = 0;
		virtual void cerrarSesion() = 0;

		virtual ~IUsuario() {};
};
#endif