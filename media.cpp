#include <cstring>
#include <iostream>
#include "media.h"
#include "movies.h"
#include "music.h"
#include "videogames.h"

using namespace std;

Media::Media() {
  cout << "hi" << endl;
}

char* Media::getTitle() {
  cout << "title" << endl;
  return 0;
}

int Media::getYear() {
  cout << "test year" << endl;
  return 0;
}
