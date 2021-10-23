#ifndef _IVideojuego
#define _IVideojuego

#include "DtGenero.h"
#include "DtPlataforma.h"
#include "DtCategoria.h"
#include "DtInfoCategoria.h"
#include "DtInfoSusc.h"
#include "DtInfoVideojuego.h"
#include "Videojuego.h"
#include "DtInfoEstadistica.h"

using namespace std;
using std::string;

class IVideojuego {

	public:

		IVideojuego() {};

		virtual void agregarNuevoVideojuego(string nombre, string descripcion, DtCosto* costos) = 0;
		virtual set<DtGenero*> listarGenero() = 0;
		virtual void agregarGenero(string nombreGenero) = 0;
		virtual set<DtPlataforma*> listarPlataformas() = 0;
		virtual void agregarPlataforma(string nombrePlataforma) = 0;
		virtual set<DtCategoria*> listarCategorias() = 0;
		virtual set<string> listarNombreTodasCategorias() = 0;
		virtual void agregarCategoria(string nombreCategoria) = 0;
		virtual void confirmarCategoria() = 0;
		virtual void confirmarNuevoVideojuego() = 0;
		virtual void cancelar() = 0;
		virtual void cancelarCategoria() = 0;
		virtual set<DtInfoSusc*> listarVidConSuscActivas() = 0;
		virtual set<DtInfoSusc*> listarVidSinSuscActivas() = 0;
		virtual void terminar() = 0;
		virtual void cancelarSuscripcion() = 0;
		virtual void ingresarDatosCategoria(DtInfoCategoria* datoscategoria) = 0;
		virtual void infoNuevaSusc(TipoSuscripcion tipoSusc, TipoPago pago) = 0;
		virtual void confirmarSuscripcion() = 0;
		virtual set<DtInfoBasicaVideojuego*> listarVideojuegos() = 0;
		virtual set<DtInfoBasicaVideojuego*> listarVideojuegosPublicadosDesarrollador() = 0;
		virtual set<DtInfoVideojuego*> listarInfoVideojuegos() = 0;
		virtual void eliminarVideojuego(string nombrevideojuego) = 0;
		virtual void confirmarEliminar() = 0;
		virtual set<Genero*> obtenerGeneros() = 0;
		virtual set<Plataforma*> obtenerPlataformas() = 0;
		virtual set<Categoria*> obtenerCategorias() = 0;
		virtual Videojuego* obtenerVideojuego(string nombreVideojuego) = 0;
		virtual void seleccionarVideojuego(string nombreVid) = 0;
		virtual void puntuarVideojuego(int puntaje) = 0;
		virtual string getDescripcionVideojuegoSeleccionado() = 0;
		virtual DtCosto* getCostosVideojuegoSeleccionado() = 0;
		virtual set<string> getCategoriasVideojuegoSeleccionado() = 0;
		virtual string getEmpresaDesarrolladoraVideojuegoSeleccionado() = 0;
		virtual float getPuntajePromedioVideojuegoSeleccionado() = 0;
		virtual float getTotalHorasJugadasVideojuegoSeleccionado() = 0;
		virtual TipoPlataforma pasajeTipoPlataforma(string tipocategoria) = 0;
		virtual TipoGenero pasajeTipoGenero(string tipocategoria) = 0;
		virtual void borrarMemoriaSistema() = 0;
		virtual void cargarEstadisticasSistema() = 0;
		virtual set<DtInfoEstadistica*> listarEstadisticas() = 0;
		virtual void seleccionarEstadistica(string nombreNuevaEstadistica) = 0;
		virtual void setearVideojuegoSeleccionado(Videojuego* vidSel) = 0;

		virtual ~IVideojuego() {};
};
#endif