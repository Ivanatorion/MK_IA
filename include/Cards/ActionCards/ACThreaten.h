#ifndef ACTHREATEN_H
#define ACTHREATEN_H

#include <string>
#include "../Card.h"

class ACThreaten : public Card{
	public:
		ACThreaten();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif