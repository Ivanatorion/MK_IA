#ifndef ACFROSTBRIDGE_H
#define ACFROSTBRIDGE_H

#include <string>
#include "../../Card.h"

class ACFrostBridge : public Card{
	public:
		ACFrostBridge();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
