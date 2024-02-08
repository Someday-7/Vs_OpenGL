#ifndef STBIMAGE_LOADER_H
#define STBIMAGE_LOADER_H
#define STB_IMAGE_IMPLEMENTATION
extern unsigned char* stb_image_loader(const char* pImagePath, int &width, int &height, int &nrChannels, int req_comp);
#endif
