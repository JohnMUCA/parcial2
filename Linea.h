#ifndef LINEA_H
#define LINEA_H

#include <iostream>
#include <string>
#include "VECTOR.h"
#include "Estacion.h"

using namespace std;

class Linea {
private:
    string nombre;
    string tipoTransporte;
    unsigned short numEstaciones;
    VECTOR<Estacion> estaciones;

public:
    Linea(string _nombre, string _tipoTransporte);
    Linea();
    string getNombre() const;
    string getTipoTransporte() const;
    unsigned short getCantidadEstaciones() const;
    void agregarEstacion(string nombreEstacion, int tiempoSiguiente, int tiempoAnterior, bool esTransferencia);
    void agregarEstacion(string nombreEstacion, bool esTransferencia);
    void eliminarEstacion(string nombreEstacion);
    bool verificarEstacion(string nombreEstacion);
    Estacion* getEstaciones();
    bool operator ==(Linea& lin2);

};

#endif // LINEA_H
