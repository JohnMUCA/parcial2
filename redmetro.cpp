#include "redmetro.h"

redMetro::redMetro()
{
    numLineas = 0;
}

unsigned short redMetro::getNumLineas()
{
    return this->numLineas;
}

void redMetro::agregarLinea(string nombreLinea, string tipoTransp)
{
    Linea lin(nombreLinea, tipoTransp);
    this->lineas.append(lin);
    numLineas += 1;
}

void redMetro::eliminarLinea(string nombreLinea)
{
    Linea* lin = obtenerLineaConSuNombre(nombreLinea);
    lineas.delPos(lineas.index(*lin));
    numLineas -= 1;
}

unsigned short redMetro::getCantidadEstacionesRed()
{
    unsigned short sum = 0;
    Linea* Lineas = this->lineas.getfirst();
    for (unsigned int i = 0; i < this->numLineas; i++)
    {
        sum += Lineas[i].getCantidadEstaciones();
    }
    return sum;
}

bool redMetro::verificarEstacionEnLinea(string nombreEstacion, string nombreLinea)
{
    return (this->obtenerLineaConSuNombre(nombreLinea)->verificarEstacion(nombreEstacion));
}

Linea *redMetro::obtenerLineaConSuNombre(string nombre)
{
    Linea* linea;
    unsigned short cont = 0;
    Linea* Lineas = this->lineas.getfirst();
    while (cont < this->numLineas)
    {
        if (Lineas[cont].getNombre() == nombre)
        {
            linea = &(Lineas[cont]);
            break;
        }
    }

    return linea;
}

Linea *redMetro::getLineas()
{
    return lineas.getfirst();
}


/*class RedMetro {
private:
VECTOR<Linea> lineas;

public:
unsigned short getCantidadLineas() const { return lineas.len(); }

void agregarLinea(Linea linea) { lineas.append(linea); }

void eliminarLinea(string nombreLinea) {
    for (unsigned short i = 0; i < lineas.len(); i++) {
        if (lineas.getfirst()[i].getNombre() == nombreLinea) {
            lineas.delPos(i);
            break;
        }
    }
}

unsigned short getCantidadEstacionesRed() const {
    unsigned short totalEstaciones = 0;
    for (unsigned short i = 0; i < lineas.len(); i++) {
        totalEstaciones += lineas.getfirst()[i].getCantidadEstaciones();
    }
    return totalEstaciones;
}

bool verificarEstacionEnLinea(string nombreEstacion, string nombreLinea) const {
    for (unsigned short i = 0; i < lineas.len(); i++) {
        if (lineas.getfirst()[i].getNombre() == nombreLinea) {
            return lineas.getfirst()[i].verificarEstacion(nombreEstacion);
        }
    }
    return false;
}
};*/
