#ifndef ACINTIMIDATE_H
#define ACINTIMIDATE_H

#include <string>
#include "../../Card.h"

class ACIntimidate : public Card{
	public:
		ACIntimidate();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
