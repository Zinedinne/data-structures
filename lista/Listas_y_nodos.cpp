#include <iostream>

using namespace std;

class Nodo{
    int dato;
    Nodo *sig;
    public:
    Nodo();
    //~Nodo();
    void setDato(int x);
    void setSig(Nodo *sig);
    int getDato();
    Nodo * getSig();
};

Nodo::Nodo(){
    dato = 0;
    sig = NULL;
}

void Nodo::setDato(int x){
 dato=x;   
}

void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}

int Nodo::getDato(){
    return dato;
}

Nodo * Nodo::getSig(){
    return sig;
}

class Lista{
    Nodo * cab;
    public:
    Lista();
    ~Lista();//la cosita se hace alt gr + *
    //Metodos basicos
    void insertar(int x);
    void eliminar();//Aqui al menos se hace desde la cabeza, no hace falta pasar posicion o asi
    int estaVacia();
    int getDato();
    //Metodos complementarios
    void mostrar();
    int getFinal();
    int getMayor();
    void insertarFinal(int x);
    void eliminarFinal();
    double getPromedio();
    void Invertir();
   
};

Lista::Lista(){
    cab = NULL;
}

void Lista::insertar(int x){//-> sirve para acceder a un objeto completo
    Nodo *p;//Declaraar el apuntador
    p=new Nodo;
    p->setDato(x);
    p->setSig(cab);
    cab = p;
}

int Lista::estaVacia(){
    if (cab==NULL){
        return 1;
    }else{
        return 0;
    }
}// return cab==NULL;

int Lista::getDato(){
    if (cab==NULL){
        cout<<"Error en getDato()";
        return -1;
    }
    return cab->getDato(); //Cabeza->getDato();
}

void Lista::eliminar(){
    if (cab!=NULL){
    Nodo *p;
    p=cab;
    cab = cab->getSig();
    delete p;
    }
    
}

void Lista::mostrar(){
    cout<<"Cab->";
    Nodo *p;
    p = cab;
    while (p!=NULL){
        cout<<p->getDato()<<"->";
        p = p->getSig();
    }
    cout<<"NULL";
}


Lista::~Lista(){
    Nodo *p;
    p=cab;
    while(cab!=NULL){
        cab = cab->getSig();
        delete p;
        p=cab;
    }
}


//Aqui comiienzan los mios de tarea

int Lista::getFinal(){
    Nodo *p;
    p = cab;
    if (p==NULL){
        return -1;
    }
    while(p->getSig()!=NULL){
        p=p->getSig();
    }
    return p->getDato();
}

int Lista::getMayor(){
    Nodo *p;
    p = cab;
    if (p==NULL){
    return -1;
    }
    int may;
    may = p->getDato();
    while (p!=NULL){
        if (may<p->getDato()){
            may=p->getDato();
        }
        p = p->getSig();
    }
    return may;
}

double Lista::getPromedio(){
    Nodo *p;
    p = cab;
    double sum=0;
    int cont=0;
    if(p==NULL){
        return -1;
    }
    while (p!=NULL){
        cont=cont+1;
        sum=sum+p->getDato();
        p = p->getSig();
        
    }
    return sum/cont;
}
    
    
void Lista::insertarFinal(int x){
    Nodo * q;
    q = new Nodo;
    q->setDato(x);
    if (estaVacia()){
        cab = q;
    }
    Nodo *p;
    p = cab;
    while(p->getSig()!=NULL){
        p=p->getSig();
    }
    p->setSig(q);
}

void Lista::eliminarFinal(){
    if (!estaVacia()){
    Nodo *p;
    p = cab;
    Nodo *q;
    q = NULL;
    while (p->getSig()!=NULL){
        q=p;
        p=p->getSig();
    }
    if (q==NULL)
        cab=NULL;
    else
        q->setSig(NULL);
    delete p;
    }
}

void Lista::Invertir(){
    Lista l2, l3;
    while(!estaVacia()){
        l2.insertar(getDato());
        eliminar();
    }
    while(!l2.estaVacia()){
        l3.insertar(l2.getDato());
        l2.eliminar();
    }
    while(!l3.estaVacia()){
        insertar(l3.getDato());
        l3.eliminar();
    }
}

//Aqui terminan ajjaj
int main()
{
    Lista lista;
    lista.insertar(2);
    lista.insertar(3);
    lista.insertar(7);
    lista.mostrar();
    cout<<" Mayor:  "<<lista.getMayor();
    cout<<" Final: "<<lista.getFinal();
    cout<<" Promedio:  "<<lista.getPromedio();
    lista.eliminar();
    cout<<"    ";
    lista.mostrar();
    cout<<" Mayor:  "<<lista.getMayor();
    cout<<" Final: "<<lista.getFinal();
    cout<<" Promedio:  "<<lista.getPromedio();
    
    //Lista vacia;
    cout<<"\nAqui comienza la lista vacia: ";
    Lista listavac;
    listavac.mostrar();
    cout<<listavac.getFinal();
    cout<<listavac.getPromedio();
    cout<<listavac.getMayor();
    
    //Lista de negativos
    cout<<"\nAqui comienza la lista con negativos: ";
    Lista listaNe;
    listaNe.insertar(-3);
    listaNe.insertar(-2);
    listaNe.mostrar();
    cout<<listaNe.getMayor();
    return 0;
}