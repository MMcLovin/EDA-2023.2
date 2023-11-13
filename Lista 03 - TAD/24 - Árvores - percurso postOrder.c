#include <stdio.h>
#include <stdlib.h>
 
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node
struct no {
    int dado;
    struct no *esq, *dir;
} no;
 
// Stack type
struct Stack {
    int size;
    int top;
    struct no** array;
};
 
// A utility function to create a new tree no
struct no* newno(int dado)
{
    struct no* no = (struct no*)malloc(sizeof(struct no));
    no->dado = dado;
    no->esq = no->dir = NULL;

    return no;
}
 
// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct no**)malloc(stack->size * sizeof(struct no*));
    
    return stack;
}
 
// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{
    return stack->top - 1 == stack->size;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
void push(struct Stack* stack, struct no* no)
{
    if (isFull(stack))    return;
    stack->array[++stack->top] = no;
}
 
struct no* pop(struct Stack* stack)
{
    if (isEmpty(stack)) return NULL;

    return stack->array[stack->top--];
}
 
struct no* peek(struct Stack* stack)
{
    if (isEmpty(stack)) return NULL;
    
    return stack->array[stack->top];
}
 
// An iterative function to do postorder traversal of a
// given binary tree
void pos_orderm(struct no* root)
{
    // Check for empty tree
    if (root == NULL) return;
 
    struct Stack* stack = createStack(MAX_SIZE);
    do 
    {
        // Move to esqmost no
        while (root) 
        {
            // Push root's dir child and then root to
            // stack.
            if (root->dir)
                push(stack, root->dir);
            push(stack, root);
 
            // Set root as root's esq child
            root = root->esq;
        }
 
        // Pop an item from stack and set it as root
        root = pop(stack);
 
        // If the popped item has a dir child and the
        // dir child is not processed yet, then make sure
        // dir child is processed before root
        if (root->dir && peek(stack) == root->dir) 
        {
            pop(stack); // remove dir child from stack
            push(stack, root); // push root back to stack
            root = root->dir; // change root so that the
                                // dir child is processed
                                // next
        }
        else // Else print root's dado and set root as NULL
        {
            printf("%d ", root->dado);
            root = NULL;
        }
    } while (!isEmpty(stack));
}