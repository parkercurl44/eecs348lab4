#include <stdio.h>
#include <ctype.h>

int main()
{
    double temp;
    double convertedTemp;
    double celsiusTemp;
    char originalScale;
    char targetScale;

    printf("Enter the temperature value: ");//gets temp from user 

    if (scanf("%lf", &temp) != 1)
    {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");//user selects what temp scale their input is in 
    scanf(" %c", &originalScale);

    printf("Enter the scale to convert to (C, F, or K): ");//user chooses what scale they want to convert to 
    scanf(" %c", &targetScale);

    originalScale = toupper(originalScale);
    targetScale = toupper(targetScale);

    //checks invalid scale input 
    if (originalScale != 'C' && originalScale != 'F' && originalScale != 'K')
    {
        printf("Invalid original scale.\n");
        return 1;
    }

    if (targetScale != 'C' && targetScale != 'F' && targetScale != 'K')
    {
        printf("Invalid target scale.\n");
        return 1;
    }
    //kelvin cant be below zero. negative will print invalid 

    if (originalScale == 'K' && temp < 0)
    {
        printf("Invalid temperature. Kelvin cannot be below 0.\n");
        return 1;
    }

    // Convert original temperature to Celsius first

    if (originalScale == 'C')
    {
        celsiusTemp = temp;
    }
    else if (originalScale == 'F')
    {
        celsiusTemp = (temp - 32) * 5 / 9;
    }
    else
    {
        celsiusTemp = temp - 273.15;
    }

    // Convert Celsius to the requested scale

    if (targetScale == 'C')
    {
        convertedTemp = celsiusTemp;
    }
    else if (targetScale == 'F')
    {
        convertedTemp = (celsiusTemp * 9 / 5) + 32;
    }
    else
    {
        convertedTemp = celsiusTemp + 273.15;
    }

    printf("Converted temperature: %.2f %c\n",
           convertedTemp, targetScale);

    if (celsiusTemp < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Bundle up!\n");
    }
    else if (celsiusTemp < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    }
    else if (celsiusTemp < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsiusTemp < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }

    return 0;
}