#include "Linea.h"

Linea::Linea(string _nombre, string _tipoTransporte)
{
    nombre= _nombre;
    tipoTransporte= _tipoTransporte;
    numEstaciones = 0;
}

Linea::Linea()
{
    nombre= "";
    tipoTransporte= "";
    numEstaciones = 0;
}

string Linea::getNombre() const
{
    return nombre;
}

string Linea::getTipoTransporte() const
{
    return tipoTransporte;
}

unsigned short Linea::getCantidadEstaciones() const
{
    return numEstaciones;
}

void Linea::agregarEstacion(string nombreEstacion, int tiempoSiguiente, int tiempoAnterior, bool esTransferencia)
{
    Estacion esta(nombreEstacion, tiempoSiguiente, tiempoAnterior, esTransferencia);
    estaciones.append(esta);
    numEstaciones += 1;
}


void Linea::eliminarEstacion(string nombreEstacion)
{
    for (unsigned short i = 0; i < numEstaciones; i++) {
        if (estaciones.getfirst()[i].getNombre() == nombreEstacion) {
            estaciones.delPos(i);
            break;
        }
    }
    numEstaciones -= 1;
}

bool Linea::verificarEstacion(string nombreEstacion)
{
    for (unsigned short i = 0; i < numEstaciones; i++) {
        if (estaciones.getfirst()[i].getNombre() == nombreEstacion) {
            return true;
        }
    }
    return false;
}

Estacion *Linea::getEstaciones()
{
    return estaciones.getfirst();
}

bool Linea::tieneEstacionesTransferencia() const
{
    for (unsigned short i = 0; i < numEstaciones; i++) {
        if (estaciones.getfirst()[i].getEsTransferencia()) {
            return true;
        }
    }
    return false;
}

bool Linea::operator ==(Linea &lin2)
{
    if ((nombre == lin2.getNombre()) && (tipoTransporte == lin2.getTipoTransporte()) && (this->getEstaciones() == lin2.getEstaciones()) && (numEstaciones == lin2.getCantidadEstaciones()))
    {
        return 1;
    }
    return 0;
}

Estacion* Linea::obtenerEstacionConSuNombre(string nombre)
{
    Estacion* estacion;
    unsigned short cont = 0;
    Estacion* Estaciones = this->estaciones.getfirst();
    while (cont < this->numEstaciones)
    {
        if (Estaciones[cont].getNombre() == nombre)
        {
            estacion = &(Estaciones[cont]);
            break;
        }
        cont += 1;
    }

    return estacion;
}

bool Linea::EstaIzquierdaDe(string estacionOrigen, string estacionFinal)
{
    Estacion* EstO = this->obtenerEstacionConSuNombre(estacionOrigen);
    Estacion* EstF = this->obtenerEstacionConSuNombre(estacionFinal);
    int posEstO = estaciones.index(*EstO);
    int posEstF = estaciones.index(*EstF);
    if(posEstO < posEstF) return 1;
    else return 0;
}
