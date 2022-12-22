#include <string.h>
#include <iostream>
using namespace std;

class Nodo{
    char dato;
    Nodo * sig;
    //Constructor getter y setter
    //es lo mismo que los otros nodos que hemos hecho
    public:
    Nodo();
    
    void setDato(char x);
    void setSig(Nodo *sig);
    char getDato();
    Nodo *getSig();
};
Nodo::Nodo(){
    dato =' ';
    sig= NULL;
}

void Nodo::setDato(char x){
    dato =x;
}

void Nodo::setSig(Nodo *sig){
    
    this->sig = sig;
}

char Nodo::getDato(){
    return dato;
}

Nodo *Nodo::getSig(){
    return sig;
}

class Pila{
    Nodo * tope;
    //Metodos basicos
    public:
    Pila();
    ~Pila();
    int estaVacia();
    char getDato();
    void push(char x);
    void pop();
    //metodos complementarios
    void mostrar();
    int getMayor();
    double getPromedio();
    void invertir();
    void pushFinal(char x);
    //Todos los que queramos tambien
};

Pila::Pila(){
    tope=NULL;
}

int Pila::estaVacia(){
    return tope==NULL;
}

char Pila::getDato(){
    if (estaVacia()){
        cout<<"La pila esta Vacia";
        return -1;
    }
    return tope->getDato();
}

void Pila::push(char x){
    Nodo *p;
    p = new Nodo;
    p->setDato(x);
    p->setSig(tope);
    tope=p;
}

void Pila::pop(){
    if(tope !=NULL){
        Nodo *p;
        p=tope;
        tope=p->getSig();
        delete p;
    }
}

Pila::~Pila(){
    while(!estaVacia())
    pop();
}

void Pila::mostrar(){
    cout<<" Tope -> ";
    Pila paux;
    while(!estaVacia()){
        paux.push(getDato());
        cout<<getDato()<<" -> ";
        pop();
    }
    while(!paux.estaVacia()){
        push(paux.getDato());
        paux.pop();
    }
    cout<<"NULL";
}

int main()
{
    Pila pila, pilaux2;
    int parentesis=0, corchete=0, llave=0;
    char palabra[50]="";
    cin>>palabra;
    for(int i=0;i<strlen(palabra);i++){
        pila.push(palabra[i]);
    }
    //Aqui hacemos el recorrido por la pila y checamos cuantos parentesis, corchetes y llaves hay y los almacenamos en sus respectivas variables)
    //si una variable esta en 0 quiere decir que esta equilibrada (Cuenta con el simbolo que abre y cierra o ninguno), si tiene -1 quiere decir que le falta el simbolo que abre y si tiene 1 quiere decir que le falta el simbolo que cierra 
    //cuando un simbolo abre se suma 1 y cuando un simbolo cierra se resta 1
    while(!pila.estaVacia()){
        if (pila.getDato()=='('){
            parentesis=parentesis+1;
        }
        if (pila.getDato()=='['){
            corchete=corchete+1;
        }
        if (pila.getDato()=='{'){
            llave=llave+1;
        }
        if (pila.getDato()==')'){
            parentesis=parentesis-1;
        }
        if (pila.getDato()=='}'){
            llave=llave-1;
        }
        if (pila.getDato()==']'){
            corchete=corchete-1;
        }
        pilaux2.push(pila.getDato());
        pila.pop();
        
    }
    while(!pilaux2.estaVacia()){
        pila.push(pilaux2.getDato());
        pilaux2.pop();
    }
    //Aqui ya se muestra que separadores hacen falta
    if(parentesis>0){
        cout<<"\nHace/n falta "<<parentesis<<": )";
    }
    if(parentesis<0){
        cout<<"\nHace/n falta "<<parentesis*-1<<": (";
    }
    if(llave>0){
        cout<<"\nHace/n falta "<<llave<<": }";
    }
    if(llave<0){
        cout<<"\nHace/n falta "<<llave*-1<<": {";
    }
    if(corchete>0){
        cout<<"\nHace/n falta "<<corchete<<": ]";
    }
    if(corchete<0){
        cout<<"\nHace/n falta "<<corchete*-1<<": [";
    }
    
    if(parentesis==0 && corchete==0 && llave== 0){
        cout<<"\nLa expresion es correcta";
    }
    
    return 0;
}