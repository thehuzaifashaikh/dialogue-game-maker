#pragma once

#include <string>
#include <vector>

#include "DialogueOptions.h"

class DialogueNode
{
public:
	DialogueNode() {}

	std::string title;
	std::vector<DialogueOptions> dialogueOptions;
};