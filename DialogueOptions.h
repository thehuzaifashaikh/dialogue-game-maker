#pragma once

#include <string>

class DialogueNode;

class DialogueOptions
{
public:
	DialogueOptions(const std::string& text, DialogueNode* nextNode, bool endOption) {
		this->text = text;
		this->nextNode = nextNode;
		this->endOption = endOption;
	}

	std::string text;
	bool endOption = false;
	DialogueNode* nextNode;
};