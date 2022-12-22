/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

typedef int tipo_Dato;

class Nodo{
  tipo_Dato dato;
  Nodo *izq;
  Nodo *der;
  friend class Arbol; //Le doy permiso solo a la clase Arbol de acceder a sus datos y asi
  public:
  Nodo();
  
}

Nodo::Nodo(){
    dato=0;
    izq=NULL;
    der=NULL;
}

typedef *Nodo pNodo;

class Arbol{
    pNodo raiz;
    public:
    Arbol();
    ~Arbol();
    tipo_Dato getDato();
    int estaVacio();
    void agregarNodo(tipo_Dato x, pNodo & p);
    void agregar(tipo_Dato x);
    void eliminarNodo()tipo_Dato x, pNodo & p);
    void eliminar(tipo_Dato x);
    //metodos complementarios
    int estaX(tipo_Dato x, pNodo p);
    tipo_Dato getMenor(pNodo p);
    void mostrar(pNodo p);
    int getNivel(tipo_Dato x, pNodo p);
    int profundidad(pNodo p);
    int esHoja(tipo_Dato x, pNodo p);
    int esRaiz(tipo_Dato x, pNodo p);
    
}

Arbol::Arbol(){
    raiz=NULL;
}

int Arbol::estaVacio(){
    return raiz==NULL;
}

tipo_Dato Arbol::getDato(){
    if (estaVacio()){
        cout<<"Error: el arbol esta vacio";
        return -1;
    }
    return raiz->dato;
}

void Arbol::agregarNodo(tipo_Dato x, pNodo & p){
    if (p==NULL){
        p=new Nodo;
        p->dato=x;
    }
    if (x < p->dato){
        agregarNodo(x,p->izq);
    }
    if (x > p->dato){
        agregarNodo(x,p->der);
    }
    else{//quiere decir que x es==p->dato
    cout<<"El valor ya existe";
}

void Arbol::agregar(tipo_Dato x){
    agregarNodo(x,raiz);
}

int Arbol::estaX(tipo_Dato x){
    if(p==NULL){//no esta el dato
        return 0;
    }
    if (p->dato==x){ //encontramos el dato
        return 1;
    }
    if(x < p->dato){
        return estaX(x,p->izq);
    }
    else{//quiere decir que x es mayor a p->dato
        return estaX(x, p->der);
    }
}

int Arbol::getMenor(){
   if (p==NULL){
       cout<<"Error, el arbol esta vacio.";
       return -1;
   }
   if(p->izq == NULL){
       return p->dato;
   }
   else{
       return getMenor(p->izq);
   }
}

void eliminarNodo(tipo_Dato x, pNodo & p){
    if(p==NULL){//no esta el dato
        return 0;
    }
    if (p->dato==x){ //encontramos el dato
        Nodo *q;
        if (p->izq ==NULL){
            q=p;
            p=p->der;
            delete q;
        }
        else if (p->der==NULL){
            q=p;
            p=p->izq;
            delete q;
        }
        else{//tiene ambos hijos
            tipo_Dato m= getMenor(p->der);
            p->dato =m;
            eliminarNodo(m,p->der);
        }
    }
    if(x < p->dato){
        eliminarNodo(x,p->izq);
    }
    else{//quiere decir que x es mayor a p->dato
        eliminarNodo(x,p->der);
    }
}

void Arbol::eliminar(tipo_Dato x){
    eliminarNodo(x, raiz);
}

void Arbol::~Arbol(){
    while(!estaVacio()){
        eliminar(getMenor(raiz));//eliminar(raiz->dato);
    }
}

void Arbol::preOrden(pNodo p){ //Primero raiz, luego arbol izq y luego derecho
   if(p!=NULL){
       cout<<p->dato<<"  ";
       preOrden(p->izq);
       preOrden(p->der);
   }
}

void Arbol::getNivel(){//pts son recursivos
    
}

int Arbol::esHoja(){//pts son recursivos y analizar caso base en ambos
    
}

int main()
{
    cout<<"Hello World";

    return 0;
}