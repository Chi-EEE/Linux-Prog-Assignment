/// <summary>
/// Name: Chi Huu Huynh
/// Date: 14/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>  // std::cout
#include <string>    // std::string
#include <pthread.h> // pthread
#include <atomic>    // std::atomic

#include <unistd.h> // sleep

pthread_mutex_t mutexLock;
std::atomic<int> number{3}; // Global Variable
void *addition(void *_arg)
{
    pthread_mutex_lock(&mutexLock);
    int cpuRegister1 = number;
    // Number is added to the cpu register and there is a delay to when the adding takes place.
    sleep(1);
    cpuRegister1++;
    number = cpuRegister1;
    std::string message = "Added: " + std::to_string(number) + "\n";
    std::cout << message;
    pthread_mutex_unlock(&mutexLock);

    // Without this, vscode sends an warning
    char *retval;
    pthread_exit(retval);
}
void *subtraction(void *_arg)
{
    pthread_mutex_lock(&mutexLock);
    int cpuRegister1 = number;
    cpuRegister1--;
    number = cpuRegister1;
    std::string message = "Subtracted: " + std::to_string(number) + "\n";
    std::cout << message;
    pthread_mutex_unlock(&mutexLock);

    // Without this, vscode sends an warning
    char *retval;
    pthread_exit(retval);
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, addition, NULL);
    pthread_create(&thread2, NULL, subtraction, NULL);

    std::string message1 = "Main Thread (Before Wait): " + std::to_string(number) + "\n";
    std::cout << message1;
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sleep(1);
    std::string message2 = "Main Thread (After Wait): " + std::to_string(number) + "\n";
    std::cout << message2;
    pthread_mutex_destroy(&mutexLock); // Destroy mutex lock
    return 0;
}