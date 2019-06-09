#ifndef ACCRUSHBOLT_H
#define ACCRUSHBOLT_H

#include <string>
#include "../../Card.h"

class ACCrushingBolt : public Card{
	public:
		ACCrushingBolt();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
