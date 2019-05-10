#ifndef ACTRANQUILITY_H
#define ACTRANQUILITY_H

#include <string>
#include "../Card.h"

class ACTranquility : public Card{
	public:
		ACTranquility();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif