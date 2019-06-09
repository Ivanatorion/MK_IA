#ifndef ACSWIFTBOLT_H
#define ACSWIFTBOLT_H

#include <string>
#include "../../Card.h"

class ACSwiftBolt : public Card{
	public:
		ACSwiftBolt();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
