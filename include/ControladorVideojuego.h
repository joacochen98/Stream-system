#ifndef _ControladorVideojuego
#define _ControladorVideojuego

#include "IVideojuego.h"
#include "DtGenero.h"
#include "DtPlataforma.h"
#include "DtCategoria.h"
#include "DtInfoCategoria.h"
#include "DtInfoSusc.h"
#include "DtInfoVideojuego.h"
#include "Videojuego.h"
#include "DtCosto.h"
#include "Estadistica.h"
#include "DtInfoEstadistica.h"

using std::string;
using namespace std;

class ControladorVideojuego: public IVideojuego {

	private:
		ControladorVideojuego();
		static ControladorVideojuego* instancia; // Singleton

		map<string,Genero*> GeneroSis;
		map<string,Categoria*> CategoriaSis;
		map<string,Plataforma*> PlataformaSis;
		map<string,Videojuego*> VideojuegoSis;
		map<string, Estadistica*> estadisticasSistema;
		set<string> nombreGeneros;
		set<string> nombrePlataformas;
		set<string> nombreCategorias;
		string nombre;
		string descripcion;
		DtCosto* costo;
		DtInfoCategoria* datosCategoria;
		TipoSuscripcion tipoSuscripcion;
		TipoPago pago;
		
		Videojuego* videojuegoSeleccionado;

	public:
		static ControladorVideojuego* getInstancia();
		void agregarNuevoVideojuego(string nombre, string descripcion, DtCosto* costos);
		set<DtGenero*> listarGenero();
		void agregarGenero(string nombreGenero);
		set<DtPlataforma*> listarPlataformas();
		void agregarPlataforma(string nombrePlataforma);
		set<DtCategoria*> listarCategorias();
		set<string> listarNombreTodasCategorias();
		void agregarCategoria(string nombreCategoria);
		void confirmarCategoria();
		void cancelarCategoria();
		void confirmarNuevoVideojuego();
		void cancelar();
		TipoPlataforma pasajeTipoPlataforma(string tipocategoria);
		TipoGenero pasajeTipoGenero(string tipocategoria);

		set<DtInfoSusc*> listarVidConSuscActivas();
		set<DtInfoSusc*> listarVidSinSuscActivas();
		void seleccionarVideojuego(string nombreVid);
		void terminar();
		void cancelarSuscripcion();
		void infoNuevaSusc(TipoSuscripcion tipoSusc, TipoPago pago);
		void ingresarDatosCategoria(DtInfoCategoria* datoscategoria);
		void confirmarSuscripcion();
		set<DtInfoBasicaVideojuego*> listarVideojuegos();
		set<DtInfoBasicaVideojuego*> listarVideojuegosPublicadosDesarrollador();
		void eliminarVideojuego(string nombrevideojuego);
		void confirmarEliminar();

		set<DtInfoVideojuego*> listarInfoVideojuegos();

		void puntuarVideojuego(int puntaje);

		void cargarEstadisticasSistema();

		set<DtInfoEstadistica*> listarEstadisticas();

		void seleccionarEstadistica(string nombreNuevaEstadistica);

		set<Genero *> obtenerGeneros();
		set<Plataforma*> obtenerPlataformas();
		set<Categoria*> obtenerCategorias();
		Videojuego* obtenerVideojuego(string nombreVideojuego);
		
		string getDescripcionVideojuegoSeleccionado();
		DtCosto* getCostosVideojuegoSeleccionado();
		set<string> getCategoriasVideojuegoSeleccionado();
		string getEmpresaDesarrolladoraVideojuegoSeleccionado();
		float getPuntajePromedioVideojuegoSeleccionado();
		float getTotalHorasJugadasVideojuegoSeleccionado();

		void borrarMemoriaSistema();
		void setearVideojuegoSeleccionado(Videojuego* vidSel); 

		~ControladorVideojuego();
};
#endif