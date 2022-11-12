#include <iostream>
//#include<stdlib.h>
#include <math.h>
using namespace std;

void factSR(int n1, int r1);
void factCR(int n2, int r2);


void almacenando(string *items, string **almacen, int r, int *indexs, int *indice)
{
    for (int k = 0; k < r; k++)
    {
        almacen[*indice][k] = items[indexs[k]];
    }
    *indice = *indice + 1;
}

void initParams(int r, int **indexs, int **cont)
{
    int tmp = 0;
    *cont = &tmp;
    *indexs = new int[r];
}

void combinacionCR(string datos[], int n, int r, int y = 0, int *index = NULL, int i = 0)
{
    if (index == NULL)
    {
        index = new int[r];
    }
    if (i < r)
    {
        for (int x = y; x < n; x++)
        {
            index[i] = x;
            combinacionCR(datos, n, r, x, index, i + 1);
        }
    }

    else
    {
        cout << "\n\t";
        for (int j = 0; j < r; j++)
        {
            cout << datos[index[j]];
            cout << " ";
        }
    }
}

void combinacionSR(string datos[], int n, int r, int y = 0, int i = 0, int *index = NULL)
{
    if (index == NULL)
    {
        index = new int[r];
    }
    if (i < r)
    {
        for (int x = y; x < n; x++)
        {
            index[i] = x;
            combinacionSR(datos, n, r, x + 1, i + 1, index);
        }
    }
    else
    {
        // imprimir la lista
        cout << "\n\t";
        for (int w = 0; w < r; w++)
        {
            cout << datos[index[w]];
            cout << " ";
        }
    }
}
void factSR(int n1, int r1)
{
    int resp1 = 1;
    for (int x = 1; x <= n1; x++)
    {
        resp1 = resp1 * x; // factorial de n
    }

    int resp2 = 1;
    for (int x = 1; x <= r1; x++)
    {
        resp2 = resp2 * x; // factorial de r
    }

    int rest = n1 - r1;

    int respm = 1;
    for (int x = 1; x <= rest; x++)
    {
        respm = respm * x; // factorial de la resta
    }

    /*cout<<resp1<<endl;
    cout<<resp2<<endl;
    cout<<respm<<endl;*/

    int fact = resp1 / (resp2 * (respm));
    cout << "\nnumero de combinaciones SIN rep:" << fact << endl;
}

void factCR(int n2, int r2)
{

    int nume = n2 + (r2 - 1);
    int denom = n2 - 1;
    int respr2 = 1;

    for (int x = 1; x <= r2; x++)
    {
        respr2 = respr2 * x; // factorial de r
    }

    int respnum = 1;
    for (int x = 1; x <= nume; x++)
    {
        respnum = respnum * x; // factorial del numerador
    }

    int respden =1;
    for (int x = 1; x < denom; x++)
    {
        respden =respden*x; //factorial del denominador
    }

    int fact= respnum/r2*(respden);
    cout << "\nnumero de combinaciones CON rep:" << fact << endl;
    
}

int main()
{
    string items[] = {"Rojo", "Amarillo", "Verde", "Celeste", "Magenta", "Negro", "Blanco", "Morado", "Azul"};
    int n, r;
    int w;

    cout << "\n N:"; // Se debe seleccionar siempre 10, porque en una combinacion se eligen todos los elementos
    cin >> n;
    cout << "\n R:";
    cin >> r;

    cout << endl;

    cout << "Combinacion con repeticion: ";
    combinacionCR(items, n, r);
    cout<<endl;
    factCR(n,r);

    cout << "\n.............................................\n";

    cout << "\nCombinacion sin repeticion: ";
    combinacionSR(items, n, r);
    cout << endl;
    factSR(n, r);

    system("pause");
    // getch();
}
