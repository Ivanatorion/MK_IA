#ifndef ACCRYSTALLIZE_H
#define ACCRYSTALLIZE_H

#include <string>
#include "../Card.h"

class ACCrystallize : public Card{
	public:
		ACCrystallize();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif