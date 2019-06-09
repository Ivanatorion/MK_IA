#ifndef ACAGILITY_H
#define ACAGILITY_H

#include <string>
#include "../../Card.h"

class ACAgility : public Card{
	public:
		ACAgility();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
