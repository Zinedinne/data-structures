#include <iostream>

using namespace std;

class Nodo{
    int dato;
    Nodo *sig;
    public:
    Nodo();
    //~Nodo();
    void setDato(int x);
    int getDato();
    void setSig(Nodo * sig);
    Nodo * getSig();
};

Nodo::Nodo(){
    dato = 0;
    sig = NULL;
}

void Nodo::setDato(int x){
 dato=x;   
}

int Nodo::getDato(){
    return dato;
}

void Nodo::setSig(Nodo * sig){
    this->sig = sig;
}

Nodo * Nodo::getSig(){
    return sig;
}

class Cola{
    Nodo * fte;
    Nodo * fin;
    public:
    Cola();
    ~Cola();
    //Basicos
    void meter(int x);
    void sacar();
    int estaVacia();
    int getDato();
    //Complementarios
    void mostrar();
    int getFinal();
    void invertir();
    //Todos los que queramos
};

Cola::Cola(){
    fte=NULL;
    fin=NULL;
}

int Cola::estaVacia(){
    return fte==NULL;
}

int Cola::getDato(){
    if(estaVacia()){
        cout<<"Error cola vacia en getDato()";
        return -1;
    }
    return fte->getDato();
}

void Cola::meter(int x){
    Nodo *p;
    p=new Nodo;
    p->setDato(x);
    if(estaVacia()){
        fte=p;
    }else{
        fin->setSig(p);
    }
    fin=p;
}

void Cola::sacar(){ 
   if (estaVacia()){
       cout<<"No hay elementos \n";
    }else{
       Nodo *p;
       p=fte;
       if(fte->getSig()==NULL){
            fin=NULL;
            fte=fin;
            delete p;
       }else{      
            fte=fte->getSig();
            delete p;
       }
    }
}

void Cola::mostrar(){
    if(!estaVacia()){
        Nodo *p;
        p=fte;
        while (p!=NULL){
            cout<<p->getDato()<<" ";
            p=p->getSig();
        }
    }else{
        cout<<"\nLa cola esta vacia \n";
    }
}

Cola::~Cola(){
    Nodo *p;
    p=fte;
    while(!estaVacia()){
        fte = fte->getSig();
        delete p;
        p=fte;
    }
}

int main()
{
    Cola cola;
    cola.meter(1);
    cola.meter(2);
    cola.meter(3);
    cola.mostrar();
    cola.sacar();
    cola.mostrar();
    cola.sacar();
    cola.mostrar();
    cola.sacar();
    cola.mostrar();
    cola.sacar();
    return 0;
}
