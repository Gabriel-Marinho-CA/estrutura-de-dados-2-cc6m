#include <stdio.h>
#define MAX 10
#define SUBZERO -273.15
#define SOLARTEMP 5498.85

void PrintResult(double arrPrint[], double arr[], int qt);

int TempQuantity() 
{
    char qt[100];
    int tempQuantity = 0;

    do 
    {
        printf("Quantas temperaturas em °C você quer converter?\t");
        fgets(qt, sizeof(qt), stdin);

        if (qt[0] == '\n') 
        {
            continue;
        }

        sscanf(qt, "%d", &tempQuantity);
    } 

    while (tempQuantity <= 0 || tempQuantity > MAX);

    return tempQuantity;
}

double TestInput(int number) 
{
    double grau;
    char str[100];

    do 
    {
        printf("Informe a %iª temperatura em °C:\t", number);
        fgets(str, sizeof(str), stdin);

        if (str[0] == '\n')
        {
            continue;
        }
        double conversions = sscanf(str, "%lf", &grau);

        if (!(conversions != 1 || grau < SUBZERO || grau > SOLARTEMP))
        {
            break;
        }

    } 
    while (1);

    return grau;
}

double TempInputs(int qt, double arr[]) 
{
    double grau = 0;

    for (int i = 0; i < qt; i++) 
    {
        arr[i] = TestInput(i + 1);
    }
    return *arr;
}

double FahrenheitCalc(double grau)
{ 
    return grau * 1.8 + 32; 
}

void Converter(int qt, double arr[]) 
{
    double arrPrint[qt];

    for (int i = 0; i < qt; i++) 
    {
        arrPrint[i] = FahrenheitCalc(arr[i]);
    }
    PrintResult(arrPrint, arr, qt);
}

void PrintResult(double arrPrint[], double arr[], int qt)
{
    printf("A tabela de conversão entre °C e °F é:\n");
    printf("------------------\n");
    printf("   °C         °F\n");
    printf("------------------\n");

    for (int i = 0; i < qt; i++) 
    {
        printf("%7.2lf    %7.2lf\n", arr[i], arrPrint[i]);
    }
    printf("------------------\n");
}

int main() 
{
    int qt = TempQuantity();
    double arr[qt];
    TempInputs(qt, arr);
    Converter(qt, arr);

    return 0;
}