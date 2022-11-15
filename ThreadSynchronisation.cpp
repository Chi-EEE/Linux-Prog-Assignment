/// <summary>
/// Name: Chi Huu Huynh
/// Date: 14/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <pthread.h>
#include <atomic> // std::atomic

#include <unistd.h> // https://man7.org/linux/man-pages/man3/sleep.3.html

std::atomic<int> number{3}; // Global Variable
void *addition(void *_arg)
{
    int cpuRegister1 = number;
    // Number is added to the cpu register and there is a delay to when the adding takes place.
    sleep(1);
    cpuRegister1 += (long)_arg;
    number = cpuRegister1;
    std::string message = "Added: " + std::to_string(number) + "\n";
    std::cout << message;

    char *ret;
    pthread_exit(ret);
}
void *subtraction(void *_arg)
{
    int cpuRegister1 = number;
    cpuRegister1 -= (long)_arg;
    number = cpuRegister1;
    std::string message = "Subtracted: " + std::to_string(number) + "\n";
    std::cout << message;

    char *ret;
    pthread_exit(ret);
}

int main()
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, addition, (void *)2);
    pthread_create(&thread_2, NULL, subtraction, (void *)2);

    std::string message1 = "Main Thread (Before Wait): " + std::to_string(number) + "\n";
    std::cout << message1;
    sleep(1);
    std::string message2 = "Main Thread (After Wait): " + std::to_string(number) + "\n";
    std::cout << message2;
    return 0;
}
