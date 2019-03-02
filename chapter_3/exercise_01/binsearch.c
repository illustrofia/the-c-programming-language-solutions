// Binsearch versions comparison

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int second_binsearch(int x, int v[], int n);

void binsearch_test(int binsearch(int x, int v[], int n), int x, int v[], int n);

int main(void)
{
    int x = 3;
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    binsearch_test(binsearch, x, v, 10);

    binsearch_test(second_binsearch, x, v, 10);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int second_binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (x == v[low - 1])
    {
        return low - 1;
    }

    return -1;
}

void binsearch_test(int binsearch(int x, int v[], int n), int x, int v[], int n)
{
    clock_t time;

    time = clock();
    binsearch(x, v, n);
    time = clock() - time;

    printf("It took binsearch %.6f seconds to find x.\n", ((double)time)/CLOCKS_PER_SEC);
}