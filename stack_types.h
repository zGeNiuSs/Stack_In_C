#ifndef STACK_TYPES_H 
#define STACK_TYPES_H 

typedef struct
{
    int *my_stack;
    int topIndex; // Index of the next element to be pushed onto the stack.
    int stack_counter;
    int stack_max;
}stack_t;

typedef enum
{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY
}stack_status_t;


#endif //STACK_TYPES_H 