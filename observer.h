#ifndef observer_h
#define observer_h

class Cell;

class Observer {
 public:
  virtual void notify(Cell &whoFrom) = 0;
  virtual ~Observer() = default;
};

#endif
