/*
 * FileController.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#include "FileController.h"

namespace controller {

FileController::FileController() {
	// TODO Auto-generated constructor stub

}

FileController::~FileController() {
	// TODO Auto-generated destructor stub
}

bool FileController::saveFile(const string& fileName, MovieNode* head, int length) {
	return false;
}

bool FileController::fileExists(const string& fileName) {
	return false;
}

InterlacedMovieList FileController::loadFile(const string& fileName) {
	throw 404;
}

} /* namespace controller */
