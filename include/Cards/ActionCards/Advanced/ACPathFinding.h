#ifndef ACPATHFINDING_H
#define ACPATHFINDING_H

#include <string>
#include "../../Card.h"

class ACPathFinding : public Card{
	public:
		ACPathFinding();
		void playCardWeak(STATE *s);
		void playCardStrong(STATE *s);
		std::string getName();

	private:

};

#endif
