#ifndef REDMETRO_H
#define REDMETRO_H

#include <iostream>
#include "VECTOR.h"
#include <string>
#include "Linea.h"

using namespace std;

class redMetro
{
private:
    VECTOR<Linea> lineas;
    unsigned short numLineas;

public:
    redMetro();
    unsigned short getNumLineas();
    void agregarLinea(string nombreLinea, string tipoTransp);
    void eliminarLinea(string nombreLinea);
    unsigned short getCantidadEstacionesRed();
    bool verificarEstacionEnLinea(string nombreEstacion, string nombreLinea);
    Linea* obtenerLineaConSuNombre(string nombre);
    Linea* getLineas();
};

#endif // REDMETRO_H
