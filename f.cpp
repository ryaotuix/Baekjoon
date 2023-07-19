#include <iostream>
#include <ctype.h>

using namespace std;
const unsigned short int MAX_VAL = 10;

int LongitudCadena(char*);

int BuscarCaracter(char *cadena, char caracter);

void Ordenar(int *vector, int nElementos, bool ascendente);

int main()
{
    char *cadena = "asdasd";

    cout << LongitudCadena(cadena) << endl;

    cout << BuscarCaracter(cadena, 'a') << endl;

    int iArray[] = {5,4,3,2,1};

    Ordenar(iArray, 5, 1);

    cout << iArray << endl;

    return 0;
}

int LongitudCadena(char *cadena)
{
    char *c = cadena;
    for(int i = 0; i < MAX_VAL; i++)
    {
        if (c[i] == 0) break;
        cadena++;
    }

    return  cadena - c;
}

int BuscarCaracter(char * cadena, char caracter)
{
    char *pCadena = cadena;
    for (int i = 0; i < MAX_VAL; i++)
    {
        pCadena++;
        if (toupper(cadena[i]) == toupper(caracter))
        return pCadena- cadena;
    }

    return -1;
}

void Ordenar(int *vector, int nElementos, bool ascendente)
{


    int *pComienzo = vector, *pFinal = vector[nElementos-1];

    if (ascendente)
    {
        for (int i = 0; i < nElementos; i++)
        {
            for (; pComienzo < pFinal; pComienzo++, pFinal--)
            {
                if (*pComienzo > *pFinal)
                {
                    *pComienzo += *pFinal;
                    *pFinal -= *pComienzo;
                    *pComienzo -= *pFinal;
                }
            }
        }
    }
}