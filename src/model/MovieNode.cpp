/*
 * MovieNode.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */
#include <stdexcept>

#include "header.h"
#include "MovieNode.h"

namespace model {

/*
 * Constructor.
 * precondition: none
 * param: title - name of the movie.
 * param: company - name of the production company
 * param: length - must be greater than 0
 * param: rating - "G", "PG", "PG-13", or "R"
 */
MovieNode::MovieNode(const string& title, const string& company, int length,
		const string& rating) {

	this->title = title;
	this->company = company;
	this->rating = rating;
	this->length = length;

	this->pPrevTitle = 0;
	this->pPrevRating = 0;
	this->pPrevLength = 0;
	this->pNextTitle = 0;
	this->pNextRating = 0;
	this->pNextLength = 0;
}

MovieNode::~MovieNode() {
	// TODO Auto-generated destructor stub
}

bool MovieNode::hasNext(const string& method) {
	if (method.compare(BY_TITLE) == 0) {
		return this->pNextTitle != NULL;
	} else if (method.compare(BY_LENGTH) == 0) {
		return this->pNextLength != NULL;
	} else {
		return this->pNextRating != NULL;
	}
}

}
