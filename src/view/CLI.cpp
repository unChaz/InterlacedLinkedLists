/*
 * CLI.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#include "CLI.h"

namespace view {

CLI::CLI() {
	this->controller = ApplicationController();
	this->controller.run();
}

void CLI::printMovie(model::MovieNode* head) {
	cout << head->getTitle() << "\t";
	cout << head->getCompany() << "\t";
	cout << head->getRating() << "\t";
	cout << head->getLength() << endl;
}

/*
 * Prints the movie list in descending order.
 * param: head - the first element in the list.
 * param: method: the method of ordering (BY_LENGTH, BY_TITLE, BY RATING)
 * param: size - the size of the list.
 */
void CLI::printMovieList(model::MovieNode* head, const string& method, int size) {
	if (size == 0) {
		return;
	}
	if (method.compare(BY_TITLE) == 0) {
		printMovie(head);
		printMovieListReversed(head->getNextTitle(), method, size - 1);
	} else if (method.compare(BY_LENGTH) == 0) {
		printMovie(head);
		printMovieListReversed(head->getNextLength(), method, size - 1);
	} else if (method.compare(BY_RATING) == 0) {
		printMovie(head);
		printMovieListReversed(head->getNextRating(), method, size - 1);
	}
}

/*
 * Prints the movie list in descending order.
 * param: head - the first element in the list.
 * param: method: the method of ordering (BY_LENGTH, BY_TITLE, BY RATING)
 * param: size - the size of the list.
 * precondition: none
 */
void CLI::printMovieListReversed(model::MovieNode* head, const string& method, int size) {
	if (size == 0) {
		return;
	}
	if (method.compare(BY_TITLE) == 0) {
		printMovieListReversed(head->getNextTitle(), method, size - 1);
		printMovie(head);
	} else if (method.compare(BY_LENGTH) == 0) {
		printMovieListReversed(head->getNextLength(), method, size - 1);
		printMovie(head);
	} else if (method.compare(BY_RATING) == 0) {
		printMovieListReversed(head->getNextRating(), method, size - 1);
		printMovie(head);
	}

}

CLI::~CLI() {

}

/*
 * Gets a string from user input
 */
string CLI::getUserString() {
	string input;
	getline(cin, input);
	return input.substr(0, input.length() - 1);
}

/*
 * Prints a message to the console ending with a newline.
 */
void CLI::printLine(const string& message) {
	cout << message << endl;
}

/*
 * Prints a message to the console.
 */
void CLI::print(const string& message) {
	cout << message;
}

void CLI::printWelcome() {
	printLine("Welcome to Chaz Ferguson's Movie Database.");
}

bool CLI::stringEquals(const string& string1, const string& string2) {
	return string1.compare(string2) == 0;
}

void CLI::printFarewell() {
	printLine("Good-bye.");
}

void CLI::runProgramLoop() {
	printLine("\nPlease enter the desired action: (l)oad file, (s)ave file,");
	printLine("(i)nsert, (d)elete, (a)lphabetic, re(v)erse alphabetic,");
	printLine("(r)ating ascending, ratin(g) descending, le(n)gth ascending,");
	printLine("leng(t)h descending, (q)uit");

	string input = toLower(getUserString());
	if (stringEquals(input, "l")) {
		loadFile();
	} else if (stringEquals(input, "s")) {
		saveFile();
	} else if (stringEquals(input, "i")) {
		insertMovie();
	} else if (stringEquals(input, "d")) {
		deleteMovie();
	} else if (stringEquals(input, "a")) {
		alphabetic();
	} else if (stringEquals(input, "v")) {
		reverseAlphabetic();
	} else if (stringEquals(input, "r")) {
		ratingAscending();
	} else if (stringEquals(input, "g")) {
		ratingDescending();
	} else if (stringEquals(input, "n")) {
		lengthAscending();
	} else if (stringEquals(input, "t")) {
		lengthDescending();
	} else if (stringEquals(input, "q")) {
		printFarewell();
		exit(0);
	} else {
		printLine("Invalid input.");
	}
	runProgramLoop();
}

string CLI::toLower(const string& str) {
	std::string data = str;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return str;
}

void CLI::loadFile() {
	printLine("Enter the file to load:");
	string input = toLower(getUserString());

	bool success = controller.loadFile(input);
	if (success) {
		printLine("File loaded successfully!");
	} else {
		printLine("Loading Failed!!!");
	}

	runProgramLoop();
}

void CLI::saveFile() {
	printLine("Enter the file to save to:");
	string input = toLower(getUserString());

	bool exists = controller.fileExists(input);
	if (exists) {
		printLine("File already exists. Overwriting.");
	}

	bool success = controller.saveFile(input);
	if (success) {
		printLine("File saved successfully!");
	} else {
		printLine("Loading Failed!!!");
	}

	runProgramLoop();
}

int CLI::getLength() {
	print("Enter the movie length:");
	string lengthStr = getUserString();
	int length;
	if (isNumber(lengthStr)) {
		length = toInt(lengthStr);
		return length;
	} else {
		printLine("Invalid Length.");
		return getLength();
	}

}

string CLI::getRating() {
	print("Enter the movie rating:");
	string rating = getUserString();
	if (!this->controller.validRating(rating)) {
		printLine("Invalid Rating. Must be either G, PG, PG-13, or R. (case sensitive)");
		return getRating();
	} else {
		return rating;
	}
}

string CLI::getCompany() {
	print("Enter the production company:");
	string company = toLower(getUserString());
	if (company.length() < 1) {
		printLine("Invalid Company.");
		return getCompany();
	} else {
		return company;
	}
}

string CLI::getTitle() {
	print("Enter the movie title:");
	string title = toLower(getUserString());
	if (title.length() < 1) {
		printLine("Invalid Title.");
		return getTitle();
	} else {
		return title;
	}
}

void CLI::insertMovie() {
	string title = getTitle();
	string company = getCompany();
	string rating = getRating();
	int length = getLength();

	bool success = this->controller.addMovie(title, company, length, rating);

	if(success) {
		printLine("Movie added successfully.");
	} else {
		printLine("Movie was not added.");
	}

	runProgramLoop();
}

void CLI::deleteMovie() {
	string title = getTitle();

	bool success = this->controller.deleteMovie(title);

	if(success) {
		printLine("Movie deleted successfully.");
	} else {
		printLine("Movie was not deleted.");
	}

	runProgramLoop();
}

void CLI::alphabetic() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieList(this->controller.getTitleHead(), BY_TITLE, this->controller.getListSize());
}

void CLI::reverseAlphabetic() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieListReversed(this->controller.getTitleHead(), BY_TITLE, this->controller.getListSize());
}

void CLI::ratingAscending() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieListReversed(this->controller.getRatingHead(), BY_RATING, this->controller.getListSize());
}

void CLI::ratingDescending() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieList(this->controller.getRatingHead(), BY_RATING, this->controller.getListSize());
}

void CLI::lengthAscending() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieListReversed(this->controller.getLengthHead(), BY_LENGTH, this->controller.getListSize());
}

void CLI::lengthDescending() {
	if(this->controller.getListSize() == 0) {
		printLine("There are not currently any movies.");
		return;
	}
	printMovieList(this->controller.getLengthHead(), BY_LENGTH, this->controller.getListSize());
}

int CLI::toInt(const string& str) {
	int i;
	stringstream ss(str);
	ss >> i;
	return i;
}

bool CLI::isNumber(const string& s){
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

}
