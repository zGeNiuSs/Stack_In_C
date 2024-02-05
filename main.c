#include "stack_ds.c"

stack_t *Stack1;
stack_status_t Stack_ret;

int main(){

    Stack_ret = STACK_NOK;
    int SizeOfStack=0;
    int ret;
    int num;
    int exit=1;
    int value;
    char *arrOfStatus[]={
                        "STACK_NOK",
                        "STACK_OK",
                        "STACK_FULL",
                        "STACK_EMPTY"
                        };  //Array of status codes for the stack operations

    while (exit)
    {
        printf("\n///////////////// Menu /////////////////\n");
        printf("1: Create a new stack.\n");
        printf("2: Push an element to the stack.\n");
        printf("3: Pop an element from the stack.\n");
        printf("4: View the top element of the stack.\n");
        printf("5: Display all the elements of the stack.\n");
        printf("6: Check a status of the stack.\n");
        printf("7: Exit program.\n");
        printf("Enter your choice : ");
        scanf("%d",&num);
        
        switch(num){
            
            case 1:
                if (Stack1){
                    printf("Stack alraedy Created.\n");
                }else{
                    printf("Enter the Number of Elements in a stack: ");
                    scanf("%i",&SizeOfStack);
                    Stack1 = stack_create_func(SizeOfStack, &Stack_ret);
                    printf("Created a stack successfully.\n");
                }
                break;
            
            case 2:
                if (Stack1)
                {
                    if(Stack_ret==STACK_FULL){
                        printf("The stack is Full!\n");
                    }else{
                        printf("Enter an element whould you want to push in the stack : ");
                        scanf("%i",&value);
                        printf("Pushing element %d into the stack.\n",value);
                        stack_push_func(Stack1, &value, &Stack_ret);
                        printf("Element pushed successfully.\n");
                    }
                } else {
                    printf("Please create a stack first.\n");
                }
                break;
            
            case 3:
                if (Stack1)
                {
                    if(Stack_ret==STACK_EMPTY){
                        printf("The stack is Empty!\n");
                    }else{
                        ret = stack_pop_func(Stack1, &Stack_ret);
                        printf("Poped element %d from the stack.\n",ret);
                    }
                } else {
                    printf("Please create a stack first.\n");
                }
                break;
            
            case 4:
                if (Stack1)
                {
                    if(Stack_ret==STACK_EMPTY) {
                        printf("The stack is Empty!\n");
                    }else{
                        ret = stack_top_func(Stack1, &Stack_ret);
                        printf("Top Element is %i.\n",ret);
                    }
                } else {
                    printf("Please create a stack first.\n");
                }   
                break;
            
            case 5:
                if (Stack1)
                {
                    if(Stack_ret==STACK_EMPTY) {
                        printf("The stack is Empty!\n");
                    } else{
                        printf("Displaying elements of Stack:\n");
                        stack_display_func(Stack1, &Stack_ret);
                    }
                }else{
                    printf("Please create a stack first.\n");
                }
                break;

            case 6:
                if (Stack1)
                {
                    printf("status of the stack is %s\n", arrOfStatus[Stack_ret]);
                }else{
                    printf("Please create a stack first.\n");
                }
                break;

            case 7:
                if (Stack1)
                {
                    stack_destroy_func(Stack1, &Stack_ret);
                    exit = 0;
                }else{
                    exit = 0;
                }
                break;

            default :
                printf("\nInvalid Choice. Please enter again.");
        }
    }
    


    return 0; 
}