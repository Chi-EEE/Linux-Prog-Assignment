/// <summary>
/// Name: Chi Huu Huynh
/// Date: 07/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/// @brief Method for the child process when it is terminated
void onExit()
{
    std::cout << "This message is sent as the child process has been terminated\n";
}

int main()
{
    int pid = fork(); // Create a child process
    if (pid == 0)     // Check if the current process cannot create another process
    {
        // Let the user decide whether to exit the process with atexit() or not
        int choice;
        do
        {
            std::cout << "Would you like to exit this child process without atexit().. [1 = Yes, 0 = No]\n";
            std::cin >> choice;
            switch (choice)
            {
            case 0:
                // Run the onExit method when the process has been terminated
                atexit(*onExit);
                exit(111);
                break;
            case 1:
                exit(222);
                break;
            default:
                break;
            }
        } while (true);
    }
    else
    {
        int *stat_loc; // Pointer to put stat_loc in
        // Wait for the child process to end
        waitpid(pid, stat_loc, WCONTINUED);
        // Get the Child Process exit code using WEXITSTATUS
        std::cout << "The parent process is now going to exit\nChild Process exit code: " << WEXITSTATUS(*stat_loc) << "\n";
    }
    // The process exits once it finishes
}