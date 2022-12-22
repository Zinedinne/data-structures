#include <iostream>
#include <string>

using namespace std;

class Nodo{         //Se declara la clase nodo
    Nodo *sig;
    string matricula;
    string nombre;
    int semestre;
    public:
    Nodo();
    //~Nodo();
    void setSig(Nodo *sig);
    Nodo * getSig(); 
    string getMatricula();
    void setMatricula(string xmatricula);
    string getNombre();
    void setNombre(string xnombre);
    int getSemestre();
    void setSemestre(int xsemestre);

};

Nodo::Nodo(){   //constructor de nodo
    sig = NULL;
    nombre = "\0";
    matricula = "\0";
    semestre = 0;
}

//Se definen los metodos de la clase nodo
void Nodo::setMatricula(string xmatricula){
    this->matricula = xmatricula;

}
string Nodo::getMatricula(){
    return matricula;
}
void Nodo::setNombre(string xnombre){
    this->nombre = xnombre;
}
string Nodo::getNombre(){
    return nombre;
}
void Nodo::setSemestre(int xsemestre){
    this->semestre=xsemestre;
}
int Nodo::getSemestre(){
    return semestre;
}
void Nodo::setSig(Nodo *sig){
    this->sig = sig;
}

Nodo * Nodo::getSig(){
    return sig;
}

Nodo * llenarNodo(){    //Esta funcion se usa para llenar datos cada que se agrega un nuevo alumno tutorado
    Nodo *p;                        
    string matri,nom;
    int sem;
    cout<<"Ingresa la matricula: "; //se solicitan los datos 
    cin>>matri;
    cout<<"Ingresa el nombre: ";
    cin.ignore();
    getline(cin,nom);
    cout<<"Ingresa el semestre: ";
    cin>>sem;
    p=new Nodo; //Se crea el nodo con los datos ingresados, se crea primero para poder evaluar los valores y poder insertarlo ordenadamente
    p->setMatricula(matri);
    p->setNombre(nom);
    p->setSemestre(sem);
    return p;
}


//Se define la clase lista
class Lista{
    Nodo * cab;
    public:
    Lista();
    ~Lista();//la cosita se hace alt gr + *
    //Metodos basicos
    void insertarInicio();
    void insertarMatricula();
    void insertarSemestre();
    void insertarNombre();
    void eliminar();//Aqui al menos se hace desde la cabeza, no hace falta pasar posicion o asi
    void eliminarMatricula();
    void eliminarSemestre();
    void eliminarNombre();
    int estaVacia();
    //int getDato();
    //Metodos complementarios
    void mostrar();
};

//se definen metodos de la clase lista
Lista::Lista(){
    cab = NULL;
}
int Lista::estaVacia(){
        return cab==NULL;
}

void Lista::insertarMatricula(){ // si se elige priorizar matricula se inserta con este metodo
    Nodo *p=llenarNodo();
    
    if(estaVacia() || cab->getMatricula()>=p->getMatricula()){//si la lista esta vacia o solo el nuevo elemento es el menor
        p->setSig(cab);
        cab=p;
        }else{//la lista tiene mas de un elemento
            Nodo *q = cab;
            while(q->getSig()!=NULL && q->getSig()->getMatricula()<=p->getMatricula()){
                    q=q->getSig();
                    }
                if(q->getSig()!=NULL){//si el semestre es mayor a todos los de la lista
                    p->setSig(q->getSig());
                    }
                q->setSig(p);
            }
}

void Lista::insertarNombre(){ //si se elige priorizar nombre se usa este metodo
    Nodo *p=llenarNodo();
    
    if(estaVacia() || cab->getNombre()>=p->getNombre()){//si la lista esta vacia o solo el nuevo elemento es el menor
        p->setSig(cab);
        cab=p;
        }else{//la lista tiene mas de un elemento
            Nodo *q = cab;
            while(q->getSig()!=NULL && q->getSig()->getNombre()<=p->getNombre()){
                    q=q->getSig();
                    }
                if(q->getSig()!=NULL){//si el semestre es mayor a todos los de la lista
                    p->setSig(q->getSig());
                    }
                q->setSig(p);
            }
}

void Lista::insertarSemestre(){ //si se elige priorizar semestre se usa este metodo
    Nodo *p=llenarNodo();   
    
    if(estaVacia() || cab->getSemestre()>=p->getSemestre()){//si la lista esta vacia o solo el nuevo elemento es el menor
        p->setSig(cab);
        cab=p;
        }else{//la lista tiene mas de un elemento
            Nodo *q = cab;
            while(q->getSig()!=NULL && q->getSig()->getSemestre()<=p->getSemestre()){
                    q=q->getSig();
                    }
                if(q->getSig()!=NULL){//si el semestre es mayor a todos los de la lista
                    p->setSig(q->getSig());
                    }
                q->setSig(p);
            }
}

void Lista::mostrar(){  //metodo mostrar
    Nodo *p;
    p = cab;
    while (p!=NULL){
        cout<<"----------------------------------- \n";
        cout<<"Matricula: "<<p->getMatricula()<<"\n";
        cout<<"Nombre: "<<p->getNombre()<<"\n";
        cout<<"Semestre: "<<p->getSemestre()<<"\n";
        p = p->getSig();
    }
}

