#include "iostream"
#include "string"
using namespace std;
string Cadena(int *, char []);

int main()
{
    int n=150;
    char frase[n];
    cout << endl<< "Ingrese la frase sin mayusculas ni tildes (150 caracteres max)"<< endl;
    cout << "Introducza los espacios con un punto (.) "<< endl;
    cout << "Cuando haya terminado su frase presione Enter, Ctrl-z y Enter otra vez"<< endl << endl;

    int i;
    do
    {
        for (i=0; i<n; i++)//No conocemos la cantidad de valores que tendrá la cadena, por lo que establecemos un máximo de 150
        {
            cin >> frase [i];
        }
    }
    while (cin>>frase[i]); //Utilizamos Ctrl-z para indicar que hemos terminado de digitar la frase
    Cadena(&n, frase); //Llamado a la fución
}
string Cadena (int *n, char frase[]) //Convertimos las letras a su respectivo número en clave murciélago
{
    char murcielagoL[10] = {'m','u','r','c','i','e','l','a','g','o'}; //Cadena de la clave en letras
    char murcielagoN[10] = {'0','1','2','3','4','5','6','7','8','9'}; //Cadena de la clave en numeros
    for (int i=0; i<*n;i++) //Recorre la cadena ingresada
    {
        for (int j=0; j<10; j++) //Para recorrer las cadenas con la clave
        {
            if (frase[i]==murcielagoL[j])
                frase[i]=murcielagoN[j]; /*Si una letra de la cadena ingresada es igual a alguna de la cadena que
                contiene la clave en letras, es sustituida por su respectivo número*/
            else if (frase[i]=='.' || frase[i]=='@') 
                frase[i]=' '; /*Si un caracter de la cadena ingresada es un punto o un @ (que es lo que se imprime al pulsar Ctrl-z) 
            es sustituido por un espacio. Utilizamos punto para los espacios porque otros caracteres como guiones dan problemas*/
        }
    }
    cout << endl << "En clave murcielago: "<< frase;
}
