#include <iostream>
#define TAM 50

using namespace std;

//plantillas
class Pila
{
private:
    char datos[TAM];
    int ult;
    bool inserta(char, int);
    bool elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Pila():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    bool push(char);
    bool pop();
    char top()const;
};

char Pila::top()const
{
    char x=datos[ultimo()];
    return x;
}

bool Pila::pop()
{
    if(vacia())
    {
        return false;
    }
    else
    {
        elimina(ultimo());
    }
    return true;
}

bool Pila::push(char elem)
{
    if(llena())
    {
        return false;
    }
    else
    {
        inserta(elem, ultimo());
    }
    return true;
}

void Pila::imprime()const
{
    if(!vacia())
    {
        for(int i=0; i<=ult; i++)
        {
            char x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

bool Pila::vacia()const
{
    return ult==-1;
}
bool Pila::llena()const
{
    return ult==TAM-1;
}

bool Pila::inserta(char elem, int pos)
{
    if(llena() || pos<-1 || pos>ult)
    {
        std::cout<<"\n No se pudo insertar, PILA";
        return false;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos+1]=elem;
    ult++;
    return true;
}

bool Pila::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

char Pila::recupera(int pos)const
{
    if(vacia() || pos<0 || pos>ult-1)
    {
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else
    {
        return datos[pos];
    }
}

int Pila::primero()const
{
    if(vacia())
    {
        return -1;
    }
    return 0;
}
int Pila::ultimo()const
{
    if(vacia())
    {
        return -1;
    }
    return ult;
}

class Lista
{
private:
    char datos[TAM];
    int ult;
public:
    Lista():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    bool inserta(char, int);
    bool elimina(int);
    char recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
    int buscar(char);
};

int Lista::buscar(char elem)
{
    int i=0;
    while(i<=ult)
    {
        if(elem ==datos[i])
        {
            return i;
        }
        i++;
    }
    return -1;
}

void Lista::imprime()const
{
    if(!vacia())
    {
        for(int i=0; i<=ult; i++)
        {
            std::cout<<datos[i]<<std::endl;
        }
    }
}

bool Lista::vacia()const
{
    return ult==-1;
}
bool Lista::llena()const
{
    return ult==TAM-1;
}

bool Lista::inserta(char elem, int pos)
{
    if(llena() || pos<-1 || pos>ult)
    {
        std::cout<<"\n No se pudo insertar, LISTA";
        return false;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos+1]=elem;
    ult++;
    return true;
}

bool Lista::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

char Lista::recupera(int pos)const
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else
    {
        return datos[pos];
    }
}

int Lista::primero()const
{
    if(vacia())
    {
        return -1;
    }
    return 0;
}
int Lista::ultimo()const
{
    return ult;
}

int main()
{
    Lista infija,posfija;
    Pila pila;
    string s;
    int i=0,b;

    cout<<"Ingrese la cadena a convertir: ";
    cin>>s;
    while(i<(int)s.length())
    {
        infija.inserta(s[i],infija.ultimo());
        i++;
    }

    while(!infija.vacia())
    {
        b = 0;
        switch(infija.recupera(infija.primero()))
        {
        case '*':
        case '/':
            while(!pila.vacia() && b==0)
            {
                switch(pila.top())
                {
                case '*':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                case '/':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                default:
                    b=1;
                }
            }
            pila.push(infija.recupera(infija.primero()));
            infija.elimina(infija.primero());
            break;
        case '+':
        case '-':
            while(!pila.vacia() && b==0)
            {
                switch(pila.top())
                {
                case '*':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                case '/':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                case '+':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                case '-':
                    posfija.inserta(pila.top(),posfija.ultimo());
                    pila.pop();
                    break;
                default:
                    b=1;
                }
            }
            pila.push(infija.recupera(infija.primero()));
            infija.elimina(infija.primero());
            break;

        case '(':
            pila.push(infija.recupera(infija.primero()));
            infija.elimina(infija.primero());
            break;
        case ')':
            while(!pila.vacia() && pila.top()!='(')
            {
                posfija.inserta(pila.top(),posfija.ultimo());
                pila.pop();
            }
            pila.pop();
            infija.elimina(infija.primero());
            break;
        default:
            posfija.inserta(infija.recupera(infija.primero()),posfija.ultimo());
            infija.elimina(infija.primero());
        }
    }

    while(!pila.vacia())
    {
        posfija.inserta(pila.top(),posfija.ultimo());
        pila.pop();
    }

    posfija.imprime();
    return 0;
}


