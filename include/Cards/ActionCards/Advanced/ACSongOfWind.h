#ifndef ACSONGOFWIND_H
#define ACSONGOFWIND_H

#include <string>
#include "../../Card.h"

class ACSongOfWind : public Card{
	public:
		ACSongOfWind();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
