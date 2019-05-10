#ifndef ACMANADRAW_H
#define ACMANADRAW_H

#include <string>
#include "../Card.h"

class ACManaDraw : public Card{
	public:
		ACManaDraw();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif