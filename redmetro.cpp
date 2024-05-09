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

unsigned short redMetro::calcularTiempoLlegada(const string &nombreLinea, const string &estacionOriginal, const string &estacionFinal)
{
    unsigned short tiempoTotal = 0;
    bool empezarSuma = false;
    for (unsigned short i = 0; i < this->getNumLineas(); i++) {
        if (this->getLineas()[i].getNombre() == nombreLinea) {
            for (unsigned short j = 0; j < this->getLineas()[i].getCantidadEstaciones(); j++) {
                if (this->getLineas()[i].getEstaciones()[j].getNombre() == estacionOriginal) {
                    empezarSuma = true;
                    continue;
                }
                if (empezarSuma) {
                    tiempoTotal += this->getLineas()[i].getEstaciones()[j].getTiempoAnterior();
                }
                if (this->getLineas()[i].getEstaciones()[j].getNombre() == estacionFinal) {
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
            return linea;
        }
        cont += 1;
    }
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
