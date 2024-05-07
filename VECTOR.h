#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <class T>

class VECTOR
{

private:

    int longitud;
    T* estructura;

    void reservarEspacio()
    {
        T* aux = new T[this->longitud];
        this->copiarConte(estructura, aux);
        delete[] this->estructura;
        estructura = new T[this->longitud + 1];
        this->copiarConte(aux, estructura);
        delete[] aux;
    }

    void recortarEspacio()
    {
        T* aux = new T[this->longitud];
        this->copiarConte(estructura, aux);
        delete[] this->estructura;
        estructura = new T[this->longitud - 1];
        this->copiarConte(aux, estructura);
        delete[] aux;
    }

    void copiarConte(T *estructOrigin, T *estrucDestin)
    {
        for (int i = 0; i < this->longitud; i++)
        {
            estrucDestin[i] = estructOrigin[i];
        }
    }

public:

    VECTOR()
    {
        estructura = new T[0];
        longitud = 0;
    }

    VECTOR(unsigned short tam)
    {
        estructura = new T[tam];
        longitud = tam;
    }

    void append(T element)
    {
        this->reservarEspacio();
        this->longitud += 1;
        this->estructura[this->longitud - 1] = element;
    }

    T delPos(unsigned short pos)
    {
        T element = this->estructura[pos];
        for (int i = pos; i < this->longitud - 1; i++)
        {
            this->estructura[i] = this->estructura[i + 1];
        }
        this->recortarEspacio();
        this->longitud -= 1;
        return element;
    }

    int len()
    {
        return this->longitud;
    }

    T *getfirst()
    {
        return this->estructura;
    }

    int index(T element) const
    {
        unsigned short cont = 0;
        while (cont < longitud)
        {
            if (element == estructura[cont]) return cont;
        }
        return -1;
    }
};

#endif // VECTOR_H
