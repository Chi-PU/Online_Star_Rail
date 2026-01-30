#include "menu.h"




void displayShop() {
	std::cout << "Welcome to the Shop!" << endl;
}

void displayDaily() {
	cout << "Here is your daily reward!" << endl;
}

void displayCharacters() {
	cout << "Here are your characters!" << endl;
}

void displayWish() {
	cout << "Wish" << endl;
}

void displayMenu() {
	int x;
	cout << "1. Shop" << endl;
	cout << "2. Daily" << endl;
	cout << "3. Characters" << endl;
	cout << "4. Wish" << endl;
	cout << "5. Bag" << endl;
	cout << "6. Party" << endl;
	cout << "7. Exit" << endl;
	cin >> x;
	//loging can be added here to track user choices
	switch (x) {
	case 1:
		displayShop();
		break;
	case 2:
		displayDaily();
		break;
	case 3:
		displayCharacters();
		break;
	case 4:
		cout << "Wishing feature coming soon!" << endl;
		break;
	case 5:
		cout << "Bag feature coming soon!" << endl;
		break;
	case 6:
		cout << "Party feature coming soon!" << endl;
		break;
	case 7:
		exit(0);
		break;
	default:
		cout << "Invalid option, please try again." << endl;
		displayMenu();
		break;

	}
}