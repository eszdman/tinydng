
#define TINY_DNG_LOADER_IMPLEMENTATION
#include "../../tiny_dng_loader.h"

#define TINY_DNG_WRITER_IMPLEMENTATION
#include "tiny_dng_writer.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

int
main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << argv[0] << " input.dng output.dng" << std::endl;
    return EXIT_FAILURE;
  }

  
  tinydngwriter::DNGWriter dng_writer;
  unsigned int image_width = 512;
  dng_writer.SetField(tinydngwriter::TIFFTAG_IMAGEWIDTH, reinterpret_cast<const unsigned char*>(&image_width));

  std::string err;
  bool ret = dng_writer.Write("output.dng", &err);

  if (!err.empty()) {
    std::cerr << err;
  }

  if (!ret) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}