#include<iostream>
#include<string>

#ifndef IMAGE_H_
#define IMAGE_H_

class Image {
private:
    int width;
    int height;
    int components;
    unsigned char* image;

public:
    Image(int width, int height);
    Image(const char* filename);
    Image(const Image& img);
    Image operator=(const Image& img);
    ~Image();
    int GetHeight();
    int GetWidth();
    int GetComponentNum();
    unsigned char* GetPixel(int x, int y);
    void SetPixel(int x, int y, unsigned char* pixel, const int* rgba);
    void SaveAs(const char* filename);
    void swap(Image& first, Image& second);
};

#endif