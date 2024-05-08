#include "redmetro.h"

redMetro::redMetro()
{
    numLineas = 0;
}

unsigned short redMetro::getNumLineas()
{
    return this->numLineas;
}

void redMetro::agregarLinea(string nombreLinea, string tipoTransp)
{
    Linea lin(nombreLinea, tipoTransp);
    this->lineas.append(lin);
    numLineas += 1;
}

void redMetro::eliminarLinea(string nombreLinea)
{
    Linea* lin = obtenerLineaConSuNombre(nombreLinea);
    if(!lin->tieneEstacionesTransferencia()){
        lineas.delPos(lineas.index(*lin));
        numLineas -= 1;
    }else{
        cout << "No se puede eliminar porque tiene estacion de trasnferencia" << endl;
    }
}


bool redMetro::verificarEstacionEnLinea(string nombreEstacion, string nombreLinea)
{
    return (this->obtenerLineaConSuNombre(nombreLinea)->verificarEstacion(nombreEstacion));
}

unsigned short redMetro::calcularTiempoLlegada(redMetro &red_metro, const string &nombreLinea, const string &estacionOriginal, const string &estacionFinal)
{
    unsigned short tiempoTotal = 0;
    bool empezarSuma = false;
    for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
        if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
            for (unsigned short j = 0; j < red_metro.getLineas()[i].getCantidadEstaciones(); j++) {
                if (red_metro.getLineas()[i].getEstaciones()[j].getNombre() == estacionOriginal) {
                    empezarSuma = true;
                    continue;
                }
                if (empezarSuma) {
                    tiempoTotal += red_metro.getLineas()[i].getEstaciones()[j].getTiempoAnterior();
                }
                if (red_metro.getLineas()[i].getEstaciones()[j].getNombre() == estacionFinal) {
                    break;
                }
            }
            break;
        }
    }
    return tiempoTotal;

}

Linea *redMetro::obtenerLineaConSuNombre(string nombre)
{
    Linea* linea;
    unsigned short cont = 0;
    Linea* Lineas = this->lineas.getfirst();
    while (cont < this->numLineas)
    {
        if (Lineas[cont].getNombre() == nombre)
        {
            linea = &(Lineas[cont]);
            break;
        }
    }

    return linea;
}

unsigned short redMetro::redMetro::getCantidadEstacionesRed()
{
    unsigned short sum = 0;
    Linea* linea = lineas.getfirst();
    for (unsigned short i = 0; i < numLineas; i++) {
        sum += linea->getCantidadEstaciones();
        /*for (unsigned short j = 0; j < lineas.getfirst()[i].getCantidadEstaciones(); j++) {
            if (!estaciones[j].getEsTransferencia()) {
                sum++;
            }
        }*/
    }
    return sum;
}

Linea *redMetro::getLineas()
{
    return lineas.getfirst();
}
