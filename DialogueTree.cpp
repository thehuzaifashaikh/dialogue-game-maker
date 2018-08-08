#include "DialogueTree.h"

DialogueTree::DialogueTree(const std::string &dialogFile) {
	std::string contents = IOManager::readFile(dialogFile);

	std::string token;
	int fileCurrentNode = 0;
	for (int i = 0; i < contents.size(); i++) {
		char c = contents[i];
		token += c;

		if (token == "***") {
			i += 2;
			std::string number;
			while (isNum(contents[i])) {
				number += contents[i];
				i++;
			}

			int nodeNum = std::stoi(number);
			fileCurrentNode = nodeNum;
			i += 5;
			token = "";

		} else if (token == " " || token == "\n" || token == "\t") {
			token = "";

		} else if (token == "nodes:") {
			if (contents[i+1] == ' ')
				i++;
			i++;

			int totalNodes = (int)(contents[i] - '0');
			dialogueNodes.resize(totalNodes + 1);
			token = "";

		} else if (token == "Title:") {
			if (contents[i+1] == ' ')
				i++;
			i++;

			std::string fileTitle;
			while (contents[i] != '\t') {
				fileTitle += contents[i];
				i++;
			}

			dialogueNodes[fileCurrentNode].title = fileTitle;
			token = "";

		} else if (token == "Options:") {
			if (contents[i+1] == ' ')
				i++;
			i++;

			while (contents[i] == '(') {
				i++;

				std::string fileDialogue;
				while (contents[i] != '|') {
					fileDialogue += contents[i];
					i++;
				}
				i++;

				std::string fileTargetNodeStr;
				while (isNum(contents[i])) {
					fileTargetNodeStr += contents[i];
					i++;
				}

				bool fileIsEndOption = false;
				if (isNum(contents[i+1])) {
					i += 2;
					int fileIsEndNodeNum = (int)(contents[i-1] - '0');
					if (fileIsEndNodeNum == 1) {
						fileIsEndOption = true;
					}
				}


				int fileTargetNode = std::stoi(fileTargetNodeStr);
				dialogueNodes[fileCurrentNode].dialogueOptions.emplace_back(fileDialogue, &(dialogueNodes[fileTargetNode]), fileIsEndOption);
				i++;

				if (contents[i] == ' ') {
					i++;
				}
			}

			token = "";
		}
	}
}

DialogueTree::~DialogueTree() {
	dialogueNodes.clear();
}

void DialogueTree::run() {
	std::cout << "*** Starting Game ***\n---------------------\n\n";

	DialogueNode* currentNode = &dialogueNodes[1];
	while (true) {
		if (currentNode->title == "") {
			std::cout << "\n-----------------\n*** Game Over ***\n";
			exit(0);
		}

		std::cout << "\n\n" << currentNode->title << "\n";

		for (int i = 0; i < currentNode ->dialogueOptions.size(); i++) {
			std::cout << "[" << i+1 << "] \"" << currentNode->dialogueOptions[i].text << "\"\n";
		}

		int i;
		std::cout << "\n>>> ";
		std::cin >> i;
		i--;

		if (i < 0) {
			std::cout << "Invalid input.\n";
		}

		if (currentNode->dialogueOptions[i].endOption) {
			std::cout << "\n-----------------\n*** You got it! ***\n";
			exit(0);
		}

		currentNode = currentNode->dialogueOptions[i].nextNode;

	}
}

bool DialogueTree::isNum(char c) {
	return c >= '0' && c <= '9';
}