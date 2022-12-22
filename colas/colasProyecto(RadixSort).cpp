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
        cout<<"Error cola vacia ";
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
        cout<<"La cola esta vacia \n";
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
    int n, a; //declaramos n para guardar la cantidad de elementos y a para el llenado de la cola
    Cola colaBase;//Declaramos la cola base que vamos a usar
    Cola cola0, cola1, cola2, cola3, cola4, cola5, cola6, cola7, cola8, cola9;//Declaramos las colas que vamos a usar para ordenar
    
    cout<<"Ingrese la cantidad de numeros a ordenar\n";//Llenamos la cola base
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el valor "<<i+1<<"\n";
        cin>>a;
        colaBase.meter(a);
    }
    
    cout<<"\nESTADO INICIAL\n";
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n"; 
    getchar();
    getchar();
    /*
    PRIMERA ITERACION (por unidades)
    */
    while(!colaBase.estaVacia()){    //Vaciamos por unidades la cola base en las 9 colas
        int x = colaBase.getDato()%10; //evaluamos las unidades del dato e insertamos en la cola correspondiente
        switch(x){
            case 0:
                cola0.meter(colaBase.getDato());
              break;
            case 1:
                cola1.meter(colaBase.getDato());
              break;
            case 2:
                cola2.meter(colaBase.getDato());
              break;
            case 3:
                cola3.meter(colaBase.getDato());
              break;
            case 4:
                cola4.meter(colaBase.getDato());
              break;
            case 5:
                cola5.meter(colaBase.getDato());
              break;
            case 6:
                cola6.meter(colaBase.getDato());
              break;
            case 7:
                cola7.meter(colaBase.getDato());
              break;
            case 8:
                cola8.meter(colaBase.getDato());
              break;
            case 9:
                cola9.meter(colaBase.getDato());
              break;
            }
        colaBase.sacar();
        }
    cout<<"\nESTADO TRAS EVALUAR UNIDADES\n";    
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    //regresar los elementos a la cola colaBase
        
    while(!cola0.estaVacia()){    //Vaciamos la cola 0 en la colaBase
        colaBase.meter(cola0.getDato());
        cola0.sacar();
        }
        
    while(!cola1.estaVacia()){    //Vaciamos la cola 1 en la colaBase
        colaBase.meter(cola1.getDato());
        cola1.sacar();
        }
        
    while(!cola2.estaVacia()){    //Vaciamos la cola 2 en la colaBase
        colaBase.meter(cola2.getDato());
        cola2.sacar();
        }
            
    while(!cola3.estaVacia()){    //Vaciamos la cola 3 en la colaBase
        colaBase.meter(cola3.getDato());
        cola3.sacar();
        }
            
    while(!cola4.estaVacia()){    //Vaciamos la cola 4 en la colaBase
        colaBase.meter(cola4.getDato());
        cola4.sacar();
        }
            
    while(!cola5.estaVacia()){    //Vaciamos la cola 5 en la colaBase
        colaBase.meter(cola5.getDato());
        cola5.sacar();
        }
            
    while(!cola6.estaVacia()){    //Vaciamos la cola 6 en la colaBase
        colaBase.meter(cola6.getDato());
        cola6.sacar();
        }
            
    while(!cola7.estaVacia()){    //Vaciamos la cola 7 en la colaBase
        colaBase.meter(cola7.getDato());
        cola7.sacar();
        }
            
    while(!cola8.estaVacia()){    //Vaciamos la cola 8 en la colaBase
        colaBase.meter(cola8.getDato());
        cola8.sacar();
        }
            
    while(!cola9.estaVacia()){    //Vaciamos la cola 9 en la colaBase
        colaBase.meter(cola9.getDato());
        cola9.sacar();
        }
        
    cout<<"\nESTADO TRAS REGRESAR A LA COLA BASE\n";     
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    /*
    SEGUNDA ITERACION (por decenas)
    */
    while(!colaBase.estaVacia()){    //Vaciamos por decenas la cola base en las 9 colas
        int x = (colaBase.getDato()/10)%10; //evaluamos las decenas del dato e insertamos en la cola correspondiente
        switch(x){
            case 0:
                cola0.meter(colaBase.getDato());
              break;
            case 1:
                cola1.meter(colaBase.getDato());
              break;
            case 2:
                cola2.meter(colaBase.getDato());
              break;
            case 3:
                cola3.meter(colaBase.getDato());
              break;
            case 4:
                cola4.meter(colaBase.getDato());
              break;
            case 5:
                cola5.meter(colaBase.getDato());
              break;
            case 6:
                cola6.meter(colaBase.getDato());
              break;
            case 7:
                cola7.meter(colaBase.getDato());
              break;
            case 8:
                cola8.meter(colaBase.getDato());
              break;
            case 9:
                cola9.meter(colaBase.getDato());
              break;
            }
        colaBase.sacar();
        }
    
    cout<<"\nESTADO TRAS EVALUAR DECENAS\n";    
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    
    //regresar los elementos a la cola colaBase
        
    while(!cola0.estaVacia()){    //Vaciamos la cola 0 en la colaBase
        colaBase.meter(cola0.getDato());
        cola0.sacar();
        }
        
    while(!cola1.estaVacia()){    //Vaciamos la cola 1 en la colaBase
        colaBase.meter(cola1.getDato());
        cola1.sacar();
        }
        
    while(!cola2.estaVacia()){    //Vaciamos la cola 2 en la colaBase
        colaBase.meter(cola2.getDato());
        cola2.sacar();
        }
            
    while(!cola3.estaVacia()){    //Vaciamos la cola 3 en la colaBase
        colaBase.meter(cola3.getDato());
        cola3.sacar();
        }
            
    while(!cola4.estaVacia()){    //Vaciamos la cola 4 en la colaBase
        colaBase.meter(cola4.getDato());
        cola4.sacar();
        }
            
    while(!cola5.estaVacia()){    //Vaciamos la cola 5 en la colaBase
        colaBase.meter(cola5.getDato());
        cola5.sacar();
        }
            
    while(!cola6.estaVacia()){    //Vaciamos la cola 6 en la colaBase
        colaBase.meter(cola6.getDato());
        cola6.sacar();
        }
            
    while(!cola7.estaVacia()){    //Vaciamos la cola 7 en la colaBase
        colaBase.meter(cola7.getDato());
        cola7.sacar();
        }
            
    while(!cola8.estaVacia()){    //Vaciamos la cola 8 en la colaBase
        colaBase.meter(cola8.getDato());
        cola8.sacar();
        }
            
    while(!cola9.estaVacia()){    //Vaciamos la cola 9 en la colaBase
        colaBase.meter(cola9.getDato());
        cola9.sacar();
        }
        
    cout<<"\nESTADO TRAS REGRESAR A LA COLA BASE\n";     
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    /*
    TERCERA ITERACION (por centenas)
    */
    
    while(!colaBase.estaVacia()){    //Vaciamos por centenas la cola base en las 9 colas
        int x = (colaBase.getDato()/100)%10; //evaluamos las centenas del dato e insertamos en la cola correspondiente
        switch(x){
            case 0:
                cola0.meter(colaBase.getDato());
              break;
            case 1:
                cola1.meter(colaBase.getDato());
              break;
            case 2:
                cola2.meter(colaBase.getDato());
              break;
            case 3:
                cola3.meter(colaBase.getDato());
              break;
            case 4:
                cola4.meter(colaBase.getDato());
              break;
            case 5:
                cola5.meter(colaBase.getDato());
              break;
            case 6:
                cola6.meter(colaBase.getDato());
              break;
            case 7:
                cola7.meter(colaBase.getDato());
              break;
            case 8:
                cola8.meter(colaBase.getDato());
              break;
            case 9:
                cola9.meter(colaBase.getDato());
              break;
            }
        colaBase.sacar();
        }
    
    cout<<"\nESTADO TRAS EVALUAR CENTENAS\n";    
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    //regresar los elementos a la cola colaBase
        
    while(!cola0.estaVacia()){    //Vaciamos la cola 0 en la colaBase
        colaBase.meter(cola0.getDato());
        cola0.sacar();
        }
        
    while(!cola1.estaVacia()){    //Vaciamos la cola 1 en la colaBase
        colaBase.meter(cola1.getDato());
        cola1.sacar();
        }
        
    while(!cola2.estaVacia()){    //Vaciamos la cola 2 en la colaBase
        colaBase.meter(cola2.getDato());
        cola2.sacar();
        }
            
    while(!cola3.estaVacia()){    //Vaciamos la cola 3 en la colaBase
        colaBase.meter(cola3.getDato());
        cola3.sacar();
        }
            
    while(!cola4.estaVacia()){    //Vaciamos la cola 4 en la colaBase
        colaBase.meter(cola4.getDato());
        cola4.sacar();
        }
            
    while(!cola5.estaVacia()){    //Vaciamos la cola 5 en la colaBase
        colaBase.meter(cola5.getDato());
        cola5.sacar();
        }
            
    while(!cola6.estaVacia()){    //Vaciamos la cola 6 en la colaBase
        colaBase.meter(cola6.getDato());
        cola6.sacar();
        }
            
    while(!cola7.estaVacia()){    //Vaciamos la cola 7 en la colaBase
        colaBase.meter(cola7.getDato());
        cola7.sacar();
        }
            
    while(!cola8.estaVacia()){    //Vaciamos la cola 8 en la colaBase
        colaBase.meter(cola8.getDato());
        cola8.sacar();
        }
            
    while(!cola9.estaVacia()){    //Vaciamos la cola 9 en la colaBase
        colaBase.meter(cola9.getDato());
        cola9.sacar();
        }
        
    cout<<"\nESTADO TRAS REGRESAR A LA COLA BASE\n";     
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    
    /*
    CUARTA ITERACION  (por millares)
    */
    
    while(!colaBase.estaVacia()){    //Vaciamos por millares la cola base en las 9 colas
        int x = colaBase.getDato()/1000; //evaluamos los millares del dato e insertamos en la cola correspondiente
        switch(x){
            case 0:
                cola0.meter(colaBase.getDato());
              break;
            case 1:
                cola1.meter(colaBase.getDato());
              break;
            case 2:
                cola2.meter(colaBase.getDato());
              break;
            case 3:
                cola3.meter(colaBase.getDato());
              break;
            case 4:
                cola4.meter(colaBase.getDato());
              break;
            case 5:
                cola5.meter(colaBase.getDato());
              break;
            case 6:
                cola6.meter(colaBase.getDato());
              break;
            case 7:
                cola7.meter(colaBase.getDato());
              break;
            case 8:
                cola8.meter(colaBase.getDato());
              break;
            case 9:
                cola9.meter(colaBase.getDato());
              break;
            }
        colaBase.sacar();
        }
    
    cout<<"\nESTADO TRAS EVALUAR MILLARES\n";    
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    
    //regresar los elementos a la cola colaBase
        
    while(!cola0.estaVacia()){    //Vaciamos la cola 0 en la colaBase
        colaBase.meter(cola0.getDato());
        cola0.sacar();
        }
        
    while(!cola1.estaVacia()){    //Vaciamos la cola 1 en la colaBase
        colaBase.meter(cola1.getDato());
        cola1.sacar();
        }
        
    while(!cola2.estaVacia()){    //Vaciamos la cola 2 en la colaBase
        colaBase.meter(cola2.getDato());
        cola2.sacar();
        }
            
    while(!cola3.estaVacia()){    //Vaciamos la cola 3 en la colaBase
        colaBase.meter(cola3.getDato());
        cola3.sacar();
        }
            
    while(!cola4.estaVacia()){    //Vaciamos la cola 4 en la colaBase
        colaBase.meter(cola4.getDato());
        cola4.sacar();
        }
            
    while(!cola5.estaVacia()){    //Vaciamos la cola 5 en la colaBase
        colaBase.meter(cola5.getDato());
        cola5.sacar();
        }
            
    while(!cola6.estaVacia()){    //Vaciamos la cola 6 en la colaBase
        colaBase.meter(cola6.getDato());
        cola6.sacar();
        }
            
    while(!cola7.estaVacia()){    //Vaciamos la cola 7 en la colaBase
        colaBase.meter(cola7.getDato());
        cola7.sacar();
        }
            
    while(!cola8.estaVacia()){    //Vaciamos la cola 8 en la colaBase
        colaBase.meter(cola8.getDato());
        cola8.sacar();
        }
            
    while(!cola9.estaVacia()){    //Vaciamos la cola 9 en la colaBase
        colaBase.meter(cola9.getDato());
        cola9.sacar();
        }
        
    cout<<"\nESTADO TRAS REGRESAR A LA COLA BASE\n";     
    //revisamos el estado de las colas
    cout<<"\nEl contenido de la cola base\n";
    colaBase.mostrar();
    cout<<"\nEl contenido de la cola 0\n";
    cola0.mostrar();
    cout<<"\nEl contenido de la cola 1\n";
    cola1.mostrar();
    cout<<"\nEl contenido de la cola 2\n";
    cola2.mostrar();
    cout<<"\nEl contenido de la cola 3\n";
    cola3.mostrar();
    cout<<"\nEl contenido de la cola 4\n";
    cola4.mostrar();
    cout<<"\nEl contenido de la cola 5\n";
    cola5.mostrar();
    cout<<"\nEl contenido de la cola 6\n";
    cola6.mostrar();
    cout<<"\nEl contenido de la cola 7\n";
    cola7.mostrar();
    cout<<"\nEl contenido de la cola 8\n";
    cola8.mostrar();
    cout<<"\nEl contenido de la cola 9\n";
    cola9.mostrar();
    cout<<"\nPresione cualquier tecla para continuar...\n";
    getchar();
    
    return 0;
}



