#include <iostream>

#include "DialogueTree.h"

int main(int argc, char** argv)
{
	DialogueTree dt(argv[1]);
	dt.run();

	return 0;
}