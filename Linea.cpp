#include "Linea.h"

Linea::Linea(string _nombre, string _tipoTransporte, unsigned short _numEstaciones)
{
    nombre= _nombre;
    tipoTransporte= _tipoTransporte;
    numEstaciones = _numEstaciones;
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

void Linea::agregarEstacion(string nombreEstacion)
{
    estaciones.append(nombreEstacion);
    numEstaciones += 1;
}

void Linea::eliminarEstacion(string nombreEstacion)
{
    for (unsigned short i = 0; i < numEstaciones; i++) {
        if (estaciones.getfirst()[i] == nombreEstacion) {
            estaciones.delPos(i);
            break;
        }
    }
    numEstaciones -= 1;
}

bool Linea::verificarEstacion(string nombreEstacion)
{
    for (unsigned short i = 0; i < numEstaciones; i++) {
        if (estaciones.getfirst()[i] == nombreEstacion) {
            return true;
        }
    }
    return false;
}
