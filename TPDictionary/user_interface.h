#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "dictionary_map.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class UserInterface {
public:
	UserInterface() = default;
	UserInterface(const UserInterface& copy) = delete;
	UserInterface(UserInterface&& move) = delete;
	UserInterface& operator=(const UserInterface& copy) = delete;
	UserInterface& operator=(UserInterface&& move) noexcept = delete;

	~UserInterface() {
		if (fin.is_open()) {
			fin.close();
		}
	}

	bool openFile(const std::string& filename);

	void readTextFromFile();
	void readStringFromConsole();
	void readWord(const std::string& word);

	void eraseWord();

	void showDictionary(std::ostream& out);
	void showTopTree(std::ostream& out);

	size_t ditionarySize();
	void clearDictionary();

	void showMenu();
	void Menu();
private:
	DictionaryMap dict;
	std::ifstream fin;
};

#endif

