#include "image.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // Step 1:
    // Create an image by loading in "data/statue.png"
    Image statue("data/statue.png");
    cout << "Height: " << statue.GetHeight() << " Width: " << statue.GetWidth() << endl;
    //Save the image as "data/statue_copy.png"
    statue.SaveAs("data/statue_copy.png");

    // Step 2:
    // Create an image of size 256 x 256.
    Image step2 = Image(256, 256);
    for(int x=0; x<step2.GetWidth(); x++) {
        for(int y=0; y<step2.GetHeight(); y++) {
            // Set each pixel to Red or [1, 0, 0, 1] => [red, green, blue, alpha]
            unsigned char* pixel = step2.GetPixel(x, y);
            int rgba[4] = {255, 0, 0, 255};
            step2.SetPixel(x, y, pixel, rgba);
        }
    }
    // Save the image as "data/red.png"
    step2.SaveAs("data/red.png");

    // Step 3:
    // Create an image of size 256 x 32
    Image step3 = Image(256, 32);
    for(int x=0; x<step3.GetWidth(); x++) {
        for(int y=0; y<step3.GetHeight(); y++) {
            // Edit the image to create a gradient
            unsigned char* pixel = step3.GetPixel(x, y);
            int rgba[4] = {0, x, 0, 255};
            step3.SetPixel(x, y, pixel, rgba);
        }
    }
    // Save the image as "data/green_gradient.png"
    step3.SaveAs("data/green_gradient.png");

    return 0;
}