
#include <stdio.h>
#define SUBZERO -273.15
#define SOLARTEMP 5498.85

double Converter(double grau) 
{ 
    return grau * 1.8 + 32; 
}

double TestInput() {
    double grau;
    char str[100];

    do 
    {
        printf("Informe a temperatura em °C: ");
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

int main(void) 
{
    double grau = TestInput();

    double fahrenheit = Converter(grau);

    printf("A temperatura de %.2lf°C é igual à %.2lf°F.\n", grau, fahrenheit);

    return 0;
}