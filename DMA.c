#include <stdio.h>
#include <stdlib.h>
void read(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}
void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d ", *(arr + i));
    }
}
void search(int *arr, int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (key == *(arr + i))
        {
            printf(" %d found at %d ", key, i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf(" element not found ");
    }
}
void insert_ele(int *arr, int *n, int value, int pos)
{

    int i;
    if (pos >= 0 && pos <= *n - 1)
    {
        arr = (int *)realloc(arr, (*(n) + 1) * sizeof(int));
        for (i = *n - 1; i >= pos; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }

        *(arr + pos) = value;
        (*n)++;
        display(arr, *n);
    }
    else
        printf("Inavlid Position\n");
}
void delete (int *arr, int *n, int pos)
{
    int i;
    if (pos >= 0 && pos <= *n - 1)
    {
        for (i = pos; i <= *n - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        arr = (int *)realloc(arr, (*(n) + 1) * sizeof(int));
        (*n)--;
        display(arr, *n);
    }
    else
    {
        printf("Inavlid Position\n");
    }
}
void delete_vl(int *arr, int *n, int value)
{
    int i, flag = 0;
    for (i = 0; i < *n; i++)
    {
        if (*(arr + i) == value)
        {
            flag = 1;
            for (int j = i; j <= *n - 1; j++)
            {
                *(arr + j) = *(arr + j + 1);
            }
            arr = (int *)realloc(arr, (*(n)-1) * sizeof(int));
            (*n)--;
            display(arr, *n);
            return;
        }
    }
    if (flag == 0)
    {
        printf("value not found");
    }
}

void main()
{
    int size, ch, key, pos, value, *arr;
    while (1)
    {
        printf(" \n1.Read \n2.Display\n3.Search\n4.Insert\n5.Delete\n6.DeleteByVal\n7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the size of the array\n");
            scanf("%d", &size);
            printf("enter the elements\n");
            arr = (int *)calloc(size, sizeof(int));
            if (arr == NULL)
            {
                printf("memory error");
            }
            read(arr, size);
            break;
        case 2:
            printf("the elements are \n");
            display(arr, size);
            break;
        case 3:
            printf("enter the key to searched\n ");
            scanf("%d", &key);
            search(arr, size, key);
            break;
        case 4:
            printf("enter the postion and value of the new key\n");
            scanf("%d %d", &pos, &value);
            insert_ele(arr, &size, value, pos);
            break;
        case 5:
            printf("enter the postion to be deleted\n");
            scanf("%d", &pos);
            delete (arr, &size, pos);
            break;
        case 6:
            printf("enter the value to be deleted\n");
            scanf("%d", &value);
            delete_vl(arr, &size, value);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("entered value is wrong");
            break;
        }
    }
}