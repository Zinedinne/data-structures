#include <iostream>
#include <string.h>
using namespace std;

typedef string tipo_dato;
class Nodo{
    tipo_dato dato;
    int frecuencia;
    Nodo *izq;
    Nodo *der;
    friend class Arbol;
public:
    Nodo();
};
Nodo::Nodo(){
    dato="";
    frecuencia= 1;
    izq=NULL;
    der=NULL;
}
typedef Nodo* pNodo;
class Arbol{
    pNodo raiz;
public:
    //basicos
    Arbol();
    ~Arbol();
    tipo_dato getDato();
    int estaVacio();
    void agregarNodo(tipo_dato x, pNodo &p); 
    void agregar(tipo_dato x);
    void eliminarNodo(tipo_dato x, pNodo &p);
    void eliminar(tipo_dato x);
    //complementarios
    int estaX(tipo_dato x, pNodo p);
    tipo_dato getMenor(pNodo p);
    void mostrar();
    void mostrarPreOrden();
    void mostrarPosOrden();
    void mostrarInOrden();
    void preOrden(pNodo p);
    void inOrden(pNodo p);
    void posOrden(pNodo p);
    int getNivel(tipo_dato x, pNodo p);
    int profundidad(pNodo p);
    int esHoja(tipo_dato x, pNodo p);
    int esRaiz(tipo_dato x, pNodo p);
 
};
Arbol::Arbol(){
    raiz=0;
}
Arbol::~Arbol(){
    while(!estaVacio())
        eliminar(getMenor(raiz));
}
int Arbol::estaVacio(){
    return raiz==NULL;
}
tipo_dato Arbol::getDato(){
    if(estaVacio()){
        cout<<"arbol vacio\n";
        return "error";
    }
    return raiz->dato;
}
void Arbol::agregarNodo(tipo_dato x, pNodo &p){
    if(p==NULL){
        p=new Nodo;
        p->dato=x;
    }
    else{
        if(x<p->dato)
            agregarNodo(x, p->izq);
        if(x>p->dato)
            agregarNodo(x, p->der);
        else if(x==p->dato)
            p->frecuencia++;
            
    }
}
void Arbol::agregar(tipo_dato x){
    agregarNodo(x, raiz);
}
int Arbol::estaX(tipo_dato x, pNodo p){
    if(p==NULL) //no esta el dato
        return 0;
    if(p->dato==x)
        return 1;
    if(x<p->dato)
        return estaX(x, p->izq);
    return estaX(x, p->der); //x>p->dato
}
tipo_dato Arbol::getMenor(pNodo p){
    if(p==NULL){
        cout<<"arbol vacio\n";
        return "error";
    }
    if (p->izq==NULL)
        return p->dato;
    else
        return getMenor(p->izq);
}
void Arbol::eliminarNodo(tipo_dato x, pNodo &p){
    if(p==NULL)
        return;
    if(p->dato==x){
       if(p->frecuencia==1){
        Nodo *q;
        if(p->izq==NULL){
            q=p;
            p=p->der;
            delete q;
        }
        else if(p->der==NULL){
            q=p;
            p=p->izq;
            delete q;
        }
        else{
            tipo_dato m=getMenor(p->der);
            p->dato=m;
            eliminarNodo(m, p->der);
        }
      }else{
          if(p->frecuencia>1){
              p->frecuencia--;
          }
      }
    }
    else if(x<p->dato)
        eliminarNodo(x, p->izq);
    else
        eliminarNodo(x, p->der);
}
void Arbol::eliminar(tipo_dato x){
    eliminarNodo(x,raiz);
}

void Arbol::preOrden(pNodo p){
    if(p!=NULL){
        cout<<p->dato<<" ";
        cout<<"("<<p->frecuencia<<")";
        preOrden(p->izq);
        preOrden(p->der);
    }
}
void Arbol::inOrden(pNodo p){
    if(p!=NULL){
        inOrden(p->izq);
        cout<<p->dato<<" ";
        cout<<"("<<p->frecuencia<<")";
        inOrden(p->der);
    }
}
void Arbol::posOrden(pNodo p){
    if(p!=NULL){
        posOrden(p->izq);
        posOrden(p->der);
        cout<<p->dato<<" ";
        cout<<"("<<p->frecuencia<<")";
    }
}
void Arbol::mostrarPreOrden(){
    preOrden(raiz);
}
void Arbol::mostrarInOrden(){
    inOrden(raiz);
}
void Arbol::mostrarPosOrden(){
    posOrden(raiz);
}
int Arbol::profundidad(pNodo p){
    int izq, der;
    if(p==NULL)
        return 0;
    else{
        izq=profundidad(p->izq)+1;
        der=profundidad(p->der)+1;
        if(izq>der)
            return izq;
        else
            return der;
    }
}
int Arbol::esHoja(tipo_dato x, pNodo p){
    if(p==NULL) //no esta el dato
        return 0;
    if(p->dato==x){
        if(p->izq==NULL&&p->der==NULL)
            return 1;
        else
            return 0;
    }
    if(x<p->dato)
        return esHoja(x, p->izq);
    return esHoja(x, p->der);

}
int Arbol::getNivel(tipo_dato x, pNodo p){
    if(!estaX(x, raiz))
        return 0;
	if(p->dato==x)
        return 1;
	if(x<p->dato)
		return 1+getNivel(x, p->izq);
	else
		return 1+getNivel(x, p->der);
}

int main(){
    bool salir = true;
    int n;
    tipo_dato x;
    Arbol miArbol;
    cout<<"Cuantos nombres desea ingresar? \n";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el nombre "<<i+1<<"\n";
        getline(cin,x);
        miArbol.agregar(x);
    }
   
    while(salir){
    
    cout<<"\nSeleccione una accion\n";
    cout<<"1.-Agregar \n 2.-Eliminar \n 3.- mostrar PreOrden \n 4.- mostrar InOrden \n 5.-mostrar posOrden \n 6.-Salir \n";
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"Ingrese el nombre\n";
        cin.ignore();
        getline(cin,x);
        miArbol.agregar(x);
        break;
    case 2:    
        cout<<"elimimar\n";
        cout<<"Ingrese el nombre\n";
        cin.ignore();
        getline(cin,x);
        miArbol.eliminar(x);
        break;
    case 3:
        cout<<"preorden\n";
        miArbol.mostrarPreOrden();
        break;
    case 4:
        cout<<"inorden\n";
        miArbol.mostrarInOrden();
        break;
    case 5:
        cout<<"posorden\n";
        miArbol.mostrarPosOrden();
        break;
    default:
        cout<<"saliendo";
        salir=false;
        break;
    }
    
    //while
  }
    
    return 0;
}