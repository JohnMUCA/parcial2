#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>
using namespace std;
class Estacion{
private:
    string nombre;
    int tiempoSiguiente;
    int tiempoAnterior;
    bool esTransferencia;

public:
    Estacion(string _nombre, int _tiempoSiguiente, int _tiempoAnterior, bool _esTransferencia);
    string getNombre() const;
    int getTiempoSiguiente() const;
    int getTiempoAnterior() const;
    bool getEsTransferencia() const;
};
#endif // ESTACION_H
