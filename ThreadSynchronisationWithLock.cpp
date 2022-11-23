/// <summary>
/// Name: Chi Huu Huynh
/// Date: 14/11/2022
/// Login: C00261172
/// </summary>

#include <iostream> // std::cout
#include <string> // std::string
#include <pthread.h> // pthread

#include <unistd.h> // sleep

pthread_mutex_t mutexLock; // Mutex Lock
int number = 0; // Global Variable
void *addition(void *_arg)
{
    pthread_mutex_lock(&mutexLock);
    int count = (long)_arg;
    while (count > 0) {
        number += count; // Adds the count to the number
        count--;
    }
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
    int count = (long)_arg;
    while (count > 0) {
        number -= count; // Subtracts the count to the number
        count--;
    }
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

    // Create 2 new threads
    pthread_create(&thread1, NULL, addition, (void*) 1000000);
    pthread_create(&thread2, NULL, subtraction, (void*) 1000000);

    std::string message1 = "Main Thread (Before Wait): " + std::to_string(number) + "\n";
    std::cout << message1;

    // Main thread waits until both of the threads have completed
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    std::string message2 = "Main Thread (After Wait): " + std::to_string(number) + "\n";
    std::cout << message2;
    pthread_mutex_destroy(&mutexLock); // Destroy mutex lock
    return 0;
}