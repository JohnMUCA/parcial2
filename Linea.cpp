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

bool Linea::operator ==(Linea &lin2)
{
    if ((nombre == lin2.getNombre()) && (tipoTransporte == lin2.getTipoTransporte()) && (this->getEstaciones() == lin2.getEstaciones()) && (numEstaciones == lin2.getCantidadEstaciones()))
    {
        return 1;
    }
    return 0;
}
