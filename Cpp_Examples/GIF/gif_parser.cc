#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "gif_lib.h"

int main(int argc, char** argv) {
  if(argc < 2) {
    std::cout<< "E: no arguments"<< std::endl;
    exit(1);
  }


  GifFileType* fGIF = DGifOpenFileName(argv[1], nullptr);

  if (DGifSlurp(fGIF) != GIF_OK) {
    std::cout << "GIF Open Failed.\n";
    DGifCloseFile(fGIF, nullptr);
    fGIF = nullptr;
  }

  // Default Info
  std::cout << "Width: " << fGIF->SWidth << ", Height: " << fGIF->SHeight
            << "\n"
            << "Image Count: " << fGIF->ImageCount << "\n"
            << "Background color: " << fGIF->SBackGroundColor << std::endl;

  // ColorMap Info
  auto cm = fGIF->SColorMap;
  std::cout << "Has ColorMap? :" << (cm ? "true" : "false") << std::endl;
  if (cm) {
    std::cout << "ColorCount: " << cm->ColorCount
              << ", BitsPerPixel: " << cm->BitsPerPixel << ", Sorted? "
              << std::boolalpha << cm->SortFlag << std::endl;
    for (int i = 0; i < cm->ColorCount; i++) {
      const auto& c = *(cm->Colors + i);

      std::cout << std::setw(5) << "Color[" << i << "]: " << (int)c.Red << ", "
                << (int)c.Green << ", " << (int)c.Red << "   ";
      if (i % 5 == 0) std::cout << "\n";
    }
  }

  // Duration Info
  int duration = 0;
  for (int i = 0; i < fGIF->ImageCount; i++) {
    auto& image = fGIF->SavedImages[i];
    std::cout << "Frame[" << i << "] - ";
    for (int j = 0; j < image.ExtensionBlockCount; j++) {
      if (image.ExtensionBlocks[j].Function == GRAPHICS_EXT_FUNC_CODE) {
        if (image.ExtensionBlocks[j].ByteCount < 4) {
          std::cerr << "E: Somethings wrong with GRAPHICS_EXT_FUNC_CODE bytes.";
          return 0;
        }
        const uint8_t* b = (const uint8_t*)image.ExtensionBlocks[j].Bytes;
        auto time = ((b[2] << 8) | b[1]) * 10;
        std::cout << "duration: " << time;
        duration += time;
      } else {
        std::cout << "ext:" << (int)image.ExtensionBlocks[j].Function << "("
                  << image.ExtensionBlocks[j].ByteCount << ")";
      }
    }

    std::cout << ", extension count: " << image.ExtensionBlockCount;

    const auto desc = image.ImageDesc;

    std::cout << ", interlace?: " << desc.Interlace;
    std::cout << ", hasColorMap?: " << (desc.ColorMap ? true : false);
    std::cout << ", LTWH: " << desc.Left << "," << desc.Top << "," << desc.Width
              << "," << desc.Height;

    std::cout << ", RasterBit: " << (int)*image.RasterBits;

    std::cout << std::endl;
  }
  std::cout << "Total duration: " << duration << " ms" << std::endl;

  // Frame index to draw
  int n = 0;

  // Draw next frame rect with color index
  {
    auto& image = fGIF->SavedImages[n];
    int h = image.ImageDesc.Height;
    int w = image.ImageDesc.Width;

    std::cout << "\nFrame number " << n << std::endl;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        std::cout << std::setw(4) << (int)*(image.RasterBits + j + i * w);
      }
      std::cout << "\n";
    }
  }

  // Draw next frame rect with color
  {
    auto& image = fGIF->SavedImages[n];
    int h = image.ImageDesc.Height;
    int w = image.ImageDesc.Width;
    int bg = fGIF->SBackGroundColor;

    std::cout << "\nFrame number " << n << std::endl;
    std::cout << "##########################################################\n";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int k = image.RasterBits[j + i * w];
        auto& c = cm->Colors[k];

        if (k == bg)
          std::cout << " ";
        else
          // std::cout << colorize(*((cm->Colors) + c)) << "*";
          std::cout << "\033[38;2;" << (int)c.Red << ";" << (int)c.Green << ";"
                    << (int)c.Blue << "m*";
      }
      std::cout << "\n";
    }
    std::cout << "\033[38;2;255;255;255m";
    std::cout << "##########################################################\n";
  }

  return 0;
}
