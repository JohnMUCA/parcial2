#include "Estacion.h"

Estacion::Estacion(string _nombre, unsigned short _tiempoSiguiente, unsigned short _tiempoAnterior, bool _esTransferencia)
{
    nombre = _nombre;
    tiempoSiguiente = _tiempoSiguiente;
    tiempoAnterior = _tiempoAnterior;
    esTransferencia =_esTransferencia;
}

Estacion::Estacion()
{
    nombre = "";
    tiempoSiguiente = 0;
    tiempoAnterior = 0;
    esTransferencia = 0;
}

string Estacion::getNombre() const
{
    return nombre;
}

unsigned short Estacion::getTiempoSiguiente() const
{
    return tiempoSiguiente;
}

unsigned short Estacion::getTiempoAnterior() const
{
    return tiempoAnterior;
}

bool Estacion::getEsTransferencia() const
{
    return esTransferencia;
}

bool Estacion::operator ==(Estacion &esta2)
{
    bool bandera = 0;
    if ((nombre == esta2.getNombre()) && (tiempoAnterior == esta2.getTiempoAnterior()) && (tiempoSiguiente == esta2.getTiempoSiguiente()) && (esTransferencia == esta2.getEsTransferencia()))
    {
        bandera = 1;
    }
    return bandera;
}
