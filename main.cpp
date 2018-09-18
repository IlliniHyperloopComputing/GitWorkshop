#include <iostream>
#include <sstream> // oh stringstream that's neat maybe that's convenient
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

  Pixel colorsMat [125][125];

  ifstream in;
  in.open("in.data", ios::in);

  if(in.is_open()) { //if the file is open
    string line;
    getline(in, line); //stores a line in line
    width = stoi(line);

    getline(in, line);
    height = stoi(line);

    //TODO set up data structures
    // maybe a 2d vector would be useful?

    while(getline(in, line)){  //reads a line at a time

      //TODO read in pixel data
      //cout << "Line = " << line << endl;
      
      stringstream stream (line);

      int x;
      int y;
      int r;
      int g;
      int b;

      stream >> x;
      stream >> y;
      stream >> r;
      stream >> g;
      stream >> b;

      Pixel tempPixel = {r,g,b};

      colorsMat[x][y] = tempPixel;

      //cout << "R = " << tempPixel.r << endl;
      //cout << "G = " << tempPixel.g << endl;
      //cout << "B = " << tempPixel.b << endl;


    }

    cout << "Width = " << width << endl; //Print to console
    cout << "Height = " << height << endl;

    ofstream out;
    out.open("out.ppm", ios::out);
    if(out.is_open()) { //if the file is open
      cout << "P3" << endl; //write to file
      cout << width << " " << height << endl; 
      cout << 255 << endl;

      //TODO writing your pixel data in ppm form
      
      //cout << "test" << endl;
      for( int x = 0; x < 125; x = x + 1 ) {
          for( int y = 0; y < 125; y = y + 1 ) {
          cout << colorsMat[x][y].r << " " <<  colorsMat[x][y].g <<  " " <<  colorsMat[x][y].b << " ";
        }
        cout << endl;
      }


      out.close();
    }
    in.close();  
  }



}
