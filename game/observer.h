#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Player;

class Observer {
public:
	virtual ~Observer() = default;
	virtual void notify(Player & whoNotified) = 0;
};

#endif
