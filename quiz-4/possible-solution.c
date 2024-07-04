#include <stdio.h>
#include <stdlib.h> // this is used for malloc()

/// @brief Recursive function to calculate the factorial of a positive integer.
/// @param n A memory address containing the current n of the function given the recursive context.
/// @return A memory address containing the return value.
int *factorial(int *n) {
        
    // make a new memory address that is of an int type.
    // in parameter passing by reference, malloc() is often used
    // because its memory is generally not cleaned after a function has completed.  
    int *returned_memory_address = (int*) malloc(sizeof(int));
    
    // if received n is 0 or 1
    if (*(n)==0 || *(n)==1) {

        // update the values inside the returned memory address to 1
        *(returned_memory_address) = 1;


    // if received n is greater than 1, 
    // multiply that received n with another instance of itself with (n-1),
    // but whose value is placed in a memory address
    } else {

        // make another memory address to store the value 
        // which will be pass to another instance of *factorial() 
        int *another_memory_address = (int*) malloc(sizeof(int));

        // its value is <current_n_value> minus 1
        *(another_memory_address) = *(n)-1;

        // place the value on the memory address to be returned later
        *(returned_memory_address) = (*n) * (*(factorial(another_memory_address)));

        // free dynamically-allocated malloc() memory
        free(another_memory_address);
    }
    
    // actually return the return value
    return returned_memory_address;
}


// main function
int main() {

    // variable declarations
    int num, recursive_factorial_value;
    int *recursive_factorial_result_address;

    // Get the number for which to calculate factorial
    printf("[recursive, pass-by-reference] \n\nEnter a number to calculate factorial: ");
    scanf("%d", &num);

    // factorials not allowed if it is a negative integer. Print error then exit.
    if (num < 0) { printf("Factorial is not allowed for negative numbers.\n"); return 0; }
    
    // at this point, number (if not a string) is a positive or zero integer.
    recursive_factorial_result_address = factorial(&num);

    // acquire the value in the given memory address
    recursive_factorial_value = *(recursive_factorial_result_address);
    
    // free the malloc()-allocated memory after acquiring value
    free(recursive_factorial_result_address);
    
    // print the result
    printf("The factorial expression '%i!' has a value of %i.\n\n", num, recursive_factorial_value);

    // exit 
    return 0;
}
