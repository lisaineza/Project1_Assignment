#include <stdio.h>

/* Returns the absolute value of a float */
float absoluteValue(float x)
{
    return (x < 0) ? -x : x;
}

/* Calculates the simplified water-quality index */
float calculateIndex(float temperature, float turbidity)
{
    float temperatureDeviation = absoluteValue(temperature - 25.0f);
    float turbidityPenalty = turbidity / 2.0f;
    return 100.0f - (temperatureDeviation + turbidityPenalty);
}

/* Classifies water quality based on the index */
const char *classifyWater(float index)
{
    if (index >= 80.0f)
        return "Good";
    else if (index >= 60.0f)
        return "Warning";
    else
        return "Critical";
}

int main(void)
{
    float temperature, turbidity, index;

    printf("Enter temperature (C): ");
    scanf("%f", &temperature);
    printf("Enter turbidity (NTU): ");
    scanf("%f", &turbidity);

    index = calculateIndex(temperature, turbidity);

    printf("\n===== WATER QUALITY MONITORING REPORT =====\n");
    printf("Temperature   : %.1f C\n", temperature);
    printf("Turbidity     : %.1f NTU\n", turbidity);
    printf("Quality Index : %.2f\n", index);
    printf("Status        : %s\n", classifyWater(index));

    return 0;
}