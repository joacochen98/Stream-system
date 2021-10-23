#ifndef _ControladorUsuario
#define _ControladorUsuario

#include "Usuario.h"
#include "DtValorEstadistica.h"
#include "Jugador.h"
#include "Desarrollador.h"
#include "IUsuario.h"

using namespace std;

class ControladorUsuario: public IUsuario {
	private:
		ControladorUsuario();
		static ControladorUsuario *instancia; // Singleton

		Usuario* usuarioSesion;
		map<string,Usuario*> coleccionUsuarios;
		set<Desarrollador*> coleccionDesarrolladores;
		map<string,Jugador*> coleccionJugadores;

		string tipoUsuario; 
		string email;
		string contrasenia;
		string nombreEmpresa; 
		string nickname;
		string descripcion;
		string nombreVid;
		string nombreEstadistica;

	public:
		static ControladorUsuario* getInstancia();
		bool datosInicioSesion(string email, string contrasenia);
		void tipoUsuarioRegistrar(string tipoUsuario);
		bool existeEmail(string email);
		void recordarEmail(string email);
		void recordarContrasenia(string contrasenia);
		void ingresarNombreEmpresa(string nombreEmpresa);
		bool existeNicknameJugador(string nickname);
		void recordarNickname(string nickname);
		void ingresarDescripcion(string descripcion);
		void confirmarAltaUsuario();
		void cancelar();
		void setDesarrolladorSesion(Desarrollador* desarrollador);
		void setJugadorSesion(Jugador* jugador);
		
		Usuario* getUsuarioSesion();
		set<string> listarVideojuegosPublicadosPorDesarrolador();
		void seleccionarVideojuego(string nombreVid);
		set<DtValorEstadistica*> mostrarEstadistica();
		Jugador* buscarJugador(string nickname);
		Desarrollador* buscarDesarrollador(string nombreEmpresa);
		set<Desarrollador*> getDesarrolladores();
		bool usuarioSesionEsDesarrollador();
		void cerrarSesion();

		~ControladorUsuario();
};
#endif
