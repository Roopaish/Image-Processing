// Basic way of creating a image

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

     // Looping through all pixels of the image in y and x axis
    for(int y = 0; y < 500; y++){
      for(int x = 0; x < 500; x++){
        image << (x * y) % 255 << " " << x << " " << (x + y) % 255 << " "; // place pixel info
      }
      image << endl;
    }
  }

  image.close(); // close the file

  return 0;
}