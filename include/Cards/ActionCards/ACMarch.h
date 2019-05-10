#ifndef ACMARCH_H
#define ACMARCH_H

#include <string>
#include "../Card.h"

class ACMarch : public Card{
	public:
		ACMarch();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif