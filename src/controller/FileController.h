/*
 * FileController.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#ifndef FILECONTROLLER_H_
#define FILECONTROLLER_H_

#include <string>

#include "InterlacedMovieList.h"

using namespace std;
using namespace model;

namespace controller {

class FileController {
public:
	FileController();
	virtual ~FileController();
	bool saveFile(const string& fileName, MovieNode* head, int length);
	bool fileExists(const string& fileName);
	InterlacedMovieList loadFile(const string& fileName);
};

} /* namespace controller */
#endif /* FILECONTROLLER_H_ */
