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

// https://unix.stackexchange.com/a/150746
int main()
{
   // Duplicates the current process
   int pid = fork();
   std::string processCommand = "cat /proc/" + std::to_string(pid);
   // https://stackoverflow.com/a/29639239
   system((processCommand + "/limits").c_str());
}