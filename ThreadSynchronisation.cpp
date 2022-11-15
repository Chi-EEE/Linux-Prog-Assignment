/// <summary>
/// Name: Chi Huu Huynh
/// Date: 14/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <pthread.h>
#include <cstdint>
#include <atomic>

// Sleep Function: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
#include <chrono>
#include <thread>

std::atomic<int> number{3};
void *addition(void *_arg)
{
    int cpuRegister1 = number;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cpuRegister1 += (long)_arg;
    number = cpuRegister1;
    std::cout << "Added: " << number << "\n";

    char *ret;
    pthread_exit(ret);
}
void *subtraction(void *_arg)
{
    int cpuRegister1 = number;
    cpuRegister1 -= (long)_arg;
    number = cpuRegister1;
    std::cout << "Subtracted: " << number << "\n";

    char *ret;
    pthread_exit(ret);
}

int main()
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, addition, (void *)2);
    pthread_create(&thread_2, NULL, subtraction, (void *)-2);
    std::cout << "Default: " << number << "\n";
    return 1;
}
