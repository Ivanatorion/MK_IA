#ifndef ACICESHIELD_H
#define ACICESHIELD_H

#include <string>
#include "../../Card.h"

class ACIceShield : public Card{
	public:
		ACIceShield();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
