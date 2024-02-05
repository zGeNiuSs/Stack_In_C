#ifndef STACK_DS_H 
#define STACK_DS_H 

#include <stdio.h>
#include <stdlib.h>
#include "stack_types.h"

void stack_push_func(stack_t* MyStack, int *push_value, stack_status_t *ret);
int stack_pop_func(stack_t* MyStack, stack_status_t *ret);
int stack_top_func(stack_t* MyStack, stack_status_t *ret);
stack_t *stack_create_func(int stack_size, stack_status_t *ret);
void stack_display_func(stack_t* MyStack, stack_status_t *ret);
void  stack_destroy_func(stack_t* MyStack, stack_status_t *ret);
int isEmpty(stack_t* MyStack);
int isFull(stack_t* MyStack);




#endif //STACK_DS_H 