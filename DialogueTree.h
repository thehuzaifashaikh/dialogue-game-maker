#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "DialogueNode.h"
#include "IOManager.h"

class DialogueTree
{
public:
	DialogueTree(const std::string& dialogFile);
	~DialogueTree();

	void run();

private:
	bool isNum(char c);

	std::vector<DialogueNode> dialogueNodes;
};