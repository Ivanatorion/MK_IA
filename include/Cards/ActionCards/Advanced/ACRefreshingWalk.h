#ifndef ACRFSWALK_H
#define ACRFSWALK_H

#include <string>
#include "../../Card.h"

class ACRefreshingWalk : public Card{
	public:
		ACRefreshingWalk();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
