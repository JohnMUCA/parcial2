#ifndef LINEA_H
#define LINEA_H

#include <iostream>
#include <string>
#include "VECTOR.h"
using namespace std;

class Linea {
private:
    string nombre;
    string tipoTransporte;
    unsigned short numEstaciones;
    VECTOR<string> estaciones;

public:
    Linea(string _nombre, string _tipoTransporte, unsigned short _numEstaciones);
    string getNombre() const;
    string getTipoTransporte() const;
    unsigned short getCantidadEstaciones() const;
    void agregarEstacion(string nombreEstacion);
    void eliminarEstacion(string nombreEstacion);
    bool verificarEstacion(string nombreEstacion);
};

#endif // LINEA_H
