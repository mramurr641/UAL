/*
 ENUNCIADO
*/

// LIBRERIAS
#include<stdio.h>
#include<math.h>

// MACROS - CONSTANTES
#define LA 100.0 // Longitud eslabon A [cm]
#define LB 75.0  // Longitud eslabon B [cm]
#define r sqrt(LA*LA+LB*LB-sqrt(3)*LA*LB) // Limite inferior de posicion
#define limB 150 // Limite de giro del eslabon B [grados]

//VARIABLES GLOBALES

//DECLARACION DE FUNCIONES
void solicitar_datos(float *x, float *y);
void cartesianas_a_polares(float x, float y, float *d, float *theta);
void calcular_d(float x, float y, float *d);
void calcular_theta(float x, float y, float *d, float *theta);
float cuadrante(float y, float fi);
float rad_a_grados(float fi);
void calcular_angulos(float d, float theta, float *alpha, float *beta);
void calcular_alpha(float d,float theta,float *alpha);
void calcular_beta(float d,float *beta );
int comprobar_datos(float d,float beta,int flag);
void calcular_Deltas(int flag, float alpha0, float beta0, float alpha, float beta, float *Delta_alpha, float *Delta_beta);
void mostrar_datos(int flag, float alpha0, float beta0, float alpha, float beta, float Delta_alpha, float Delta_beta);
void registrar_datos(int flag, float *alpha0, float *beta0, float alpha, float beta);


//MAIN
int main(){
    // Declaracion de variables
    float x,y,d,theta,alpha,beta,alpha0=0,beta0=0,Delta_alpha,Delta_beta;
    int flag;
    do{
        // Solicitud de datos
        solicitar_datos(&x,&y);
        // Procesamiento
        cartesianas_a_polares(x,y,&d,&theta);
        calcular_angulos(d,theta,&alpha,&beta);
        flag=comprobar_datos(d,beta,flag);
        calcular_Deltas(flag,alpha0,beta0,alpha,beta,&Delta_alpha,&Delta_beta);
        // Formateo por pantalla
        mostrar_datos(flag,alpha0,beta0,alpha,beta,Delta_alpha,Delta_beta);
        // Registro
        registrar_datos(flag,&alpha0,&beta0,alpha,beta);
    }while(x!=0||y!=0);
    /*
    printf("x=%f\n",x);
    printf("y=%f\n",y);
    printf("d=%f\n",d);
    printf("theta=%f\n",theta);
    printf("alpha=%f\n",alpha);
    printf("beta=%f\n",beta);
    printf("flag=%i\n",flag);
    */
    return 0;
}

//DEFINICION DE FUNCIONES
void solicitar_datos(float *x, float *y)
{
    printf("Introduzca la coordenada x: ");
    scanf("%f",x);
    printf("Introduzca la coordenada y: ");
    scanf("%f",y);
    // FALTA ANADIR QUE SI SE INTRODUCE 0,0, ALPHA ES 0 AUTOMATICAMENTE Y BETA ES 0 AUTOMATICAMENTE
}

void cartesianas_a_polares(float x, float y, float *d, float *theta)
{
    calcular_d(x,y,d);
    calcular_theta(x,y,d,theta);
}

void calcular_d(float x, float y, float *d)
{
    *d=sqrt(x*x+y*y);
}

void calcular_theta(float x, float y, float *d, float *theta)
{
    *theta=acos(x/(*d)); // [0,PI] rad
    *theta=cuadrante(y,*theta); // [0,2*PI] rad
    *theta=rad_a_grados(*theta); // [0,360] grados
}

float cuadrante(float y, float fi)
{
    if(y<0)                    // Punto en el 3er o 4o cuadrante o semieje -Y
        return fi=2*M_PI-fi;
    else                       // Punto en el 1er o 2o cuadrante o semiejes +X,-X,+Y
        return fi;
}

float rad_a_grados(float fi)
{
    return fi*180/M_PI;
}

void calcular_angulos(float d, float theta, float *alpha, float *beta)
{
    calcular_alpha(d,theta,alpha);
    calcular_beta(d,beta);
}

void calcular_alpha(float d,float theta,float *alpha)
{
    float alpha1;
    alpha1 = acos((LA*LA+d*d-LB*LB)/(2*d*LA));
    alpha1 = rad_a_grados(alpha1);
    *alpha=theta-alpha1;
    // HACER UNA FUNCION QUE PASE ESTE ANGULO DE ANGULOS NEGATIVOS, A REFERENCIAS DE 0
    // CUANDO EL VALOR ES NO VÁLIDO POR LA CONDICIÓN DE r, parece no poder calcularse su valor. Sale -1.#IND00
}
void calcular_beta(float d,float *beta )
{   
    float aux;
    aux=acos((LA*LA+LB*LB-d*d)/(2*LA*LB));
    *beta=180-rad_a_grados(aux);
        // CUANDO EL VALOR ES NO VÁLIDO POR LA CONDICIÓN DE r, parece no poder calcularse su valor. Sale -1.#IND00
}

int comprobar_datos(float d, float beta, int flag)
{
    if((d>=r&&d<=LA+LB)&&(beta>=0&&beta<=150))
        return flag=1;
    else
        return flag=0;
}

void calcular_Deltas(int flag, float alpha0, float beta0, float alpha, float beta, float *Delta_alpha, float *Delta_beta)
{
    if(flag)
    {
        *Delta_alpha=alpha-alpha0;
        *Delta_beta=beta-beta0;
    }

}

void mostrar_datos(int flag, float alpha0, float beta0, float alpha, float beta, float Delta_alpha, float Delta_beta)
{
    if(flag)
    {
        printf("Desplazamiento angular final:\n");
        printf("Delta alpha=%f[grados]\n",Delta_alpha);
        printf("Delta beta=%f[grados]\n",Delta_beta);
        printf("Posicion angular final:\n");
        printf("alpha_f= %f\n",alpha);
        printf("beta_f= %f\n",beta);
    }
    else
    {
        printf("Posicion inalcanzable.\n");
        printf("alpha_f= %f\n",alpha0);
        printf("beta_f= %f\n",beta0);
    }
}

void registrar_datos(int flag, float *alpha0, float *beta0, float alpha, float beta)
{   if(flag)
    {
        *alpha0=alpha;
        *beta0=beta;
    }
}