#ifndef ACCONCENTRATION_H
#define ACCONCENTRATION_H

#include <string>
#include "../Card.h"

class ACConcentration : public Card{
	public:
		ACConcentration();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif