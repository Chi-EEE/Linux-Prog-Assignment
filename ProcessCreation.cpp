/// <summary>
/// Name: Chi Huu Huynh
/// Date: 06/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <memory>

int main()
{
   // Duplicates the current process
   int pid = fork();
   int currentPID = getpid();
   int parentPID = getppid();
   std::string message = "Process PID: ";
   if (pid == 0)
   {
      message = "[P0] This is a Parent Process.\n[P0] " + message;
      message += std::to_string(pid) + "\n" + "[P0] Parent PID: " + std::to_string(parentPID) + "\n" + "[P0] Current PID: " + std::to_string(currentPID) + "\n";
   }
   else if (pid > 0)
   {
      message = "[C] This is a Child Process.\n[C] " + message;
      message += std::to_string(pid) + "\n" + "[C] Parent PID: " + std::to_string(parentPID) + "\n" + "[C] Current PID: " + std::to_string(currentPID) + "\n";
   }
   else if (pid == -1)
   {
      message = "[P-1] This is a Parent Process.\n[P-1] " + message;
      message += std::to_string(pid) + "\n" + "[P-1] Parent PID: " + std::to_string(parentPID) + "\n" + "[P-1] Current PID: " + std::to_string(currentPID) + "\n";
   }
   std::cout << message;
}