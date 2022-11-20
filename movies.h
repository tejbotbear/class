#include <iostream>
#include <cstring>

using namespace std;

class Movies : public Media {
 public:
  int duration;
  int rating;
  char director[100];

  void PrintOutput() {
    cout << "----------------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Duration: " << duration << endl;
    cout << "Rating: " << rating << endl;
    cout << "Director: " << director << endl;
  }

};
