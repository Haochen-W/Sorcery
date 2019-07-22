#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "minion.h"

class Decorator: public Minion {
protected:
	Minion * component;
public:
	Decorator(Minion * component);
	virtual ~Decorator();
};

#endif
