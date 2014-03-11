/*
 * MovieNode.h
 *
 *  Created on: Mar 8, 2014
 *      Author: Chaz
 */

#ifndef MOVIENODE_H_
#define MOVIENODE_H_

#include <string>

using namespace std;
/*
 * Contains meta data about a movie.
 *
 * Author: Chaz Ferguson
 * Version: 3-8-2014
 */
namespace model {
class MovieNode {
private:
	string title;
	string company;
	string rating;
	int length;
	MovieNode* pPrevTitle;
	MovieNode* pPrevRating;
	MovieNode* pPrevLength;
	MovieNode* pNextTitle;
	MovieNode* pNextRating;
	MovieNode* pNextLength;
public:
	MovieNode(const string& title, const string& company, int length,
			const string& rating);
	virtual ~MovieNode();
	bool hasNext(const string& method);

	MovieNode* getNextLength() {
		return pNextLength;
	}

	void setNextLength(MovieNode* nextLength) {
		pNextLength = nextLength;
	}

	MovieNode* getNextRating() {
		return pNextRating;
	}

	void setNextRating(MovieNode* nextRating) {
		pNextRating = nextRating;
	}

	 MovieNode* getNextTitle() {
		return pNextTitle;
	}

	void setNextTitle(MovieNode* nextTitle) {
		pNextTitle = nextTitle;
	}

	MovieNode* getPrevLength() {
		return pPrevLength;
	}

	void setPrevLength(MovieNode* prevLength) {
		pPrevLength = prevLength;
	}

	MovieNode* getPrevRating() {
		return pPrevRating;
	}

	void setPrevRating(MovieNode* prevRating) {
		pPrevRating = prevRating;
	}

	MovieNode* getPrevTitle() {
		return pPrevTitle;
	}

	void setPrevTitle(MovieNode* prevTitle) {
		pPrevTitle = prevTitle;
	}

	const string& getCompany() const {
		return company;
	}

	void setCompany(const string& company) {
		this->company = company;
	}

	int getLength() const {
		return length;
	}

	void setLength(int length) {
		this->length = length;
	}

	string& getRating() {
		return rating;
	}

	void setRating(const string& rating) {
		this->rating = rating;
	}

	string& getTitle()  {
		return title;
	}

	void setTitle(const string& title) {
		this->title = title;
	}
};
};

#endif /* MOVIENODE_H_ */
