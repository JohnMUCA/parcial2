#include "Estacion.h"

Estacion::Estacion(string _nombre, int _tiempoSiguiente, int _tiempoAnterior, bool _esTransferencia)
{
    nombre =_nombre;
    tiempoSiguiente = _tiempoSiguiente;
    tiempoAnterior = _tiempoAnterior;
    esTransferencia =_esTransferencia;
}

string Estacion::getNombre() const
{
    return nombre;
}

int Estacion::getTiempoSiguiente() const
{
    return tiempoSiguiente;
}

int Estacion::getTiempoAnterior() const
{
    return tiempoAnterior;
}

bool Estacion::getEsTransferencia() const
{
    return esTransferencia;
}
