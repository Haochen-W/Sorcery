#ifndef SUBJECT_H
#define SUBJECT_H

class Subject{
  std::vector<observer *> observers;

public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
};

#endif