Lista::~Lista(){    //destructor de la clase lista
    Nodo *p;
    p=cab;
    while(cab!=NULL){
        cab = cab->getSig();
        delete p;
        p=cab;
    }
}    

void Lista::eliminar(){ //metodo eliminar
    if (cab!=NULL){
    Nodo *p;
    p=cab;
    cab = cab->getSig();
    delete p;
    }
}

void Lista::eliminarSemestre(){
    cout<<"Ingresa el semestre que quieres eliminar\n";
    int val;
    cin>>val;
     if(cab->getSemestre()==val){
        cab=cab->getSig();
    }else{
        if (!estaVacia()){
    Nodo *p;
    p = cab;
    Nodo *q;
    q = NULL;
    while (p->getSemestre()!=val){
        q=p;
        p=p->getSig();
    }
    if (q==NULL)
        cab=NULL;
    else{
        if(p->getSig()!=NULL){
        q->setSig(p->getSig());
            }else{
                  q->setSig(NULL);
            }
        }
    delete p;
    }
    }
}

void Lista::eliminarMatricula(){
    cout<<"Ingresa la matricula que quieres eliminar\n";
    string val;
    cin.ignore();
    getline(cin, val);
     if(cab->getMatricula()==val){
        cab=cab->getSig();
    }else{
        if (!estaVacia()){
    Nodo *p;
    p = cab;
    Nodo *q;
    q = NULL;
    while (p->getMatricula()!=val){
        q=p;
        p=p->getSig();
    }
    if (q==NULL)
        cab=NULL;
    else{
        if(p->getSig()!=NULL){
        q->setSig(p->getSig());
            }else{
                  q->setSig(NULL);
            }
        }
    delete p;
    }
    }
}

void Lista::eliminarNombre(){
    cout<<"Ingresa el nombre que quieres eliminar\n";
    string val;
    cin.ignore();
    getline(cin,val);
    if(cab->getNombre()==val){
        cab=cab->getSig();
    }else{
        if (!estaVacia()){
    Nodo *p;
    p = cab;
    Nodo *q;
    q = NULL;
    while (p->getNombre()!=val){
        q=p;
        p=p->getSig();
    }
    if (q==NULL)
        cab=NULL;
    else{
        if(p->getSig()!=NULL){
        q->setSig(p->getSig());
            }else{
                  q->setSig(NULL);
            }
        }
    delete p;
    }
    }
}

int main (){
    int n,r,op; //Primero se ingresa al codigo y se pregunta la cantidad de inserciones iniciales que se desean
    Lista lista;
    cout<<"Ingresa el numero de tutorados para iniciar: ";
    cin>>n;
    cout<<"¿Que atributo desea priorizar para la insercion? \n";
    cout<<" 1.-Matricula \n 2.-Nombre \n 3.- Semestre \n";
    cin>>r; // aparte de servir al switch, esta variable se usa despues para que cada vez que se quiera ingresar un nuevo alumno se haga con la misma prioridad
    switch (r)
    {
    case 1:
        cout<<"Piorizar matricula \n";  //segun la opcion r se utiliza el metodo de insercion
        for(int i=0;i<n;i++){           
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarMatricula();
        }
        break;
    case 2:    
        cout<<"Priorizar nombre \n";
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarNombre();
        }
        break;
    case 3:
        cout<<"Priorizar semestre \n";
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarSemestre();
        }
        break;
    default:
        cout<<"Error numero no valido, se usara la prioridad por defecto \n";  //si se elige otro valor hacemos que r valga 1, y que se priorice matricula
        r=1;
        for(int i=0;i<n;i++){
            cout<<"Ingresa los datos del alumno "<<i+1<<"\n";
            lista.insertarMatricula();
        }
        break;
    }
    bool val=true;
    
    while(val){ //mientras el val no cambie se seguira ejecutando el menu principal
        cout<<"Menu principal\n";
        cout<<"La R es"<< r<<"\n";  //la r es para ver el metodo de insercion que se usa
        cout<<" 1.-Insertar nuevo tutorado \n 2.-Eliminar tutorado \n 3.- Mostrar lista de tutorados \n 4.-Salir \n";
        
        cin>>op;
        
        switch (op)
        {
        case 1:
           cout<<"Insertar \n"; //Segun el valor de r que se guardo, el sistema ya conoce la prioridad con la que se desea insertar
            if(r==1){
                lista.insertarMatricula();
            }
            else{
                if(r==2){
                lista.insertarNombre();
                }
                else{
                    lista.insertarSemestre();
                }
            }
            
            break;
        case 2:
          cout<<"Eliminar \n";
          if(r==1){
                lista.eliminarMatricula();
            }
            else{
                if(r==2){
                lista.eliminarNombre();
                }
                else{
                    lista.eliminarSemestre();
                }
            }
            break;
        case 3:
         cout<<"Lista de tutorados \n";
            lista.mostrar();
            break;
        case 4:
            cout<<"Salir";
            val=false;  //cambia el val y finaliza la ejecucion
            break;
     default:
         cout<<"Error opcion no valida, intente de nuevo \n";
         break;
      }
    }
}