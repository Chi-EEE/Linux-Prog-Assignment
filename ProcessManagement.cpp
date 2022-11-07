/// <summary>
/// Name: Chi Huu Huynh
/// Date: 07/11/2022
/// Login: C00261172
/// </summary>

#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
   int pid = getpid(); // Gets the current process id
   const std::string PROCESS_COMMAND = "cat /proc/" + std::to_string(pid);
   const std::string HEADING = "limits";
   
   // Executes the shell command and outputs the result
   // https://stackoverflow.com/a/29639239
   system((PROCESS_COMMAND + "/" + HEADING).c_str());
}