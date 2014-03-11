//============================================================================
// Name        : Assignment3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "header.h"
#include "CLI.h"

using namespace view;

int main() {
	view::CLI cli;
	cli = CLI();
	cli.runProgramLoop();
	return 0;
}
