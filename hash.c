#include <stdio.h>
#include <stdlib.h>

struct data
{
    int key;
    int value;
};

struct data *array;
int capacity = 10;
int size = 0;

int hashcode(int key)
{
    return key % capacity;
}

int get_prime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    for (; !if_prime(n); n += 2)
        ;
    return n;
}

int if_prime(int n)
{
    int i;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void init_array()
{
    int i;
    capacity = get_prime(capacity);
    array = (struct data *)malloc(capacity * sizeof(struct data));
    for (i = 0; i < capacity; i++)
    {
        array[i].key = 0;
        array[i].value = 0;
    }
}

void insert(int key)
{
    int index = hashcode(key);
    if (array[index].value == 0)
    {
        array[index].key = key;
        array[index].value = 1;
        size++;
        printf("\n Key  (%d)  has been inserted \n", key);
    }
    else if (array[index].key == key)
    {
        printf("\n Key  (%d) already present, hence updating its value \n", key);
        array[index].value += 1;
    }
    else
    {
        printf("\n Element cannot be inserted");
    }
}

void remove_element(int key)
{
    int index = hashcode(key);
    if (array[index].value == 0)
    {
        printf("\nThis  Key  does not exists \n");

    }
    else{
        array[index].key = 0;
        array[index].value = 0;
        size--;
        printf("\n Key  (%d)  has been removed \n", key);

    }
}