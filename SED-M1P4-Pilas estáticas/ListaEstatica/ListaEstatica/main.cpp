#include <iostream>
#define TAM 50

//plantillas
class Lista{
private:
    float datos[TAM];
    int ult;
public:
    Lista():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool inserta(float , int);
    bool elimina(int);
    float recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
    int buscar(float);
};

int Lista::buscar(float elem){
    int i=0;
    while(i<=ult){
        if(elem ==datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

void Lista::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            std::cout<<datos[i]<<std::endl;
        }
    }
}

bool Lista::vacia()const{
    return ult==-1;
}
bool Lista::llena()const{
    return ult==TAM-1;
}

bool Lista::inserta(float elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

bool Lista::elimina(int pos){
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

float Lista::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

int Lista::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
int Lista::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Lista Milista;
    Milista.inserta(0,0);
    for(int i=1; i<=40; i++){
        Milista.inserta(i*0.2, Milista.primero());
    }
    Milista.imprime();
    return 0;
}
