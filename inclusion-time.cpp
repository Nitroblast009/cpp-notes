/*Notes:
     - #include <> is only for preprocssor libs
     - #include "" is for all libs/files, but common practice is to just use it for local files
     - Never include .cpp files; only .h files
     - Never compile .h files; only .cpp files
     - #pragma once helps avoid repeated inclusion
*/
#include <iostream>
#include "it2.h"

int main()
{
     printStuff("Sup");
}