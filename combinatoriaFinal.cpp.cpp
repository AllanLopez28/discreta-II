#include <iostream>
#include <math.h>
using namespace std;

void factSR(int n1, int r1);
void factCR(int n2, int r2);

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
            cout << "-"
                 << " ";
            cout << datos[index[j]];
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

        cout << "\n\t";
        for (int w = 0; w < r; w++)
        {
            cout << datos[index[w]];
            cout << "-";
            // cout << " ";
        }
    }
}
void factSR(int n1, int r1)
{
    int resp1 = 1;
    for (int x = 1; x <= n1; x++)
    {
        resp1 = resp1 * x;
    }

    int resp2 = 1;
    for (int x = 1; x <= r1; x++)
    {
        resp2 = resp2 * x;
    }

    int rest = n1 - r1;

    int respm = 1;
    for (int x = 1; x <= rest; x++)
    {
        respm = respm * x;
    }

    int fact = resp1 / (resp2 * (respm));
    cout << "\nnumero de combinaciones SIN rep:" << fact << endl;
}

void factCR(int n2, int r2)
{

    int valor1 = n2 + r2 - 1;
    int valor2 = n2 - 1;
    int factorial1 = 1;
    int factorial2 = 1;
    int factorial3 = 1;
    int resultadoCR = 0;

    for (int i = 1; i <= valor1; i++)
    {
        factorial1 = factorial1 * i;
    }

    for (int j = 1; j <= valor2; j++)
    {
        factorial2 = factorial2 * j;
    }

    for (int k = 1; k <= r2; k++)
    {
        factorial3 = factorial3 * k;
    }

    resultadoCR = factorial1 / (factorial2 * factorial3);

    cout << "\nnumero de combinaciones CON rep:" << resultadoCR << endl;
}

int main()
{
    int op;
    do
    {
        string items[] = {"Petra", "La Muralla China", "Chichen Itza", "Cristo Redentor", "Coliseo Romano", "Machu Picchu", "Palacio Taj Mahal. "};
        int n, r;
        int w;

        cout << "\n ------------------- BIENVENIDO!! -------------------- \n";
        cout << "\n Existen 7 Maravillas del mundo moderno: Petra, La Muralla China, Chichen Itza, Cristo Redentor, Coliseo Romano, Machu Picchu y el Palacio Taj Mahal \n";

        do
        {
            cout << "\n  Ingrese el numero de lugares que desea visitar:  \n";
            cout << "\n N: ";
            cin >> n;
        } while (n > 7);
        do
        {
            cout << "\n Ingrese cuantos lugares desea visitar en una temporada: \n";
            cout << "\n R: ";
            cin >> r;
        } while (r > n);

        cout << endl;

        cout << "Combinacion con repeticion: ";
        combinacionCR(items, n, r);
        cout << endl;
        factCR(n, r);

        cout << "\n.............................................\n";

        cout << "\nCombinacion sin repeticion: ";
        combinacionSR(items, n, r);
        cout << endl;
        factSR(n, r);

        cout<<"desea hacer otra combinacion 1=si, 2=salir"<<endl;
        cin>>op;
        //system("pause");
    }while (op!=2); 
}

