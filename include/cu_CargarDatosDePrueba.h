#ifndef CU_CARGARDATOSDEPRUEBA
#define CU_CARGARDATOSDEPRUEBA

#include "Fabrica.h"
#include "SuscripcionTemporal.h"
#include "TipoPago.h"
#include "TipoValidez.h"
#include "TipoSuscripcion.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// caso de uso Cargar Datos de Prueba
void cu_CargarDatosDePrueba() {
	Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    IPartida* ip = fabrica->getIPartida();
    IUsuario* iu = fabrica->getIUsuario();

//  SE CARGAN LOS DESARROLLADORES

    string contrasenia = "123";    

    iu->recordarEmail("ironhide@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("desarrollador");
    iu->ingresarNombreEmpresa("Ironhide Game Studio");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("epic@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("desarrollador");
    iu->ingresarNombreEmpresa("Epic Games");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("mojang@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("desarrollador");
    iu->ingresarNombreEmpresa("Mojang Studios");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("ea@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("desarrollador");
    iu->ingresarNombreEmpresa("EA Sports");
    iu->confirmarAltaUsuario();

    Desarrollador *D1, *D2, *D3, *D4;
    D1 = iu->buscarDesarrollador("Ironhide Game Studio");
    D2 = iu->buscarDesarrollador("Epic Games");
    D3 = iu->buscarDesarrollador("Mojang Studios");
    D4 = iu->buscarDesarrollador("EA Sports");

//  SE CARGAN LOS JUGADORES AHORA

    iu->recordarEmail("gamer@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("jugador");
    iu->recordarNickname("gamer");
    iu->ingresarDescripcion("La letra no especifica una descripcion");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("ari@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("jugador");
    iu->recordarNickname("ari");
    iu->ingresarDescripcion("La letra no especifica una descripcion");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("ibai@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("jugador");
    iu->recordarNickname("ibai");
    iu->ingresarDescripcion("La letra no especifica una descripcion");
    iu->confirmarAltaUsuario();

    iu->recordarEmail("camila@mail.com");
    iu->recordarContrasenia(contrasenia);
    iu->tipoUsuarioRegistrar("jugador");
    iu->recordarNickname("camila");
    iu->ingresarDescripcion("La letra no especifica una descripcion");
    iu->confirmarAltaUsuario();

    Jugador *J1, *J2, *J3, *J4;
    J1 = iu->buscarJugador("gamer");
    J2 = iu->buscarJugador("ari");
    J3 = iu->buscarJugador("ibai");
    J4 = iu->buscarJugador("camila");

//  SE CARGAN LAS CATEGORIAS

    DtInfoCategoria* DtInfocategoria = new DtInfoCategoria("PC","Juegos de PC","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C1
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("PS4","Juegos de PS4","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C2
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Xbox One","Juegos de Xbox One","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C3
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Deporte","Juegos de deporte","Genero");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C4
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Supervivencia","Juegos de supervivencia","Genero");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C5
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Estrategia","Juegos de estrategia","Genero");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C6
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante","Otro");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C7
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("E","Su contenido está dirigido para todo publico","Otro");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C8
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Accion","Juegos de accion","Genero");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C9
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Aventura","Juegos de aventura","Genero");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C10
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Switch","Juegos de switch","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C11
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("Xbox X","Juegos de Xbox X","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C12
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    DtInfocategoria = new DtInfoCategoria("PS5","Juegos de ps5","Plataforma");
    iv->ingresarDatosCategoria(DtInfocategoria);    // C13
    iv->confirmarCategoria();

    iv->borrarMemoriaSistema();

    //  SE CARGAN LOS VIDEOJUEGOS

    DtCosto* costos = new DtCosto(1, 2, 7, 14);
    iv->agregarNuevoVideojuego("KingdomRush", "Primer juego", costos);
    iv->agregarPlataforma("PC");        // C1
    iv->agregarPlataforma("PS4");       // C2
    iv->agregarGenero("Estrategia");    // C6
    iv->agregarCategoria("E");          // C8
    iu->setDesarrolladorSesion(D1);
    iv->confirmarNuevoVideojuego();
    Videojuego* V1 = iv->obtenerVideojuego("KingdomRush");

    iv->borrarMemoriaSistema();

    costos = new DtCosto(3, 8, 30, 60);
    iv->agregarNuevoVideojuego("Fortnite", "Segundo juego", costos);
    iv->agregarPlataforma("PC");           // C1
    iv->agregarPlataforma("PS4");          // C2
    iv->agregarGenero("XboxOne");          // C3
    iv->agregarCategoria("Supervivencia"); // C5
    iv->agregarCategoria("Teen");          // C7
    iu->setDesarrolladorSesion(D2);
    iv->confirmarNuevoVideojuego();
    Videojuego* V2 = iv->obtenerVideojuego("Fortnite");

    iv->borrarMemoriaSistema();

    costos = new DtCosto(2, 5, 20, 40);
    iv->agregarNuevoVideojuego("Minecraft", "Tercer juego", costos);
    iv->agregarPlataforma("PC");            // C1
    iv->agregarPlataforma("Supervivencia"); // C5
    iv->agregarCategoria("E");              // C8
    iu->setDesarrolladorSesion(D3);
    iv->confirmarNuevoVideojuego();
    Videojuego* V3 = iv->obtenerVideojuego("Minecraft");

    iv->borrarMemoriaSistema();

    costos = new DtCosto(3, 8, 28, 50);
    iv->agregarNuevoVideojuego("FIFA 21", "Cuarto juego", costos);
    iv->agregarPlataforma("PC");        // C1
    iv->agregarPlataforma("PS4");       // C2
    iv->agregarGenero("Estrategia");    // C6
    iv->agregarCategoria("E");          // C8
    iv->agregarGenero("XboxOne");       // C3
    iv->agregarGenero("Deporte");       // C4
    iv->agregarCategoria("E");          // C8
    iu->setDesarrolladorSesion(D4);
    iv->confirmarNuevoVideojuego();
    Videojuego* V4 = iv->obtenerVideojuego("FIFA 21");

    iv->borrarMemoriaSistema();

    //SE CARGAN LAS SUSCRIPCIONES

    SuscripcionTemporal *S1, *S2, *S3, *S4, *S5;
    SuscripcionVitalicia *S6;
    DtFechaHora *F1, *F2, *F3, *F4, *F5, *F6;
    F1 = new DtFechaHora(1, 6, 2021, 9, 00);
    F2 = new DtFechaHora(2, 6, 2021, 11, 00);
    F3 = new DtFechaHora(4, 6, 2021, 9, 00);
    F4 = new DtFechaHora(11, 6, 2021, 9, 00);
    F5 = new DtFechaHora(3, 6, 2021, 7, 00);
    F6 = new DtFechaHora(21, 12, 2021, 15, 00);

    S1 = new SuscripcionTemporal(2, F1, PayPal, tresMeses, false);
    S2 = new SuscripcionTemporal(8, F2, tarjeta, tresMeses, false);
    S3 = new SuscripcionTemporal(3, F3, PayPal, unMes, false);
    S4 = new SuscripcionTemporal(20, F4, tarjeta, unAnio, false);
    S5 = new SuscripcionTemporal(3, F5, tarjeta, unMes, false);
    S6 = new SuscripcionVitalicia(40, F6, tarjeta);
    
    HistorialSuscripciones *H1, *H2, *H3, *H4, *H5, *H6;

    H1 = new HistorialSuscripciones(J1, V1);
    J1->agregarHistorialSuscripciones(V1->getNombre(), H1);
    H1->agregarSuscripcion(S1);
    H1->setSuscripcionActiva(S1);

    H2 = new HistorialSuscripciones(J1, V2);
    J1->agregarHistorialSuscripciones(V2->getNombre(), H2);
    H2->agregarSuscripcion(S2);
    H2->setSuscripcionActiva(S2);

    H3 = new HistorialSuscripciones(J2, V2);
    J2->agregarHistorialSuscripciones(V2->getNombre(), H3);
    H3->agregarSuscripcion(S3);
    H3->setSuscripcionActiva(S3);

    H4 = new HistorialSuscripciones(J2, V3);
    J2->agregarHistorialSuscripciones(V3->getNombre(), H4);
    H4->agregarSuscripcion(S4);
    H4->setSuscripcionActiva(S4);

    H5 = new HistorialSuscripciones(J3, V2);
    J3->agregarHistorialSuscripciones(V2->getNombre(), H5);
    H5->agregarSuscripcion(S5);
    H5->setSuscripcionActiva(S5);

    H6 = new HistorialSuscripciones(J3, V3);
    J3->agregarHistorialSuscripciones(V3->getNombre(), H6);
    H6->agregarSuscripcion(S6);
    H6->setSuscripcionActiva(S6);

// SE CARGAN PUNTAJES
    try
    {
        iu->setJugadorSesion(J1);
        iv->setearVideojuegoSeleccionado(V1);
        iv->puntuarVideojuego(4);

        iu->setJugadorSesion(J1);
        iv->setearVideojuegoSeleccionado(V2);
        iv->puntuarVideojuego(5);

        iu->setJugadorSesion(J2);
        iv->setearVideojuegoSeleccionado(V2);
        iv->puntuarVideojuego(5);

        iu->setJugadorSesion(J2);
        iv->setearVideojuegoSeleccionado(V3);
        iv->puntuarVideojuego(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    DtFechaHora *F7, *F8, *F9;
    F7 = new DtFechaHora(2, 6, 2021, 9, 00);
    F8 = new DtFechaHora(3, 6, 2021, 15, 00);
    F9 = new DtFechaHora(12, 6, 2021, 16, 00);

    PartidaIndividual* P1 = new PartidaIndividual(111, F7, V1, true, "gamer", false);
    P1->setVideojuegoPerteneciente(V1);
    V1->agregarPartida(P1);
    J1->agregarNuevaPartida(P1);
    ip->agregarPartidaInterfaz(P1);
    DtFechaHora* FF7 = new DtFechaHora(2, 6, 2021, 10, 0);
    P1->setFechaFinalizacion(FF7);

    PartidaIndividual* P2 = new PartidaIndividual(222, F8, V1, true, "gamer", true);
    P2->setVideojuegoPerteneciente(V1);
    V1->agregarPartida(P2);
    J1->agregarNuevaPartida(P2);
    ip->agregarPartidaInterfaz(P2);
    P2->setIdPartidaAnterior(111); //P2 CONTINUA LA PARTIDA DE ID = 111 (P1)
    DtFechaHora* FF8 = new DtFechaHora(3, 6, 2021, 16, 0);
    P2->setFechaFinalizacion(FF8);

    PartidaIndividual* P3 = new PartidaIndividual(333, F9, V3, false, "gamer", false);
    P3->setVideojuegoPerteneciente(V3);
    V3->agregarPartida(P3);
    J2->agregarNuevaPartida(P3);
    ip->agregarPartidaInterfaz(P3);

//SE CARGAN PARTIDAS MULTIJUGADOR

    JugadorUnido *JU1, *JU2; //(J2, P4), (J3, P4)
    JU1 = new JugadorUnido(J2);
    JU2 = new JugadorUnido(J3);
    JU2->setDuracion(120); // jugo 2 horas

    DtFechaHora *F10, *F11, *F12;
    F10 = new DtFechaHora(5, 6, 2021, 17, 00);
    F11 = new DtFechaHora(6, 6, 2021, 17, 00);
    F12 = new DtFechaHora(12, 6, 2021, 20, 00);

    PartidaMultijugador* P4 = new PartidaMultijugador(444, F10, V2, true, "gamer", true);
    V2->agregarPartida(P4);
    J1->agregarNuevaPartida(P4);
    ip->agregarPartidaInterfaz(P4);
    P4->agregarJugadorUnido(JU1);
    P4->agregarJugadorUnido(JU2);
    DtFechaHora* FF10 = new DtFechaHora(5, 6, 2021, 19, 0);
    P4->setFechaFinalizacion(FF10);

    JugadorUnido *JU3, *JU4; //(J2, P5), (J3, P5)
    JU3 = new JugadorUnido(J2);
    JU4 = new JugadorUnido(J3);
    JU4->setDuracion(120); // jugo 2 horas

    PartidaMultijugador* P5 = new PartidaMultijugador(555, F11, V2, true, "gamer", true);
    V2->agregarPartida(P5);
    J1->agregarNuevaPartida(P5);
    ip->agregarPartidaInterfaz(P5);
    P5->agregarJugadorUnido(JU3);
    P5->agregarJugadorUnido(JU4);
    DtFechaHora* FF11 = new DtFechaHora(6, 6, 2021, 19, 0);
    P5->setFechaFinalizacion(FF11);

    JugadorUnido *JU5; //(J3, P3)
    JU5 = new JugadorUnido(J3);

    PartidaMultijugador* P6 = new PartidaMultijugador(666, F12, V3, false, "ari", false);
    V3->agregarPartida(P6);
    J2->agregarNuevaPartida(P6);
    ip->agregarPartidaInterfaz(P6);
    P6->agregarJugadorUnido(JU5);

//SE REALIZAN ABANDONOS DE PARTIDA

    JU1->setAbandono(true);
    DtFechaHora* fechaAb1 = new DtFechaHora(5, 6, 2021, 18, 0);
    JU1->setFechaAbandono(fechaAb1);
    JU1->setDuracion(60);

    JU3->setAbandono(true);
    DtFechaHora* fechaAb2 = new DtFechaHora(6, 6, 2021, 17, 30);
    JU3->setFechaAbandono(fechaAb2);
    JU3->setDuracion(30);

    cout << "Carga de datos de prueba exitosa!" << endl;
};

#endif