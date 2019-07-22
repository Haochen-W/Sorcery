#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "minion.h"

class Decorator: public Minion {
protected:
	Minion * component;
	Minion * prevComponent
public:
	Decorator(Minion * component, Minion * prevComponent);
	// virtual ~Decorator(); ??

	Minion * unwrap(); // unwrap one step, return prevComponent
};

#endif
