#ifndef WOUNDCARD_H
#define WOUNDCARD_H

#include <string>
#include "Card.h"

class Wound : public Card{
	public:
		Wound();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
