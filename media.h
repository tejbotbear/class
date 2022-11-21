#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  char* title;
  int year;

  Media() {
    title = new char[100];
  }

  ~Media() {
    delete title;
  }
};
