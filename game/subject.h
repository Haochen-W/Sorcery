#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"

class Subject{
	std::vector<Observer *> observers;

public:
	Subject() = default;
	virtual ~Subject() = default;

	void attach(Observer *o);
	void notifyObservers();
};

#endif
