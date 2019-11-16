#include <stdio.h>
#include <stdlib.h>

struct user {
    char *username;
    int bday;
};

void array_nth(int a[], int x)
{
    int *p = &a[x];

    printf("%d\n", *p);

    printf("-4 5 kozotti szam: ");
    scanf("%d", &x);

    printf("%d\n", *p+x);
}

void bubble_sort (struct user *data, int n)
{
    struct user tmp[1];

    printf("Rendezes elott:\n");
    for (int i=0; i<n; i++)
        printf("%10s %4d\n",data[i].username, data[i].bday);

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1; j++)
            if (data[j].bday>data[j+1].bday)
            {
                tmp[0]=data[j];
                data[j]=data[j+1];
                data[j+1]=tmp[0];
            }

    printf("Rendezes utan:\n");
    for (int i=0; i<n; i++)
        printf("%10s %4d\n",data[i].username, data[i].bday);
}

void sort (struct user *data, int n)
{

}

struct user *find_adults(struct user *data, int n)
{
    int i=0;
    int year = 2019;
    static struct user d[6];

    while ( (i<n) && (year - data[i].bday >= 18))
        d[i++] = data[i];

    return d;
}

int *mergeSort(int *a, int n1, int *b, int n2)
{
    static int *array; // static variable lenght array?!
    array = malloc((n1+n2) * sizeof(int));

    int i=0;
    int j=0;
    int k=0;

    while ((i<n1) && (j<n2))
    {
        if (a[i]<b[j])
        {
            array[k]=a[i];
            i++;
        }
        else
        {
            array[k]=b[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        array[k]=a[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        array[k]=b[j];
        j++;
        k++;
    }

    return array;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void printArray(int *a, int n)
{
    for (int i=0; i<n; i++)
         printf("%d ", a[i]);
    printf("\n\n");
}

int main()
{
    // 1. Készíts egy 10 elemű, egész számokat tartalmazó tömböt értékekkel! Állíts be egy pointer a tömb ötödik elemére!
    // Kérj be egy -4, +5 közötti számot, ami kiírja a tömb megfelelő sorszámú elemét a pointerhez képest!
    //int array[] = {0,1,2,3,4,5,6,7,8,9};
    //array_nth(array,sizeof(array)/sizeof(array[0]));

    // 2. Készíts struktúrát, ami egy felhasználó nevét és születési évét tárolja! Készíts egy 5 elemű tömböt belőle!
    struct user user[6] = {
        {"Gabor",1987},
        {"a",1988},
        {"b",2014},
        {"c",2007},
        {"d",1999}
    };
    int n = sizeof(user)/sizeof(user[0]);

    //printf("%s %d\n", user[0].username, user[0].bday);

    // 3. Rendezd növekvő sorba az előző feladat tömbjét, a felhasználók születési éve szerint! Írasd ki az elemeket!
    //bubble_sort(user,n);

    // 4. Készíts függvényt, ami a felhasználók tömbjéből kiválogatja azokat, akik nagykorúak (betöltötték a 18-at)!
    // A függvény térjen vissza az eredménytömb címével!
    /*
    struct user *adults = find_adults(user,n);

    printf("Adults:\n");
    for (int i=0; adults[i].username != NULL; i++)
        printf("%10s %d\n", adults[i].username, adults[i].bday);
    */

    // 5. Készíts függvényt, ami két paraméterül kapott, rendezett egészekből álló tömböt összefűz egyetlen új, rendezett tömbbe!
    // A függvény térjen vissza az új tömb kezdőcímével!
    int a[4];
    int b[6];
    int size_a = sizeof(a)/sizeof(a[0]);
    int size_b = sizeof(b)/sizeof(b[0]);

    int *array;
    for (int i=0; i<size_a; i++)
        a[i] = rand() % 50;
    for (int i=0; i<size_b; i++)
        b[i] = rand() % 50;

    printf("size_a: %d\n",size_a);
    printf("Unsorted a:\n");
    printArray(a, size_a);

    printf("size_b: %d\n",size_b);
    printf("Unsorted b:\n");
    printArray(b, size_b);

    qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), cmpfunc);
    qsort(b, sizeof(b)/sizeof(b[0]), sizeof(b[0]), cmpfunc);

    printf("Sorted a:\n");
    printArray(a, size_a);
    printf("Sorted b:\n");
    printArray(b, size_b);

    array = mergeSort(a, size_a, b, size_b);
    printf("Sorted merged:\n");
    printArray(array, size_a + size_b);

    return 0;
}
