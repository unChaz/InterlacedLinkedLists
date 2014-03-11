/*
 * ApplicationController.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#ifndef APPLICATIONCONTROLLER_H_
#define APPLICATIONCONTROLLER_H_

#include <iostream>
#include <string>

#include "InterlacedMovieList.h"
#include "FileController.h"

using namespace std;
using namespace model;

/*
 * Controller for the program.
 *
 * Author: Chaz Ferguson
 * Version: 3-8-2014
 */
namespace controller {
class ApplicationController {
private:
	InterlacedMovieList list;
	FileController fc;
public:
	ApplicationController();
	virtual ~ApplicationController();
	void run();
	bool saveFile(const string& fileName);
	bool loadFile(const string& fileName);
	bool fileExists(const string& fileName);
	bool deleteMovie(const string& title);
	bool addMovie(const string& title, const string& company, int length,
			const string& rating);
	bool validRating(const string& rating);
	int getListSize();
	MovieNode* getLengthHead();
	MovieNode* getRatingHead();
	MovieNode* getTitleHead();
};
};

#endif /* APPLICATIONCONTROLLER_H_ */
