/*
 Construir un programa que calcule e imprima en pantalla el resultado
 de la siguiente expresión, donde los componentes de los vectores 
 A, B y C se introducen por teclado:
 D = A^(B^C) (^: producto vectorial)
*/

/*
int x = 10;
int *dir = &x;

float parametro = 3;
salida = funcion(3)
float funcion(parametro)
return salida

void funcion(*dir) // cuando la declaro
funcion(&x); // cuando la uso

en los parametros pongo como puntero las variables que necesito devolver
y en lugar de poner el tipo de dato a devolver, pongo void.


*/

// LIBRERIAS
#include <stdio.h>

// DECLARACION DE FUNCIONES - PROTOTIPOS
void leerDatos(float *ax, float *ay, float *az,
               float *bx, float *by, float *bz,
               float *cx, float *cy, float *cz);
void leerVector(float *vx, float *vy, float *vz);
void calcularExpresion(float ax, float ay, float az,
                       float bx, float by, float bz,
                       float cx, float cy, float cz,
                       float *dx, float *dy, float *dz);
void productoVectorial(float ax, float ay, float az,
                       float bx, float by, float bz,
                       float *cx, float *cy, float *cz);
void mostrarResultado(float vx, float vy, float vz);

int main(){
    float ax,ay,az;
    float bx,by,bz;
    float cx,cy,cz;
    float dx,dy,dz;
    printf("CALCULADORA D=A^(B^C)\n");
    leerDatos(&ax,&ay,&az,&bx,&by,&bz,&cx,&cy,&cz);
    calcularExpresion(ax,ay,az,bx,by,bz,cx,cy,cz,&dx,&dy,&dz);
    mostrarResultado(dx,dy,dz);
    return 0;
}

void leerDatos(float *ax, float *ay, float *az,
               float *bx, float *by, float *bz,
               float *cx, float *cy, float *cz)
{
    printf("Introduzca las coordenadas del vector A:");
    leerVector(ax,ay,az);
    printf("Introduzca las coordenadas del vector B:");
    leerVector(bx,by,bz);
    printf("Introduzca las coordenadas del vector C:");
    leerVector(cx,cy,cz);
}

void leerVector(float *vx, float *vy, float *vz)
{
    printf("x: ");
    scanf("%f",vx); //vx es equivalente a un &vx de antes. ya es la direciion de vx variable. ya es un puntero
    printf("y: ");
    scanf("%f",vy);
    printf("z: ");
    scanf("%f",vz);
}

void calcularExpresion(float ax, float ay, float az,
                       float bx, float by, float bz,
                       float cx, float cy, float cz,
                       float *dx, float *dy, float *dz)
{
}

void productoVectorial(float ax, float ay, float az,
                       float bx, float by, float bz,
                       float *cx, float *cy, float *cz)
{
}

void mostrarResultado(float vx, float vy, float vz)
{
}
