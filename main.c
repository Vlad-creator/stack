#include <stdio.h>
#include <stdlib.h>

#define KAN1 1212345678912345678
#define KAN2 1212345678912345679

typedef int Elem_T;

struct stack
{
    unsigned long long  Kanoreyka1;
    int size;
    int maxelems;
    int plusstk;
    Elem_T* arr;
    unsigned long long Kanoreyka2;
};

int stack_pop(struct stack* ptr);

void stack_construct (struct stack* ptr);
void stack_push(struct stack* ptr);
void stack_OK(struct stack* ptr);
void stack_distruct(struct stack* ptr);
void stack_dump(struct stack* ptr);
void difference(struct stack* ptr);
void sum(struct stack* ptr);

int main()
{
    struct stack stk;
    struct stack* stk_ptr = &stk;
    int N = 0;
    scanf("%d" , &N);
    stack_construct(stk_ptr);
    for (int i = 0 ; i < N ; i++)
        stack_push(stk_ptr);
    sum(stk_ptr);
    stack_dump(stk_ptr);
    stack_distruct(stk_ptr);
    return 0;
}

void stack_push(struct stack* ptr)
{
    stack_OK(ptr);
    if ((ptr->size) == ((ptr->maxelems)))
    {
        Elem_T* arrx = ptr->arr;
        ptr->maxelems = ptr->maxelems + ptr->plusstk;
        ptr->arr = realloc(arrx , ptr->maxelems * sizeof(Elem_T));
        if (ptr->arr == NULL)
            printf ("virubay nahyi");
    }

    scanf("%d" , &((ptr->arr)[(ptr->size)]));
    (ptr->size)++;
}

int stack_pop(struct stack* ptr)
{
    stack_OK(ptr);
    if (ptr->size == 0)
    {
        printf("DAUN VIRUBAY");
        return 0;
    }
    (ptr->size)--;
    int pop = (ptr->arr)[(ptr->size)];
    return pop;
}

void stack_construct(struct stack* ptr)
{
    ptr->Kanoreyka1 = 1212345678912345678;
    ptr->Kanoreyka2 = 1212345678912345679;
    ptr->size = 0;
    ptr->maxelems = 2;
    ptr->plusstk = 10;
    ptr->arr = calloc(ptr->maxelems , sizeof(Elem_T));
}

void stack_OK(struct stack* ptr)
{
    if (ptr->size < 0)
        printf ("POMOIKA VIRUBAY");
    if ((ptr->Kanoreyka1 != KAN1) || (ptr->Kanoreyka2 != KAN2))
        printf ("POMOIKA VIRUBAY");
}

void stack_distruct(struct stack* ptr)
{
    ptr->size = 0;
    ptr->maxelems = 0;
    ptr->plusstk = 0;
    free(ptr->arr);
}

void stack_dump(struct stack* ptr)
{
    FILE* fp = fopen("C:\\Users\\vlad-\\OneDrive\\Рабочий стол\\gnu1.txt", "w");
    //fprintf (fp , "kanoreyka1 = %llu\n" , ptr->Kanoreyka1);
    //fprintf (fp , "kanoreyka2 = %llu\n" , ptr->Kanoreyka2);
    fprintf (fp , "size = %d\n" , ptr->size);
    fprintf (fp , "maxelems = %d\n" , ptr->maxelems);
    for (int i = 0 ; i < ptr->size ; i++)
        fprintf(fp , "arr[%d] = %d\n" , i , ptr->arr[i]);
    fclose(fp);
}

void sum(struct stack* ptr)
{
    stack_OK(ptr);
    Elem_T* mass = (ptr->arr);
    mass[(ptr->size) - 2] = mass[(ptr->size) - 1] + mass[(ptr->size) - 2];
    mass[ptr->size] = 0;
    (ptr->size)--;
}

void difference(struct stack* ptr)
{
    stack_OK(ptr);
    Elem_T* mass = (ptr->arr);
    mass[(ptr->size) - 2] = mass[(ptr->size) - 1] - mass[(ptr->size) - 2];
    mass[ptr->size] = 0;
    (ptr->size)--;
}





