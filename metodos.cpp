#include "Cola.h"

Constancia::Constancia(){
    nombre  = "";
    carrera = "";
    totalMaterias = 0;
    promedio = 0;
}

Constancia::Constancia(std::string n, std::string c, int t, float p): nombre(n), carrera(c), totalMaterias(t), promedio(p) {}
void Constancia::operator=(Constancia& x)
{
    nombre  = x.nombre;
    carrera = x.carrera;
    totalMaterias = x.totalMaterias;
    promedio = x.promedio;
}

std::ostream& operator<<( std::ostream& o, Constancia& x)
{
	o<<"***************************************Constancia***************************************"<<std::endl;
    o<<"nombre: "<<x.nombre<<"\t carrera: "<<x.carrera<<"\t total Materias: "<<x.totalMaterias<<"\t promedio: "<<x.promedio<<std::endl;
    return o;
}
std::istream& operator>>( std::istream& o, Constancia& x)
{
    std::cout<<"inserta nombre: ";
    o>>x.nombre;
    std::cout<<"inserta carrera: ";
    o>>x.carrera;
    std::cout<<"inserta total de materias cursadas: ";
    o>>x.totalMaterias;
    std::cout<<"inserta promedio: ";
    o>>x.promedio;
    return o;
}

bool Cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(Constancia& elem){
	if(llena()){
		std::cout<<"Cola llena, Atienda alumnos!"<<std::endl;
	}else
    	inserta(elem,0);
}
Constancia& Cola::dequeue(){
	ult--;
	return datos[ult+1];
}
bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Cola::inserta(Constancia& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}

Constancia operator +(Constancia& e1, Constancia& e2){
	return Constancia(e1.nombre+e2.nombre, e1.carrera+e2.carrera, e1.totalMaterias+e2.totalMaterias, e1.promedio+e2.promedio);
}
    	
bool operator ==(Constancia& e1, Constancia& e2){
    return (e1.nombre == e2.nombre &&
        e1.carrera == e2.carrera &&
        e1.totalMaterias == e2.totalMaterias &&
        e1.promedio == e2.promedio);
}

bool operator !=(Constancia& e1, Constancia& e2){
    return !(e1 == e2);
}
    
bool operator <(Constancia& e1, Constancia& e2) {
    return e1.promedio < e2.promedio;
}
    
bool operator >(Constancia& e1, Constancia& e2) {
    return e1.promedio > e2.promedio;
}

int Cola::busquedaLineal(Constancia& c){
    if(vacia()){
        return -1;
    }
    for(int i=ult; i>=0; i--){
        if(c==datos[i]){
            return (i-ult)*-1;
        }
    }
    return -1;
 }

int Cola::busquedaBinaria(Constancia& c) {
    int pm = 0;
    int sm = ult;

    while (pm <= sm) {
        int medio = pm + (sm - pm) / 2;

        if (datos[medio] == c) {
            return (medio-ult)*-1;
        } else if (datos[medio] < c) {
            pm = medio + 1;
        } else {
            sm = medio - 1;
        }
    }

    return -1;  // El objetivo no se encuentra en el arreglo
}
