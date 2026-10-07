#include <stdio.h>

#define MAX_ROUTES 100

int totalDistance(const int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

/* Reuses totalDistance() as part of another calculation */
double averageDistance(const int arr[], int n)
{
    return (double)totalDistance(arr, n) / n;
}

int longestRoute(const int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int countAboveLimit(const int arr[], int n, int limit)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > limit)
            count++;
    return count;
}

/* Recursive sum: sum of first n elements */
int recursiveSum(const int arr[], int n)
{
    if (n == 0)                              /* base case */
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int main(void)
{
    int distances[MAX_ROUTES];
    int n, limit;

    printf("Enter number of routes (1-%d): ", MAX_ROUTES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_ROUTES)
    {
        printf("Invalid number of routes.\n");
        return 1;
    }

    printf("Enter %d distances (km): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &distances[i]);

    printf("Enter distance limit (km): ");
    scanf("%d", &limit);

    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", totalDistance(distances, n));
    printf("Average distance: %.2f km\n", averageDistance(distances, n));
    printf("Longest route: %d km\n", longestRoute(distances, n));
    printf("Routes above %d km: %d\n", limit, countAboveLimit(distances, n, limit));
    printf("Routes above %d km: %d\n", limit + 10, countAboveLimit(distances, n, limit + 10));
    printf("\nRecursive sum: %d km\n", recursiveSum(distances, n));

    return 0;
}