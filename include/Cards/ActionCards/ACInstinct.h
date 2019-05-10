#ifndef ACINSTINCT_H
#define ACINSTINCT_H

#include <string>
#include "../Card.h"

class ACInstinct : public Card{
	public:
		ACInstinct();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif