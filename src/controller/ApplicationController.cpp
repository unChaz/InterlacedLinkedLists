/*
 * ApplicationController.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#include "ApplicationController.h"

#include "header.h"

namespace controller {

/*
 * Default Constructor.
 */
ApplicationController::ApplicationController() {
	this->list = InterlacedMovieList();
	this->fc = FileController();
}

/*
 * destructor
 */
ApplicationController::~ApplicationController() {
	this->list.deleteAllMovieNodes();
}

/*
 * Saves a file containing all the movies to a specified filename.
 * Overwrites the file if it exists.
 * precondition: none
 * return: true if the file saved successfully.
 * postcondition: the file is saved.
 */
bool ApplicationController::saveFile(const string& fileName) {
	return fc.saveFile(fileName, this->getTitleHead(), this->getListSize());
}

/*
 * Loads a file containing movies from a specified filename.
 * precondition: none
 * return: true if the file loaded successfully. False if there
 * was an I/O error.
 * postcondition: the movies are loaded into the InterlacedMovieList.
 */
bool ApplicationController::loadFile(const string& fileName) {
	try {
		this->list = fc.loadFile(fileName);
		return true;
	} catch(int e) {
		return false;
	}
}

/*
 * Deletes a movie from the list.
 * precondition: none
 * return: true if the file deletes successfully. False if the movie
 * does not exist.
 * postcondition: movie does not exist in the collection.
 */
bool ApplicationController::deleteMovie(const string& title) {
	return false;
}

/*
 * Adds a movie to the collection.
 * precondition: none
 * return: true if the movie was added successfully. false if a movie with that
 * title already exists.
 * postcondition: the movie is added to the doubly linked lists.
 */
bool ApplicationController::addMovie(const string& title, const string& company,
		int length, const string& rating) {

	if(length < 0) {
		return false;
	}
	if (!validRating(rating)) {
		return false;
	}
	if(company.length() <= 0) {
		return false;
	}
	if(title.length() <= 0) {
		return false;
	}

	/*
	if (getListSize() > 0 && list.containsMovie(title, getTitleHead(), getListSize())) {
		return false;
	}
	*/

	MovieNode* movie = new MovieNode(title, company, length, rating);
	this->list.insertMovie(movie);

	return true;
}

/*
 * Checks if the given string is a valid movie rating.
 * param: rating - a string
 * return: true if the rating is G, PG, PG-13, or R.
 */
bool ApplicationController::validRating(const string& rating) {
	if(rating.compare(G) == 0) {
		return true;
	} else if(rating.compare(PG) == 0) {
		return true;
	} else if(rating.compare(PG-13) == 0) {
		return true;
	} else if(rating.compare(R) == 0) {
		return true;
	} else {
		return false;
	}
}

/*
 * returns the size of the list.
 */
int ApplicationController::getListSize() {
	return this->list.getSize();
}

/*
 * returns the head of the length list.
 */
MovieNode* ApplicationController::getLengthHead() {
	return this->list.getHeadLength();
}

/*
 * returns the head of the rating list.
 */
MovieNode* ApplicationController::getRatingHead() {
	return this->list.getHeadRating();
}

/*
 * returns the head of the title list.
 */
MovieNode* ApplicationController::getTitleHead() {
	return this->list.getHeadTitle();
}

/*
 * Checks to see if the file exists.
 */
bool ApplicationController::fileExists(const string& fileName) {
	return fc.fileExists(fileName);
}

}


/*
 * DELETE ME!! TESTING ONLY!
 */
void controller::ApplicationController::run() {
	bool added = addMovie("Fargo", "20th Century Fox", 120, "R");
	added = addMovie("Batman", "20th Century Fox", 120, "R");
	added = addMovie("Aladdin", "Doesn't Matter", 110, "G");
	added = addMovie("Zelda", "Paramount", 130, "PG");
	added = addMovie("Mama Mia", "20th Century Fox", 99, "PG-13");

}
