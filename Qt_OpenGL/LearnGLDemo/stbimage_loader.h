#ifndef STBIMAGE_LOADER_H
#define STBIMAGE_LOADER_H
#include "global_func.h"
extern unsigned char* stb_image_loader(const char* pImagePath, int &width, int &height, int &nrChannels, int req_comp);
#endif
