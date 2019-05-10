#ifndef ACCOLDTOUGHNESS_H
#define ACCOLDTOUGHNESS_H

#include <string>
#include "../Card.h"

class ACColdToughness : public Card{
	public:
		ACColdToughness();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif