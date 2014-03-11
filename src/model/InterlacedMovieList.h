/*
 * InterlacedMovieList.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#ifndef INTERLACEDMOVIELIST_H_
#define INTERLACEDMOVIELIST_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include "stdlib.h"
#include "MovieNode.h"

using namespace std;
/*
 * Organizes movies into a doubly linked list by title, rating and length.
 *
 * Author: Chaz Ferguson
 * Version: 3-8-2014
 */
namespace model {
class InterlacedMovieList {
private:
	MovieNode* pHeadTitle;
	MovieNode* pHeadRating;
	MovieNode* pHeadLength;
	int size;
	void addToList(MovieNode* movie, MovieNode* head, const string& method, int size);
	int compareTitle(MovieNode movie1, MovieNode movie2);
	int compareLength(MovieNode movie1, MovieNode movie2);
	int compareRating(MovieNode movie1, MovieNode movie2);
	int getMovieRatingValue(MovieNode movie);
	void insertHere(MovieNode* last, MovieNode* current, MovieNode* next, const string& method);
	void replaceHead(MovieNode* head, MovieNode* movie, const string& method);
public:
	InterlacedMovieList();
	virtual ~InterlacedMovieList();
	void insertMovie(MovieNode* movie);
	void deleteMovie(MovieNode* movie);
	void deleteAllMovieNodes();
	int compareMovies(MovieNode* movie1, MovieNode* movie2,
			const string& method);
	bool containsMovie(const string& title, MovieNode* head, int size);

	MovieNode* getHeadLength() const {
		return pHeadLength;
	}

	MovieNode* getHeadRating() const {
		return pHeadRating;
	}

	MovieNode* getHeadTitle() const {
		return pHeadTitle;
	}

	int getSize() const {
		return size;
	}
};
};

#endif /* INTERLACEDMOVIELIST_H_ */
