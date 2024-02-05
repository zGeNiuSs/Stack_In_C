#include "stack_ds.h"


void stack_push_func(stack_t* MyStack, int *push_value, stack_status_t *ret)
{
    if (MyStack->my_stack == NULL || ret == NULL || push_value == NULL) {
        /* Stack is not pushed */
        printf("Error: The stack has not been pushed.\n");
        *ret = STACK_NOK;
    }
    else{
        if (isFull(MyStack))
        {
            *ret = STACK_FULL;
        }
        else{
            /* Stack is pushed */
            (MyStack->topIndex)++;
            MyStack->my_stack[MyStack->topIndex] = *push_value;
            (MyStack->stack_counter)++;
            *ret = STACK_OK;
        }
        if (isFull(MyStack))
        {
            *ret = STACK_FULL;
        }  
    }
}

int stack_pop_func(stack_t* MyStack, stack_status_t *ret)
{
    int return_value=0;
    if (MyStack->my_stack == NULL || ret == NULL) {
        /* Stack is not poped */
        printf("Error: The stack has not been poped.\n");
        *ret = STACK_NOK;
    }
    else{  
        if (isEmpty(MyStack))
        {
            *ret = STACK_EMPTY;
        }
        else{
            /* Stack is poped */
            return_value = MyStack->my_stack[MyStack->topIndex];
            (MyStack->topIndex)--;
            (MyStack->stack_counter)--;
            if((MyStack->topIndex)==-1)
                *ret = STACK_EMPTY;
            else
                *ret = STACK_OK;
        }
    }
    return  return_value;
}

int stack_top_func(stack_t* MyStack, stack_status_t *ret)
{
    int return_value = 0;
    if (MyStack->my_stack == NULL || ret == NULL) {
        /* Stack is not top value */
        printf("Error: The stack has not been poped.\n");
        *ret = STACK_NOK;
    }
    else{
        if (isEmpty(MyStack))
        {
            *ret = STACK_EMPTY;
        }
        else{
            /* Stack is top value */
            return_value = MyStack->my_stack[MyStack->topIndex];
            *ret = STACK_OK;
        }
    }
    return  return_value;
}

stack_t *stack_create_func(int stack_size, stack_status_t *ret)
{
    stack_t *MyStack = NULL;
    MyStack->topIndex == -1;
    
    if (ret == NULL) {
        /* Stack is not initialized */
        printf("Error: The stack has not been initialized.\n");
        *ret = STACK_NOK;
        MyStack = NULL;
    }
    else{
        /* Stack is initialized */
        MyStack = (stack_t *)malloc(sizeof(stack_t));
        
        MyStack->stack_max = stack_size;
        MyStack->topIndex = -1;
        MyStack->stack_counter = 0;

        MyStack->my_stack = (int *)calloc(MyStack->stack_max, sizeof(int));

        if (!MyStack->my_stack) {
            /* Stack is not initialized */
            printf("Error: The stack has not been initialized.\n");
            free(MyStack);
            MyStack = NULL;
            *ret = STACK_NOK;
        }else
        {
            *ret = STACK_EMPTY;
        }

    }
    return  MyStack;
}

void stack_display_func(stack_t* MyStack, stack_status_t *ret)
{
    if (MyStack->my_stack == NULL || ret == NULL) {
        /* Stack is not displayed */
        printf("Error: The stack has not been displayed.\n");
        *ret = STACK_NOK;
    }
    else{
        if(isEmpty(MyStack)){
            printf("The stack is empty!\n");
            *ret = STACK_EMPTY;
        }
        else{
        /* Stack is displayed */
        for (int i = 0; i < MyStack->stack_counter; i++)
        {
            printf("%d ", MyStack->my_stack[i]);
        }
        printf("\n");
        *ret = STACK_OK;
        }
    }
}

void  stack_destroy_func(stack_t* MyStack, stack_status_t *ret)
{
    if (MyStack->my_stack == NULL || ret == NULL) {
        /* Stack is not destroied */
        printf("Error: The stack has not been destroied.\n");
        *ret = STACK_NOK;
    }
    else{
        /* Stack is destroied */
        free(MyStack->my_stack);
        MyStack->my_stack=NULL;
        free(MyStack);
        MyStack=NULL;
        *ret = STACK_OK;
    }
}

int isEmpty(stack_t* MyStack){
    return (MyStack->topIndex == -1);
}

int isFull(stack_t* MyStack){
    return ((MyStack->topIndex)+1 == MyStack->stack_max);
}