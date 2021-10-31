#include<iostream>
#include<string>

#include "image.h"
#include "color.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb_image_write.h"

Image::Image() {
    width = 0;
    height = 0;
    components = 4;
    image = new unsigned char[width*height*components];
}

Image::Image(int wVal, int hVal) {
    width = wVal;
    height = hVal;
    components = 4;
    image = new unsigned char[width*height*components];
}

Image::Image(const char* filename) {
    unsigned char* loadedImage = stbi_load(filename, &width, &height, &components, STBI_rgb_alpha);
    components = 4;
    image = new unsigned char[width*height*components];
    std::copy(loadedImage, loadedImage + width*height*components, image);
    stbi_image_free(loadedImage);
}

Image::~Image() {
    delete[] image;
}

// For some reason I couldn't get my copy constructor to call
// the assignment operator without my program entering an
// some type of infinite recursion then seg faulting.
Image::Image(const Image& img) {
    this->width = img.width;
    this->height = img.height;
    this->components = img.components;
    this->image = new unsigned char[width*height*components];
    for(int i=0; i<width*height*components; i++) {
        this->image[i] = img.image[i];    
    }
}

Image Image::operator=(const Image& img) {
    this->width = img.width;
    this->height = img.height;
    this->components = img.components;
    delete[] image;
    this->image = new unsigned char[width*height*components];
    for(int i=0; i<width*height*components; i++) {
        this->image[i] = img.image[i];    
    }
    return *this;
}

int Image::GetHeight() {
    return height;
}

int Image::GetWidth() {
    return width;
}

int Image::GetComponentNum() {
    return components;
}

Color Image::GetPixel(int x, int y) {
    unsigned char* pixel = &image[(y*width + x)*4];
    Color rgba(pixel[0]/255.0, pixel[1]/255.0, pixel[2]/255.0, pixel[3]/255.0);
    return rgba;
}

void Image::SetPixel(int x, int y, Color& rgba) {
    unsigned char* pixel = &image[(y*width + x)*4];
    pixel[0] = (rgba.Red())*255.0;
    pixel[1] = (rgba.Green())*255.0;
    pixel[2] = (rgba.Blue())*255.0;
    pixel[3] = (rgba.Alpha())*255.0;
}

void Image::SaveAs(const char* filename) {
    stbi_write_png(filename, width, height, components, image, width*4);
}

void Image::Normalize(){
    float r, g, b, a = 0;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            Color temp_pixel = GetPixel(x, y);
            //Color pixel_color (1.0(temp_pixel[0])/255.0, 1.0(temp_pixel[1])/255.0, 1.0(temp_pixel[2])/255.0, 1.0(temp_pixel[3])/255.0);
            if(temp_pixel.Red() > r){r = temp_pixel.Red();}
            if(temp_pixel.Green() > g){g = temp_pixel.Green();}
            if(temp_pixel.Blue() > b){b = temp_pixel.Blue();}
            if(temp_pixel.Alpha() > a){a = temp_pixel.Alpha();}
        }
    }
    Color temp(r, g, b, a);
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            Color pixel_pixel = GetPixel(x, y);

            Color newcolor = pixel_pixel/temp;
            //std::cout<<newcolor.getRed()<<std::endl;
            newcolor.SetAlpha(1);
            SetPixel(x, y, newcolor);
        }
    }
}
