#include "dictionary_map.h"
#include "user_interface.h"

int main() {
	UserInterface a;
	a.openFile("input.txt");
	a.Menu();
	return 0;
}
