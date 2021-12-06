#include "imageio/iimage.h"
#include "imageio/image.h"
#include "gtest/gtest.h"
#include "imageio/filter.h"

using namespace imageio;

class ImageTest : public ::testing::Test {
public:
    void SetUp() {
        
    }
protected:
    Image image;
};

TEST_F(ImageTest, LoadCorrect) {
    Image image;
    image.Load("./green.png");
    Color pixel = image.GetPixel(0, 0);
    EXPECT_EQ(pixel.Green(), 255);
}

TEST_F(ImageTest, TestClone) {
    Image image;
    image.Load("./green.png");
    IImage* clone = image.Clone();
    for (int x=0; x < clone->GetWidth(); x++) {
        for( int y=0; y < clone->GetHeight(); y++) {
            Color pixel = clone->GetPixel(x, y);
            // Make sure image is green
            EXPECT_EQ(pixel.Green(), 255);
            EXPECT_EQ(pixel.Red(), 0);
            EXPECT_EQ(pixel.Blue(), 0);            
        }
    }
}

TEST_F(ImageTest, ColorCorrect) {
    Image image;
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


