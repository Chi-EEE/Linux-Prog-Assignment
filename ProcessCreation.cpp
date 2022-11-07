/// <summary>
/// Name: Chi Huu Huynh
/// Date: 06/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
   // Duplicates the current process
   int pid = fork();
   int currentPID = getpid();
   int parentPID = getppid();
   std::string message = "Process PID: ";
   if (pid == 0) // This will be the Child Process that cannot create Child Processes
   {
      message = "[C] This is a Child Process.\n[C] Child " + message;
      message += std::to_string(pid) + "\n" + "[C] Parent PID: " + std::to_string(parentPID) + "\n" + "[C] Current PID: " + std::to_string(currentPID) + "\n";
   }
   else if (pid > 0) // This will be the Parent Process that can create Child Processes
   {
      message = "[P0] This is a Parent Process.\n[P0] Parent " + message;
      message += std::to_string(pid) + "\n" + "[P0] Parent PID: " + std::to_string(parentPID) + "\n" + "[P0] Current PID: " + std::to_string(currentPID) + "\n";
   }
   else if (pid == -1) // This will be the Parent Process that cannot create Child Processes
   {
      message = "[P-1] This is a Parent Process.\n[P-1] Parent " + message;
      message += std::to_string(pid) + "\n" + "[P-1] Parent PID: " + std::to_string(parentPID) + "\n" + "[P-1] Current PID: " + std::to_string(currentPID) + "\n";
   }
   std::cout << message;
}