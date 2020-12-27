#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//the number of elements in the array
const int dim = 1000;

void bubble_sort( int array[dim] );
void array_randomizer( int array[dim] );

int main (void)
{
    srand( (unsigned)time(NULL) );

    //array creating
    int arr[dim];
    array_randomizer( arr );

    //timing 
    int start, stop;
    start = clock();

    bubble_sort( arr );

    stop = clock();
    float delta = (float)(stop - start)/CLOCKS_PER_SEC;

    printf("start time: %i\n", start);
    printf("stop time: %i\n", stop);
    printf("algorithm duration: %f\n", delta );

    printf("sorted array:\n\n");
    for(int i = 0; i < dim; i++){
        printf("%i ", arr[i]);
        if(i%10 == 0 && i != 0)
            printf("\n");
    }
    printf("\n\n");
}

/*
* this function fill the array with random numbers
*/
void array_randomizer( int array[dim] ){
    for (int i = 0; i < dim; i++){
        array[i] = rand();
    }
}

/*
* this function sorts the array
*/
void bubble_sort( int array[dim] )
{
    int tmp;

    for (int i = 0; i < dim; i++){
        for ( int j = 0; j < dim - i - 1; j++){
            if ( array[j] > array[j + 1] ){
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            } 
        }
    }
}