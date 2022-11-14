/// <summary>
/// Name: Chi Huu Huynh
/// Date: 14/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdint>

static int number = 3;
void *hello(void *_arg)
{
    int* data;
    data = (int *) _arg;
    number += *data;
    delete data;

    char *ret;
    pthread_exit(ret);
}

int main()
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, hello, (void *)2);
    pthread_create(&thread_2, NULL, hello, (void *)-2);
    while (true)
    {
        std::cout << number << "\n";
    }
    return 1;
}
