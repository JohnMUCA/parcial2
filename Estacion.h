#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>
using namespace std;
class Estacion{
private:
    string nombre;
    unsigned short tiempoSiguiente;
    unsigned short tiempoAnterior;
    bool esTransferencia;

public:
    Estacion(string _nombre, unsigned short _tiempoSiguiente, unsigned short _tiempoAnterior, bool _esTransferencia);
    Estacion();
    string getNombre() const;
    unsigned short getTiempoSiguiente() const;
    unsigned short getTiempoAnterior() const;
    bool getEsTransferencia() const;
    bool operator ==(Estacion& esta2);
};
#endif // ESTACION_H
