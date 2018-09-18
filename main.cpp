#include <iostream>
#include <sstream>
#include <fstream>

#include <vector> //hmmm what's this maybe this is useful

using namespace std;

struct Pixel {
 //hmm this could be useful but who knows
 int r;
 int g;
 int b;
};

int main() {
  int width = 0;
  int height = 0;

  ifstream in;
  in.open("in.data", ios::in);

  if(in.is_open()) {
    string line;
    getline(in, line); //stores a line in line
    width = stoi(line);

    getline(in, line);
    height = stoi(line);

    //TODO set up data structures
    // maybe a 2d vector would be useful?

    while(getline(in, line)){  //reads a line at a time

      //TODO read in pixel data
      
    }

    in.close();  
  }



  cout << "Width = " << width << endl;
  cout << "Height = " << height << endl;

  ofstream out;
  out.open("out.ppm", ios::out);
  if(out.is_open()) {
    out << "P3" << endl;
    out << width << " " << height << endl; 
    out << 255 << endl;

    //TODO writing your pixel data in npm form
    
    out.close();
  }
}
