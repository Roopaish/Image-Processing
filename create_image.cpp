#include<iostream>
#include<fstream>

using namespace std;

int main(){
  ofstream image; // declare an output file stream object
  image.open("image.ppm"); // open the file

  if(image.is_open()){
    // place header info
    image << "P3" << endl; // ppm format
    image << "500 500" << endl; // width and height
    image << "255" << endl; // max color value

  }

  image.close(); // close the file

  return 0;
}