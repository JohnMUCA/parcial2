#include "redmetro.h"

int main() {
    redMetro red_metro;
    int opcion;
    string tipoTransporte;
    string nombreLinea, nombreEstacion;
    unsigned short tiempoAnt, tiempoSig;
    bool esTransferencia;
    string estacionOriginal, estacionFinal;

    while (true) {
        cout << "1. Agregar linea\n";
        cout << "2. Agregar estacion a linea\n";
        cout << "3. Verificar estacion en linea\n";
        cout << "4. Mostrar informacion de la red de metro\n";
        cout << "5. Elminar linea de la Redmetro\n";
        cout << "6. Cuantas estaciones tiene una linea\n";
        cout << "7. Eliminar Estacion de una linea\n";
        cout << "8. Cuntas estaciones tiene la RedMetro\n";
        cout << "9. Calular el tiempo de viaje\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opcion: ";


        if (!(cin >> opcion)) {
            // Limpiar el flujo de entrada y descartar la entrada incorrecta
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Opcion invalida. Intente de nuevo." << endl;
            cout << endl;
            continue;
        }

        if (opcion == 1) {

            cout << endl;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            cout << endl;
            cout << "Ingrese el tipo de transporte (Metro, Bus, etc.): ";
            cin >> tipoTransporte;
            red_metro.agregarLinea(nombreLinea, tipoTransporte);
            cout << endl;
            cout << "Linea agregada correctamente." << endl;
            cout << endl;

        } else if (opcion == 2) {

            cout << endl;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
                bool lineaEncontrada = false;
                for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                    if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                        lineaEncontrada = true;
                        break;
                    }
                }

                if (!lineaEncontrada) {
                    cout << endl;
                    cout << "La linea ingresada no existe. Por favor, primero agregue la linea." << endl;
                    cout << endl;
                    continue;
                }
            cout << endl;
            cout << "Ingrese el nombre de la estacion: ";
            cin >> nombreEstacion;
            cout << endl;
            cout << "Ingrese el tiempo en minutos a la anterior estacion(si es la primera estacion digite el cero): ";
            cin >> tiempoAnt;
            cout << endl;
            cout << "Ingrese el tiempo en minutos  a la siguiente estacion(si es la ultima estacion digite el cero): ";
            cin >> tiempoSig;
            cout << endl;
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
            cout << endl;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            bool lineaEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    lineaEncontrada = true;
                    break;
                }
            }

            if (!lineaEncontrada) {
                cout << endl;
                cout << "La linea ingresada no existe." << endl;
                cout << endl;
                continue;
            }
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
            cout << endl;
            cout << "Ingrese el nombre de la linea a eliminar: ";
            cin >> nombreLinea;
            bool lineaEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    lineaEncontrada = true;
                    break;
                }
            }

            if (!lineaEncontrada) {
                cout << endl;
                cout << "La linea ingresada no existe." << endl;
                cout << endl;
                continue;
            }
            bool tieneTransferencias = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea && red_metro.getLineas()[i].tieneEstacionesTransferencia()) {
                    tieneTransferencias = true;
                    break;
                }
            }
            if (!tieneTransferencias) {
                red_metro.eliminarLinea(nombreLinea);
                cout << endl;
                cout << "Linea eliminada correctamente." << endl;
            } else {
                cout << endl;
                cout << "No se puede eliminar la linea porque tiene estaciones de transferencia." << endl;
            }
            cout << endl;
        } else if (opcion == 6) {
            cout << endl;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            bool lineaEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    cout << endl;
                    cout << "La linea " << nombreLinea << " tiene " << red_metro.getLineas()[i].getCantidadEstaciones() << " estaciones." << endl;
                    cout << endl;
                    lineaEncontrada = true;
                    break;
                }
            }
            if (!lineaEncontrada) {
                cout << endl;
                cout << "La linea '" << nombreLinea << "' no existe." << endl;
                cout << endl;
            }
        } else if (opcion == 7) {

            cout << endl;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            bool lineaEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    lineaEncontrada = true;
                    break;
                }
            }

            if (!lineaEncontrada) {
                cout << endl;
                cout << "La linea ingresada no existe." << endl;
                cout << endl;
                continue;
            }
            cout << "Ingrese el nombre de la estacion a eliminar: ";
            cin >> nombreEstacion;

            bool estacionEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    if (red_metro.getLineas()[i].verificarEstacion(nombreEstacion)) {
                        estacionEncontrada = true;
                        break;
                    }
                }
            }

            if (estacionEncontrada) {
                for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                    if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                        for (unsigned short j = 0; j < red_metro.getLineas()[i].getCantidadEstaciones(); j++) {
                            if (red_metro.getLineas()[i].getEstaciones()[j].getNombre() == nombreEstacion) {
                                if (!red_metro.getLineas()[i].getEstaciones()[j].getEsTransferencia()) {
                                    red_metro.getLineas()[i].eliminarEstacion(nombreEstacion);
                                    cout << endl;
                                    cout << "La estacion se ha eliminado con exito" << endl;
                                    cout << endl;
                                } else {
                                    cout << endl;
                                    cout << "No se puede eliminar una estacion de transferencia." << endl;
                                    cout << endl;
                                }
                                break;
                            }
                        }
                        break; // Salir del bucle una vez que se ha eliminado la estación
                    }
                }
            } else {
                cout << endl;
                cout << "La estacion ingresada no existe en la linea especificada." << endl;
                cout << endl;
            }
        } else if (opcion == 8) {
            cout << endl;
            cout << "La red Metro tiene un total de " << red_metro.getCantidadEstacionesRed() << " estaciones." << endl;
            cout << endl;
        } else if (opcion == 9) {
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            bool lineaEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    lineaEncontrada = true;
                    break;
                }
            }

            if (!lineaEncontrada) {
                cout << endl;
                cout << "La linea ingresada no existe." << endl;
                cout << endl;
                continue;
            }
            cout << "Ingrese el nombre de la estacion original: ";
            cin >> estacionOriginal;
            bool estacionOriginalEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    if (red_metro.getLineas()[i].verificarEstacion(estacionOriginal)) {
                        estacionOriginalEncontrada = true;
                        break;
                    }
                }
            }

            if (!estacionOriginalEncontrada) {
                cout << endl;
                cout << "La estacion original ingresada no existe en la linea especificada." << endl;
                cout << endl;
                continue;
            }
            cout << "Ingrese el nombre de la estacion final: ";
            cin >> estacionFinal;
            bool estacionFinalEncontrada = false;
            for (unsigned short i = 0; i < red_metro.getNumLineas(); i++) {
                if (red_metro.getLineas()[i].getNombre() == nombreLinea) {
                    if (red_metro.getLineas()[i].verificarEstacion(estacionFinal)) {
                        estacionFinalEncontrada = true;
                        break;
                    }
                }
            }

            if (!estacionFinalEncontrada) {
                cout << endl;
                cout << "La estacion final ingresada no existe en la linea especificada." << endl;
                cout << endl;
                continue;
            }

            unsigned short tiempoLlegada = red_metro.calcularTiempoLlegada(red_metro, nombreLinea, estacionOriginal, estacionFinal);
            cout << "El tiempo de llegada entre las estaciones '" << estacionOriginal << "' y '" << estacionFinal << "' en la linea '" << nombreLinea << "' es de " << tiempoLlegada << " minutos." << endl;
            cout << endl;
        } else if (opcion == 10) {
            break;
        } else {
            cout << endl;
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
            cout << endl;
        }
    }

    return 0;
}
