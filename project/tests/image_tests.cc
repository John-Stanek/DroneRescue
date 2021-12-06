#include "imageio/iimage.h"
#include "imageio/image.h"
#include "gtest/gtest.h"

using namespace imageio;

class ImageTest : public ::testing:Test {
public:
    void SetUp() {
        
    }
protected:
    Image image;
};

TEST_F(ImageTest, TestClone) {
    image.Load("./green.png");
    Image* clone;
    clone = image.Clone();
    for (int x=0; x < clone.GetWidth(); x++) {
        for( int y=0; y < clone.GetHeight(); y++) {
            Color pixel = clone.GetPixel(x, y);
            // Make sure image is green
            EXPECT_EQ(pixel.Green(), 255);
            EXPECT_EQ(pixel.Red(), 0);
            EXPECT_EQ(pixel.Blue(), 0);            
        }
    }
}

TEST_F(ImageTest, ColorCorrect) {
    image.Load("./green.png");
    for (int x=0; x < image.GetWidth(); x++) {
        for( int y=0; y < image.GetHeight(); y++) {
            Color pixel = image.GetPixel(x, y);
            // RGB for green should be (0, 255, 0).
            EXPECT_EQ(pixel.Green(), 255);
            EXPECT_EQ(pixel.Red(), 0);
            EXPECT_EQ(pixel.Blue(), 0);
        }
    }
}



