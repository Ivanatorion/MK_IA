#ifndef ACFIREBOLT_H
#define ACFIREBOLT_H

#include <string>
#include "../../Card.h"

class ACFireBolt : public Card{
	public:
		ACFireBolt();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
