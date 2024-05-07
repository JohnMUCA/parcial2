#include "redmetro.h"

int main() {
    redMetro red_metro;
    int opcion;
    string tipoTransporte;
    string nombreLinea, nombreEstacion;
    unsigned short tiempoAnt, tiempoSig;
    bool esTransferencia;

    while (true) {
        cout << "1. Agregar linea\n";
        cout << "2. Agregar estacion a linea\n";
        cout << "3. Verificar estacion en linea\n";
        cout << "4. Mostrar informacion de la red de metro\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1) {

            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            cout << "Ingrese el tipo de transporte (Metro, Bus, etc.): ";
            cin >> tipoTransporte;
            red_metro.agregarLinea(nombreLinea, tipoTransporte);
            cout << endl;
            cout << "Linea agregada correctamente." << endl;
            cout << endl;
        } else if (opcion == 2) {

            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la estacion: ";
            cin >> nombreEstacion;
            cout << "Ingrese el tiempo en minutos a la anterior estacion(si es la primera estacion digite el cero): ";
            cin >> tiempoAnt;
            cout << "Ingrese el tiempo en minutos  a la siguiente estacion(si es la ultima estacion digite el cero): ";
            cin >> tiempoSig;
            cout << "Es una estacion de transferencia?(1: si. 0: no): ";
            cin >> esTransferencia;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    red_metro.getLineas()[i].agregarEstacion(nombreEstacion, tiempoSig, tiempoAnt, esTransferencia);
                    cout << endl;
                    cout << "Estacion agregada a la linea correctamente." << endl;
                    cout << endl;
                    break;
                }
            }
        } else if (opcion == 3) {

            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            cout << "Ingrese el nombre de la estacion: ";
            cin >> nombreEstacion;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    bool estaEnLinea = red_metro.getLineas()[i].verificarEstacion(nombreEstacion);
                    if (estaEnLinea) {
                        cout << endl;
                        cout << "La estacion '" << nombreEstacion << "' esta en la linea '" << nombreLinea << "'." << endl;
                        cout << endl;
                    } else {
                        cout << endl;
                        cout << "La estacion '" << nombreEstacion << "' no esta en la linea '" << nombreLinea << "'." << endl;
                        cout << endl;
                    }
                    break;
                }
                else cout << "La linea ingresada no existe." << endl;
                cout << endl;
            }
        } else if (opcion == 4) {
            cout << endl;
            cout << "Cantidad de lineas: " << red_metro.getNumLineas() << endl;
            cout << "Cantidad total de estaciones en la red: " << red_metro.getCantidadEstacionesRed() << endl;
            cout << endl;
        } else if (opcion == 5) {
            break;
        } else {
            cout << endl;
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
            cout << endl;
        }
    }

    return 0;
}
