/// <summary>
/// Name: Chi Huu Huynh
/// Date: 23/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
   int pid = getpid(); // Gets the current process id
   const std::string PROCESS_COMMAND = "cat /proc/" + std::to_string(pid);
   const std::string HEADING = "sched";
   
   // Executes the shell command and outputs the resource limits of the process
   system((PROCESS_COMMAND + "/" + HEADING).c_str());
   // se.sum_exec_runtime is the execution time of the process
}