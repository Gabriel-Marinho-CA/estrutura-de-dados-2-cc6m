#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define TAM 3
#define TAMFUNC 6

struct ReturnCalcValues 
{
    bool concavit;
    double yPoint;
    double vert1;
    double vert2;
    double sqrx1;
    double sqrx2;
    bool root;
};

typedef struct ReturnCalcValues returnCalcValues;

double TestInput(double value, char letter);
void PrintRes(returnCalcValues values);

double GetCoef(double arrValues[]) 
{
    char letters[TAM] = {'a', 'b', 'c'};

    double a, b, c;

    for (int i = 0; i < TAM; i++) 
    {
        arrValues[i] = TestInput(i + 1, letters[i]);
    }

    return *arrValues;
}

double TestInput(double value, char letter) 
{
    double valueTest = value;
    int charComparsion;
    char a[] = "a";
    char str[100];

    sprintf(str, "%f", value);

    do 
    {
        printf("Informe o coeficiente \"%c\": ", letter);
        fgets(str, sizeof(str), stdin);

        if (str[0] == '\n')
        {
            continue;
        }
  
        double conversor = sscanf(str, "%lf", &valueTest);

        if (!(conversor != 1) && !(letter == 'a' && valueTest == 0.0))
        {
            break;
        }
    
    } 
    while (1);

    return valueTest;
}

// Função que calcula os elementos pedidos
void CalcFunc(double arrValues[]) 
{
    returnCalcValues values;
    double delta;
    delta = arrValues[1] * arrValues[1] - 4 * arrValues[0] * arrValues[2];

    if (arrValues[0] > 0) 
    {
        values.concavit = true;
    } 
    else 
    {
        values.concavit = false;
    }
    values.yPoint = arrValues[2];
    values.vert1 = ((-arrValues[1]) / (2 * arrValues[0]));
    values.vert2 = arrValues[0] * pow(values.vert1, 2) + arrValues[1] * values.vert1 + arrValues[2];
                 
    if (!(delta < 0))
    {
        values.root = true;
          
        if (delta == 0) 
        {
            values.sqrx1 = (-arrValues[1] + sqrt(delta)) / (2 * arrValues[0]);
            values.sqrx2 = values.sqrx1;
        } 
        else
        {
            values.sqrx1 = (-arrValues[1] + sqrt(delta)) / (2 * arrValues[0]);
            values.sqrx2 = (-arrValues[1] - sqrt(delta)) / (2 * arrValues[0]);
        }
    } 
    else 
    {
        values.root = false;
    }

    PrintRes(values);
}

void PrintRes(returnCalcValues values) 
{
    if (values.concavit) 
    {
        printf("A parábola tem concavidade para cima.\n");
    } 

    else 
    {
        printf("A parábola tem concavidade para baixo.\n");
    }

    printf("A parábola cruza o eixo y no ponto: %.2lf.\n", values.yPoint + 0.00);
  
    if(values.concavit)
    {
        printf("As coordenadas do vértice (ponto mínimo) são: (%.2lf, %.2lf).\n", values.vert1 + 0.00, values.vert2 + 0.00);
    }

    else 
    {
        printf("As coordenadas do vértice (ponto máximo) são: (%.2lf, %.2lf).\n", values.vert1 + 0.00, values.vert2 + 0.00);
    }
    

    if (values.root == false) 
    {
        printf("A função não tem raízes reais.\n");
    } 
    else 
    {
        if (values.sqrx1 == values.sqrx2) 
        {
            printf("A função tem uma raiz real: %.2lf.\n", values.sqrx1 + 0.00);
        } 
        else 
        {
            printf("A função tem duas raízes reais:\n");
            printf("    x1 = %.2lf\n", values.sqrx1 + 0.00);
            printf("    x2 = %.2lf\n", values.sqrx2 + 0.00);
        }
    }
}

int main(void) 
{
    double arrValues[TAM];

    printf("--------------------------------------------------");
    printf("\nSolucionador de funções quadráticas: ax^2 + bx + c\n");
    printf("--------------------------------------------------\n");

    GetCoef(arrValues);

    printf("\n--------------------------------------------------");
    printf("\nSolução da função: (%.2lf)x^2 + (%.2lf)x + (%.2lf)\n", arrValues[0], arrValues[1], arrValues[2]);
    printf("--------------------------------------------------\n");

    CalcFunc(arrValues);

    return 0;
}