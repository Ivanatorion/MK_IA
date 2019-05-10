#ifndef ACPROMISE_H
#define ACPROMISE_H

#include <string>
#include "../Card.h"

class ACPromise : public Card{
	public:
		ACPromise();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif