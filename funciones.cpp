#include <iostream>
#include <cmath>
using namespace std;


void derivar(int polinomio[],int derivada[], int grado){
    for(int i=0;i<=grado;i++){
        derivada[i]=polinomio[i+1]*(i+1);
    }
}
float evaluar_derivada(int polinomio[], float x,int grado){
    int* p;
    float resultado=0;
    p=&polinomio[0];
    p++;
    for(int i=1; i<=grado; i++)
    {
        resultado+=(*p)*(i)*pow(x,i-1);
        p++;//El puntero se incrementa para apuntar al siguiente entero
    }
    return resultado;
}

float evaluar_funcion(int polinomio[], float x,int grado){
    int* p;
    float resultado=0;
    p=&polinomio[0];
    for(int i=0; i<=grado; i++)
    {
        resultado+=(*p)*pow(x,i);
        p++;//El puntero se incrementa para apuntar al siguiente entero
    }
    return resultado;
}
void newton_raphson(int polinomio[],int grado){
    int cant;
    float valor_inicial,funcion,derivada;
    cout<<"Ingrese cantidad de iteraciones : ";
    cin>>cant;
    float iteracion[cant];
    cout<<"Ingrese valor inicial : ";
    cin>>valor_inicial;
    for(int i=1;i<=cant;i++){
        derivada = evaluar_derivada(polinomio,valor_inicial,grado);
        funcion = evaluar_funcion(polinomio,valor_inicial,grado);
        iteracion[i]=(valor_inicial - (funcion/derivada)) ;
        cout<<"Itereacion "<<i<<" : "<<iteracion[i]<<endl;
        valor_inicial=iteracion[i];
    }

}
void newton_raphson_modificado(int polinomio[], int derivada[],int grado){
    int cant, grado2;
    grado2=(grado-1);
    cout<<grado2;
    float valor_inicial,funcion,primera_derivada,segunda_derivada;
    cout<<"Ingrese cantidad de iteraciones : ";
    cin>>cant;
    float iteracio[cant];
    cout<<"Ingrese valor inicial : ";
    cin>>valor_inicial;
    for(int i=1;i<=cant;i++){
        primera_derivada = evaluar_derivada(polinomio,valor_inicial,grado);
        segunda_derivada = evaluar_derivada(derivada,valor_inicial,grado2);
        funcion = evaluar_funcion(polinomio,valor_inicial,grado);
        iteracio[i]=( valor_inicial - (funcion*primera_derivada)/( pow(primera_derivada,2) - (funcion)*(segunda_derivada))) ;
        cout<<"Itereacion "<<i<<" : "<<iteracio[i]<<endl;
        valor_inicial=iteracio[i];
    }


}

