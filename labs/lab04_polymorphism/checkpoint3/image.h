#include<iostream>
#include<string>

#include "color.h"

#ifndef IMAGE_H_
#define IMAGE_H_

class Image {
private:
    int width;
    int height;
    int components;
    unsigned char* image;

public:
    Image();
    Image(int width, int height);
    Image(const char* filename);
    Image(const Image& img);
    Image operator=(const Image& img);
    ~Image();
    int GetHeight();
    int GetWidth();
    int GetComponentNum();
    unsigned char* GetPixel(int x, int y);
    void SetPixel(int x, int y, unsigned char* pixel, const float rgba[3]);
    void SaveAs(const char* filename);
    void swap(Image& first, Image& second);
};

#endif