#include "user_interface.h"

bool UserInterface::openFile(const std::string& filename) {
	fin.open(filename);
	if (!fin.is_open()) {
		return false;
	}
	return true;
}

void UserInterface::readTextFromFile() {
	if (!fin.is_open()) {
		return;
	}
	std::string inserter;
	while (!fin.eof()) {
		std::getline(fin, inserter, '\n');
		std::istringstream tempStream(inserter);
		std::string substr;
		while (tempStream >> substr) {
			dict.insert(substr);
		}
	}
}

void UserInterface::readStringFromConsole() {
	if (!fin.is_open()) {
		return;
	}
	std::string inserter;
	std::getline(std::cin, inserter, '\n');
	std::getline(std::cin, inserter, '\n');
	std::istringstream tempStream(inserter);
	std::string substr;
	while (tempStream >> substr) {
		dict.insert(substr);
	}
}

void UserInterface::readWord(const std::string& word) {
	if (!fin.is_open()) {
		return;
	}
	dict.insert(word);
}

void UserInterface::showDictionary(std::ostream& out) {
	if (!fin.is_open()) {
		return;
	}
	dict.print(out);
}

void UserInterface::showTopTree(std::ostream& out) {
	dict.popularWords(out);
}

size_t UserInterface::ditionarySize() {
	return dict.size();
}

void UserInterface::eraseWord() {
	std::string a;
	std::cin >> a;
	if (!dict.erase(a)) {
		std::cout << "Word is missing!\n";
	}
}

void UserInterface::clearDictionary() {
	dict.clear();
}

void UserInterface::showMenu() {
	std::cout << "Input number you want:\n";
	std::cout << "1) Read text from the file\n";
	std::cout << "2) Read string from the console\n";
	std::cout << "3) Delete word from dictionary\n";
	std::cout << "4) Show all dictionary\n";
	std::cout << "5) Show top three word\n";
	std::cout << "6) Show dictionary size\n";
	std::cout << "7) Clear dictionary\n";
	std::cout << "8) Show menu\n";
	std::cout << "9) Stop\n\n";
}

void UserInterface::Menu() {
	if (!fin.is_open()) {
		std::cout << "file is not open!\n";
	}
	showMenu();
	bool isOver = false;
	while (!isOver) {
		char command;
		std::cin >> command;
		switch (command) {
		case '1':
			readTextFromFile();
			break;
		case '2':
			readStringFromConsole();
			break;
		case '3':
			eraseWord();
			break;
		case '4':
			showDictionary(std::cout);
			break;
		case '5':
			showTopTree(std::cout);
			break;
		case '6':
			std::cout << ditionarySize() << '\n';
			break;
		case '7':
			clearDictionary();
			break;
		case '8':
			showMenu();
			break;
		case '9':
			isOver = true;
			break;
		default:
			std::cout << "Wrond command!\n\n";
			showMenu();
			break;
		}
	}
}