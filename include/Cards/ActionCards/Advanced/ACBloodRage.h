#ifndef ACBLOODRAGE_H
#define ACBLOODRAGE_H

#include <string>
#include "../../Card.h"

class ACBloodRage : public Card{
	public:
		ACBloodRage();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
