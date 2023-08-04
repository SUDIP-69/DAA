#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool is_Prime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    for (int i = 2; i * i <= n; i++) {
        // Step count: For each value of i from 2 to sqrt(n), execute the loop body
        if (n % i == 0)
            return false;
    }
    return true;
}

void sieveOfEratosthenes(int n) {
    bool primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }

    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        // Step count: For each value of i from 2 to sqrt(n), execute the outer loop body
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                // Step count: For each value of j from i^2 to n, execute the inner loop body
                primes[j] = false;
            }
        }
    }

    printf("%d is prime: %s\n", n, primes[n] ? "true" : "false");
}

void primeno(int num,int i) {
    if (i == 1)
        printf("%d is prime: true\n", num);
    else
    {
       if (num % i == 0) 
         printf("%d is prime: false\n", num);
       else
         return primeno(num, i - 1);     
    }
}


int main() {
    int inputs[] = {5, 79, 101, 503, 827, 3761, 9377 , 83641 ,174407, 211891};
    int len = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < len; i++) {
        clock_t startTime = clock();
        bool b = is_Prime(inputs[i]);
        clock_t endTime = clock();
        double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;

        printf("%d is prime: %s\nTime taken: %.2f microseconds\n", inputs[i], b ? "true" : "false", timeTaken);
        
         startTime = clock();
        sieveOfEratosthenes(inputs[i]);
         endTime = clock();
         timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;

        printf("Time taken: %.2f microseconds\n",timeTaken);
        
         startTime = clock();
        primeno(inputs[i],(inputs[i]/2));
         endTime = clock();
         timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000000;

        printf("Time taken: %.2f microseconds\n\n\n", timeTaken);
    }

    return 0;
}