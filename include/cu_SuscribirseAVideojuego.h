#ifndef CU_SUSCRIBIRSEAVIDEOJUEGO_H
#define CU_SUSCRIBIRSEAVIDEOJUEGO_H

#include "Fabrica.h"
#include "IVideojuego.h"
#include "SuscripcionVitalicia.h"

#include <set>
#include <string>
#include <iostream>

using namespace std;

TipoSuscripcion numeroATipoSuscripcion(int tipoDeSuscripcion){
    TipoSuscripcion tipoSusc;
    switch(tipoDeSuscripcion){
            case 0: tipoSusc = TemporalUnMes; break;
            case 1: tipoSusc = TemporalTresMeses; break;
            case 2: tipoSusc = TemporalUnAnio; break;
            case 3: tipoSusc = Vitalicia; break;
            default: cout << "Valor de suscripcion no permitido" << endl; break;
        }
    return tipoSusc;
}

void imprimirTipoSuscripcion(int tipoDeSuscripcion){
    switch(tipoDeSuscripcion){
            case 0: cout << "mensual"; break;
            case 1: cout << "trimestral"; break;
            case 2: cout << "anual"; break;
            case 3: cout << "vitalicia"; break;
            default: cout << "Valor de suscripcion no permitido" << endl; break;
        }
}

TipoPago numeroATipoPago(int metodoDePago){
    TipoPago metPago;
    switch(metodoDePago){
            case 0: metPago = tarjeta; break;
            case 1: metPago = PayPal; break;
            default: cout << "Valor de pago no permitido" << endl; break;
        }
        return metPago;
}

void imprimirTipoPago(int metodoDePago){
    switch(metodoDePago){
            case 0: cout << "tarjeta"; break;
            case 1: cout << "PayPal"; break;
            default: cout << "Valor de pago no permitido" << endl; break;
        }
}

bool numeroABool(int imput){
    bool deseaCancelar;
    switch(imput){
        case 1: deseaCancelar = true; break;
        case 0: deseaCancelar = false; break;
        default: cout << "Imput no valido" << endl;
    }
    return deseaCancelar;
}

//se le pasa el nombre de un videojuego al que tiene una susc. activa
Suscripcion* obtenerSuscripcionActiva(string nombreVideojuego, string nombreJugador){
    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    Videojuego* videojuego = iv->obtenerVideojuego(nombreVideojuego);
    map<string, HistorialSuscripciones*>::iterator it;
    it = videojuego->getHistorialSuscripciones().find(nombreJugador);
    HistorialSuscripciones* historial = it->second;
    Suscripcion* res = historial->getSuscripcionActiva();
    return res;
};

