#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//Euclidean
int egcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return egcd(b, a % b);
}

//Naive
int ngcd(int a, int b) {
    int min = (a < b) ? a : b;
    int i, gcd;
    for (i = 1; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

//Middle School Procedure using Common Prime Factors
int gcd(int a, int b) {
    // Find the minimum of a and b
    int min = (a < b) ? a : b;

    // Find the common prime factors
    int factor, result = 1;
    for (factor = 2; factor <= min; factor++) {
        while (a % factor == 0 && b % factor == 0) {
            result *= factor;
            a /= factor;
            b /= factor;
        }
    }

    return result;
}


int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    clock_t startTime = clock();
    int result1 = egcd(num1, num2);
    printf("GCD: %d\n", result1);
    clock_t endTime = clock();
    double timeTaken1 = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;
    
     startTime = clock();
    int result2 = ngcd(num1, num2);
    printf("GCD: %d\n", result2);
     endTime = clock();
    double timeTaken2 = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;
    
     startTime = clock();
    int result3 = gcd(num1, num2);
    printf("GCD: %d\n", result3);
     endTime = clock();
    double timeTaken3 = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;

        printf("Time taken in Euclidean: %.2f microseconds\n", timeTaken1);
        printf("Time taken in Naïve: %.2f microseconds\n", timeTaken2);
        printf("Time taken in Common Prime Factors: %.2f microseconds\n", timeTaken3);

    return 0;
}









