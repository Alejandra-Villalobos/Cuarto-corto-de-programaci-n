#include "iostream"
using namespace std;
float Registro(int);
float N_Final(int, float [][5]);

int main()
{
    int n;

    cout<< "Ingrese la cantidad de alumnos: ";
    cin >> n;
    cout << endl;

    float Notas[n][5]; //"n" indica el numero de alumnos (filas), el "5" representa las 5 notas (columnas)

    Registro(n);   
}

float Registro(int n) //Función para ingresar las notas de cada estudiante
{
    float Notas[n][5];
    for (int i=0; i<n; i++) //Recorre las filas
    {
        cout << endl;
        for (int j=0; j<5; j++) //Recorre las columnas
        {
            cout << "Ingrese la nota " << j+1 << " del estudiante " << i+1 << ": ";
            cin >> Notas [i][j];
            if ((Notas [i][j]<0) || (Notas [i][j]>10)) //En caso de que el valor esté fuera del rango
            {
                cout <<"Valor invalido. Vuelva a ingresarlo. " << endl;
                j-=1; //Repite la casilla hasta que el valor sea ingresado correctamente
            }
        }
        
    }
    N_Final(n,Notas); //Llama a la función que calcula la nota final y si abrobó o reprobó
}
float N_Final(int n, float Notas [][5])
{
    float N_Final[n]; //Cadena unidimensional para juntar los datos de la tabla ya procesados (nota final y número de estudiante)
    for (int i=0; i<n; i++) //Recorre las filas
    {
        float Acum=0; //Acumula cada nota, al cambiar de fila vuelve a 0* 
        for (int j=0; j<5; j++) //Recorre las columnas
        {
            Acum += ((Notas [i][j]*0.2)); //Calcula el porcentaje de cada nota y los suma
            N_Final[i]=Acum;//Transfiere la nota final a la cadena unidimensional
        }
        if (N_Final[i]>=6) //Se necesita mínimo 6 de nota final para aprobar
            cout << endl << "Alumno " << i+1 << ": " << "Nota final: " << N_Final[i] << " Aprobado." << endl;
        else
            cout << endl << "Alumno " << i+1 << ": " << "Nota final: " << N_Final[i] << " Reprobado." << endl;
    }   
}
//(Intentar acumular la suma de las notas en la cadena unidimensional (sin el "Acum") da problemas al trabajar con más de 2 estudiantes (n))