void cu_SuscribirseAVideojuego(){

    Fabrica* fabrica = Fabrica::getInstancia();
    IVideojuego* iv = fabrica->getIVideojuego();
    IUsuario* iU = fabrica->getIUsuario();
    Usuario* usuarioSesion = iU->getUsuarioSesion();
    Jugador* jugadorSesion = dynamic_cast<Jugador*>(usuarioSesion);

    string nombreJugador = jugadorSesion->getNickname();
    set<DtInfoSusc*> vjConActiva = iv->listarVidConSuscActivas();
    set<DtInfoSusc*> vjSinActiva = iv->listarVidSinSuscActivas();
    set<DtInfoSusc*>::iterator it;

    if (vjConActiva.empty() && vjSinActiva.empty()) {
        cout << "No existen videojuegos en el sistema." << endl;
    }
    else {
        
        cout << "Estos son los juegos para los cuales tiene una suscripcion activa: " << endl << endl;
        for (it = vjConActiva.begin(); it != vjConActiva.end(); it++) cout << *(*it) << endl;

        cout << "Estos son los juegos para los cuales NO tiene una suscripcion activa: " << endl << endl;
        for (it = vjSinActiva.begin(); it != vjSinActiva.end(); it++) cout << *(*it) << endl;


        cout << "------------------------------------------------------------" << endl;
        cout << "Ingrese el nombre del videojuego al cual desea suscribirse:" << endl;
        string nombreVideojuego;
        cin.ignore();
        getline (cin,nombreVideojuego);
        bool eligioBien = true;
        try
        {
            iv->seleccionarVideojuego(nombreVideojuego);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            eligioBien = false;
        }

        if(eligioBien){

            //CHEQUEA SI ELIGIO UN VIDEOJUEGO DE LA LISTA DE LOS CON SUSC. ACTIVA
            it = vjConActiva.begin();
            bool tieneActiva = false;
            while (!tieneActiva && it != vjConActiva.end() ) {
                tieneActiva = ((*it)->getNombreVid().compare(nombreVideojuego) == 0);
                if (!tieneActiva) it++;
            }
            if (tieneActiva) {   //YA TIENE SUSC ACTIVA PARA ESE VIDEOJUEGO
                Suscripcion* suscripcion = obtenerSuscripcionActiva(nombreVideojuego, nombreJugador);
                bool esVitalicia = (dynamic_cast<SuscripcionVitalicia*>(suscripcion) != NULL);
                if (esVitalicia) {  //LA SUSC ACTIVA ES VITALICIA
                    cout << "Ya tiene una suscripcion vitalicia para ese videojuego, no puede contratar otra" << endl;
                    iv->terminar();
                }

                else { //LA SUSC ACTIVA ES TEMPORAL

                    cout << "Ya tiene una suscripcion activa para ese videojuego, ¿desea cancelarla?" << endl;
                    cout << "Para cancelarla ingrese 1, si no ingrese 0" << endl;
                    int imput;
                    cin >> imput;
                    bool deseaCancelar = numeroABool(imput);

                    if (deseaCancelar){ //CANCELA LA SUSC ACTIVA ACTUAL
                        iv->cancelarSuscripcion();
                    }
                    else{ //SE CANCELA EL CASO DE USO

                        cout << "Se cancela el caso de uso" << endl;
                        iv->terminar();
                    }
                }
            }
            else {//NO TIENE SUSC ACTIVA PARA ESE VIDEOJUEGO

                cout << "Elija el tipo de suscripcion que desea contratar:" << endl;
                cout << "0 - Mensaual" << endl;
                cout << "1 - Trimestral" << endl;
                cout << "2 - Anual" << endl;
                cout << "3 - Vitalicia" << endl;
                //cout << "Mensual: ingrese 0, trimestral: ingrese 1, anual: ingrese 2, vitalicia: ingrese 3" << endl;
                int tipoDeSuscripcion;
                cin >> tipoDeSuscripcion;
                while(tipoDeSuscripcion != 0 && tipoDeSuscripcion != 1 && tipoDeSuscripcion != 2 && tipoDeSuscripcion != 3){
                cout << "Tipo de suscripcion no valido, ingreselo nuevamente" << endl;
                cin >> tipoDeSuscripcion;
                }
                TipoSuscripcion tipoSusc = numeroATipoSuscripcion(tipoDeSuscripcion);

                cout << "Elija un metodo de pago" << endl;
                cout << "0 - Tarjeta" << endl;
                cout << "1 - PayPal" << endl;
                //cout << "Tarjeta: ingrese 0, PayPal: ingrese 1" << endl;
                int metodoDePago;
                cin >> metodoDePago;
                while(metodoDePago != 0 && metodoDePago != 1){
                cout << "Metodo de pago no valido, ingreselo nuevamente" << endl;
                cin >> metodoDePago;
                }
                TipoPago metPago = numeroATipoPago(metodoDePago);

                iv->infoNuevaSusc(tipoSusc, metPago);

                cout << "Contratara una suscripcion ";
                imprimirTipoSuscripcion(tipoDeSuscripcion);
                cout << " y la pagara con ";
                imprimirTipoPago(metodoDePago);
                cout << endl;
                cout << "1 - Desea Confirmar" << endl;
                cout << "0 - Cancelar" << endl;
                //cout << "Para confirmar ingrese 1, para cancelar ingrese 0" << endl;
                int confirma;
                cin >> confirma;

                switch(confirma) {
                    case 1: {//DA DE ALTA LA NUEVA SUSC EN EL SISTEMA
                        iv->confirmarSuscripcion();//NO BORRA MEMORIA DEL SISTEMA
                        iv->cancelar(); //PARA BORRAR LA MEMORIA DEL SISTEMA
                        cout << "Se ha suscripto de manera exitosa" << endl;
                        }
                        break;
                    case 0: {//SE CANCELA EL CASO DE USO
                        cout << "Se cancela el proceso de suscripcion" << endl;
                        iv->cancelar();
                        }
                        break;
                    default: cout << "Valor no permitido" << endl; break;
                }
            }     
        }//ENDIF ELIGIO BIEN 
    }//END ELSE HAY VIDEOJUEGOS EN EL SISTEMA

    if (!vjConActiva.empty()){
        for (it = vjConActiva.begin(); it != vjConActiva.end() ; ++it) {
            delete (*it);
        };
    }     
    if(!vjSinActiva.empty()){
        for (it = vjSinActiva.begin(); it != vjSinActiva.end() ; ++it) {
            delete (*it);
        }; 
    }    
}
#endif
