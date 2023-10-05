#ifndef COLA_H
#define COLA_H
#include <iostream>

const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class Constancia
{
private:
    std::string nombre;
    std::string carrera;
    int totalMaterias;
    float promedio;
public:
    Constancia();
    Constancia(std::string n, std::string c, int t, float p);
    void operator=(Constancia& x);
    friend std::ostream& operator<<( std::ostream&, Constancia&);
    friend std::istream& operator>>( std::istream&, Constancia&);
    friend Constancia operator +(Constancia& e1, Constancia& e2);
    friend bool operator ==(Constancia& e1, Constancia& e2);
    friend bool operator !=(Constancia& e1, Constancia& e2);
	friend bool operator <(Constancia& e1, Constancia& e2);
    friend bool operator >(Constancia& e1, Constancia& e2);

};
//***************************************************************************************
//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Cola
{
private:
    Constancia datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Constancia& elem, int pos);
public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    void enqueue(Constancia& elem);
    Constancia& dequeue();
    int busquedaLineal(Constancia& c);
    int busquedaBinaria(Constancia& c);

};
//*************************************************************************************

#endif 
