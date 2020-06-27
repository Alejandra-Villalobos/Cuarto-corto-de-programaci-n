#include "iostream"
using namespace std;
float Media(float [], float *);
int Comparar(float [], float);

int main()
{
    float Estaturas[25], Prom;
    int j=1;
    cout << "\t"<<"Ingrese las edades de los 25 alumnos en metros" << endl;
    for (int i=0; i<25; i++)
    {
        cout << "Alumno "<<j<<" : ";
        cin >> Estaturas[i];
        j++;
    }
    Media(Estaturas, &Prom); //Llamado a la función de la media
    cout << "El promedio es: " << Prom << " m" << endl;
    Comparar(Estaturas, Prom); //Llamado a la función de comparación
}

float Media(float Estaturas[], float *Prom) //Calcula la media de la estatura de 25 personas
{
    float Acum=0;
    for (int i=0; i<25; i++)
        Acum+=Estaturas[i]; //Suma de las estaturas
    *Prom = Acum/25; //Media
}
int Comparar (float Estaturas[], float Prom) //Indica la cantidad de personas que están arriba, abajo y justo en la media
{
    Media(Estaturas, &Prom);
    int Acum1=0, Acum2=0;
    for (int i=0; i<25; i++)
    {
        if (Estaturas[i]>Prom) //Si están arriba del promedio
            Acum1+=1;
        else if (Estaturas[i]<Prom) //Si están abajo del promedio
            Acum2+=1;
    }
    cout << "Alumnos con estaturas arriba de la media: " << Acum1 << endl;
    cout << "Alumnos con estaturas abajo de la media: " << Acum2 << endl;
    cout << "Alumnos con estaturas igual a la media: " << 25-(Acum1+Acum2) << endl; //Las restantes se encuentran en la media
}