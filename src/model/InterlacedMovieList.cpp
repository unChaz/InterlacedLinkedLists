/*
 * InterlacedMovieList.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#include "InterlacedMovieList.h"
#include "MovieNode.h"
#include "header.h"

namespace model {

/*
 * 0 parameter Constructor.
 */
InterlacedMovieList::InterlacedMovieList() {
	this->pHeadTitle = 0;
	this->pHeadRating = 0;
	this->pHeadLength = 0;
	this->size = 0;
}

/*
 * Destructor
 */
InterlacedMovieList::~InterlacedMovieList() {
	// TODO Auto-generated destructor stub
}

}

/*
 * Inserts a movie in the proper order.
 * param: pointer to a MovieNode
 * precondition: none
 * postcondition: movie is added to the list.
 */
void model::InterlacedMovieList::insertMovie(MovieNode* movie) {
	if (this->size == 0) {
		this->pHeadTitle = movie;
		this->pHeadRating = movie;
		this->pHeadLength = movie;
	} else {
		this->addToList(movie, this->pHeadTitle, BY_TITLE, this->size);
		this->addToList(movie, this->pHeadRating, BY_RATING, this->size);
		this->addToList(movie, this->pHeadLength, BY_LENGTH, this->size);
	}
	this->size++;
}

/**
 * Deletes a movie and adjusts all nodes.
 * param: pointer to a MovieNode
 * precondition: non
 * postcondition: movie is removed from the list.
 */
void model::InterlacedMovieList::deleteMovie(MovieNode* movie) {

}

/*
 * Recursively deletes all movies.
 */
void model::InterlacedMovieList::deleteAllMovieNodes() {

}

/**
 * Adds a movie in the correct order of a list using recursion.
 * Creates a new head if necessary.
 *
 * precondition: none
 *
 * param: movie - the movie to insert
 * param: head - the head of the list to insert into
 * param: method - the method of sorting (BY_TITLE, BY_LENGTH, BY_RATING)
 * param: size - the size of the list.
 */
void model::InterlacedMovieList::addToList(MovieNode* movie, MovieNode* head, const string& method, int size) {
	if (size == 1) {
		int result = compareMovies(head, movie, method);
		if (result > 0 && this->size == 1) {
			replaceHead(head, movie, method);
			return;
		} else {
			insertAfter(head, movie, method);
			return;
		}
	} else {
		MovieNode* next;
		if (method.compare(BY_TITLE) == 0) {
			next = head->getNextTitle();
		} else if (method.compare(BY_LENGTH) == 0) {
			next = head->getNextLength();
		} else {
			next = head->getNextRating();
		}

		int comparedToHead = compareMovies(movie, head, method);
		int comparedToNext = compareMovies(movie, next, method);

		if (size == this->size && comparedToHead == -1) {
			insertAfter(head, movie, method);
		}

		if (isEqualTo(comparedToHead) || (isSmallerThan(comparedToHead) && isBiggerThan(comparedToNext))) {
			insertAfter(head, movie, method);
			return;
		} else {
			addToList(movie, next, method, (size - 1));
			return;
		}
	}
}

bool model::InterlacedMovieList::isBiggerThan(int value) {
	return value == 1;
}

bool model::InterlacedMovieList::isEqualTo(int value) {
	return value == 0;
}

bool model::InterlacedMovieList::isSmallerThan(int value) {
	return value == -1;
}

void model::InterlacedMovieList::insertAfter(MovieNode* existingNode, MovieNode* newNode, const string& method) {
	if (method.compare(BY_TITLE) == 0) {
		MovieNode* nextNode = existingNode->getNextTitle();
		existingNode->setNextTitle(newNode);
		newNode->setPrevTitle(existingNode);
		if (nextNode != 0) {
			nextNode->setPrevTitle(newNode);
			newNode->setNextTitle(nextNode);
		}
	} else if (method.compare(BY_LENGTH) == 0) {
		MovieNode* nextNode = existingNode->getNextLength();
		existingNode->setNextLength(newNode);
		newNode->setPrevLength(existingNode);
		if (nextNode != 0) {
			nextNode->setPrevLength(newNode);
			newNode->setNextLength(nextNode);
		}
	} else {
		MovieNode* nextNode = existingNode->getNextRating();
		existingNode->setNextRating(newNode);
		newNode->setPrevRating(existingNode);
		if (nextNode != 0) {
			nextNode->setPrevRating(newNode);
			newNode->setNextRating(nextNode);
		}
	}
}

void model::InterlacedMovieList::replaceHead(MovieNode* head, MovieNode* movie,
		const string& method) {
	if (method.compare(BY_TITLE) == 0) {
		this->pHeadTitle = movie;
		movie->setNextTitle(head);
	} else if (method.compare(BY_LENGTH) == 0) {
		this->pHeadLength = movie;
		movie->setNextLength(head);
	} else if (method.compare(BY_RATING) == 0) {
		this->pHeadRating = movie;
		movie->setNextRating(head);
	}
}

/*
 * Compares 2 movie nodes by a specific method.
 * Returns:
 *    1 if the first movie is greater than.
 *    -1 if the first movie is less than.
 *    0 if they are equal.
 *    2 if an unknown method was passed.
 */
int model::InterlacedMovieList::compareMovies(MovieNode* movie1,
		MovieNode* movie2, const string& method) {
	if (method.compare(BY_TITLE) == 0) {
		return compareTitle(*movie1, *movie2);
	} else if (method.compare(BY_LENGTH) == 0) {
		return compareLength(*movie1, *movie2);
	} else {
		return compareRating(*movie1, *movie2);
	}
	return 2;
}

int model::InterlacedMovieList::compareTitle(MovieNode movie1,
		MovieNode movie2) {
	string movie1Title = movie1.getTitle();
	string movie2Title = movie2.getTitle();
	int diff = movie1Title.compare(movie2Title);
	if(diff == 0) {
		return 0;
	} else if (diff < 0) {
		return 1;
	} else {
		return -1;
	}
}

int model::InterlacedMovieList::compareLength(MovieNode movie1,
		MovieNode movie2) {
	int movie1Length = movie1.getLength();
	int movie2Length = movie2.getLength();

	if (movie1Length > movie2Length) {
		return 1;
	}  else if (movie1Length == movie2Length) {
		return 0;
	}
	return -1;
}

int model::InterlacedMovieList::compareRating(MovieNode movie1,
		MovieNode movie2) {
	int movie1Rating = getMovieRatingValue(movie1);
	int movie2Rating = getMovieRatingValue(movie1);

	if (movie1Rating > movie2Rating) {
		return 1;
	}  else if (movie1Rating == movie1Rating) {
		return 0;
	}
	return -1;
}

int model::InterlacedMovieList::getMovieRatingValue(MovieNode movie) {
	if (movie.getRating().compare(G)) {
		return 0;
	} else if (movie.getRating().compare(PG)) {
		return 1;
	} else if (movie.getRating().compare(PG13)) {
		return 2;
	} if (movie.getRating().compare(R)) {
		return 3;
	} else {
		return -1;
	}
}

/*
 * Returns whether a movie with the given title already exists in the
 * collection.
 *
 * precondition: none
 *
 * Return: true if the movie exists in the collection.
 */
bool model::InterlacedMovieList::containsMovie(const string& title, MovieNode* head, int size) {
	if(size == 0) {
		return false;
	} if (head->getTitle().compare(title) == 0) {
		return true;
	} else {
		return containsMovie(title, (head + 1), size - 1);
	}
}
