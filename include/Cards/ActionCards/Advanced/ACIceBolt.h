#ifndef ACICEBOLT_H
#define ACICEBOLT_H

#include <string>
#include "../../Card.h"

class ACIceBolt : public Card{
	public:
		ACIceBolt();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
