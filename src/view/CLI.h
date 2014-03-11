/*
 * CLI.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#ifndef CLI_H_
#define CLI_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include "stdlib.h"
#include "MovieNode.h"
#include "ApplicationController.h"
#include "header.h"

using namespace std;
using namespace controller;

/*
 * Command Line Interface for the program.
 *
 * Author: Chaz Ferguson
 * Version: 3-8-2014
 */
namespace view {

class CLI {
private:
	ApplicationController controller;
	void printMovieList(model::MovieNode* head, const string& method, int size);
	void printMovieListReversed(model::MovieNode* head, const string& method, int size);
	string getUserString();
	void printLine(const string& message);
	void print(const string& message);
	bool stringEquals(const string& string1, const string& string2);
	void loadFile();
	void saveFile();
	void insertMovie();
	void deleteMovie();
	void alphabetic();
	void reverseAlphabetic();
	void ratingAscending();
	void ratingDescending();
	void lengthAscending();
	void lengthDescending();
	bool isNumber(const string& str);
	int getLength();
	string getRating();
	string getCompany();
	string getTitle();
	void printMovie(model::MovieNode* head);

public:
	CLI();
	virtual ~CLI();
	void runProgramLoop();
	void printWelcome();
	void printFarewell();
	string toLower(const string& str);
	int toInt(const string& str);
};

};
#endif /* CLI_H_ */
