#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "gif_lib.h"

#define ENABLE_COLOR_TABLE 0
#define ENABLE_FRAME_INFO 0
#define ENABLE_EXTENSION_INFO 0

#define FRAME_NUMBER 10
#define ENABLE_FRAME_PIXEL_MAP 1
#define ENABLE_FRAME_PIXEL_DRAW 1

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "E: no arguments" << std::endl;
    exit(1);
  }

  GifFileType* fGIF = DGifOpenFileName(argv[1], nullptr);

  if (DGifSlurp(fGIF) != GIF_OK) {
    std::cout << "GIF Open Failed.\n";
    DGifCloseFile(fGIF, nullptr);
    fGIF = nullptr;
  }

  // Default Info
  std::cout << "============================================================="
               "==================="
            << std::endl;
  std::cout << "Width: " << fGIF->SWidth << ", Height: " << fGIF->SHeight
            << "\n"
            << "Image Count: " << fGIF->ImageCount << "\n";

  // ColorMap Info
  auto cm = fGIF->SColorMap;
#if ENABLE_COLOR_TABLE
  std::cout << "============================================================="
               "===================\n"
            << "Background color: " << fGIF->SBackGroundColor << std::endl;
  std::cout << "Has ColorMap? :" << (cm ? "true" : "false") << std::endl;
  if (cm) {
    std::cout << "ColorCount: " << cm->ColorCount
              << ", BitsPerPixel: " << cm->BitsPerPixel << ", Sorted? "
              << std::boolalpha << cm->SortFlag << std::endl;

    std::cout << "============================================================="
                 "==================="
              << std::endl;
    for (int i = 1; i <= cm->ColorCount; i++) {
      const auto& c = *(cm->Colors + i);
      std::cout << "[" << std::setfill('0') << std::setw(2) << i << "]: #"
                << std::hex << std::setfill('0') << std::setw(2) << (int)c.Red
                << std::setfill('0') << std::setw(2) << (int)c.Green
                << std::setfill('0') << std::setw(2) << (int)c.Red << "   "
                << std::dec;
      if (i % 5 == 0) std::cout << "\n";
    }
    std::cout << "\n"
              << "============================================================="
                 "==================="
              << std::endl;
  }
#endif

#if ENABLE_FRAME_INFO
  // Duration Info
  std::cout << std::setfill(' ') << std::left  //
            << std::setw(10) << "| Frame"      //
            << std::setw(11) << "| Dur(ms)"    //
            << std::setw(8) << "| Exts"        //
            << std::setw(12) << "| Interlace"  //
            << std::setw(12) << "| ColorMap"   //
            << std::setw(12) << "| RasterBit"  //
            << std::setw(14) << "| LTWH"       //
            << std::endl;

  int duration = 0;
  for (int i = 0; i < fGIF->ImageCount; i++) {
    auto& image = fGIF->SavedImages[i];

    std::cout << "| " << std::setw(8) << std::left << i;
    for (int j = 0; j < image.ExtensionBlockCount; j++) {
      if (image.ExtensionBlocks[j].Function == GRAPHICS_EXT_FUNC_CODE) {
        if (image.ExtensionBlocks[j].ByteCount < 4) {
          std::cerr << "E: Somethings wrong with GRAPHICS_EXT_FUNC_CODE bytes.";
          return 0;
        }
        const uint8_t* b = (const uint8_t*)image.ExtensionBlocks[j].Bytes;
        auto time = ((b[2] << 8) | b[1]) * 10;
        duration += time;
        std::cout << "| " << std::setw(9) << std::left << time;
      }
    }
    const auto desc = image.ImageDesc;

    std::cout << "| " << std::setw(6) << image.ExtensionBlockCount        //
              << "| " << std::setw(10) << desc.Interlace                  //
              << "| " << std::setw(10) << (desc.ColorMap ? true : false)  //
              << "| " << std::setw(10) << (int)*image.RasterBits          //
              << "| " << desc.Left << ", " << desc.Top << ", " << desc.Width
              << "," << desc.Height << std::endl;
  }
  std::cout << "\nTotal duration: " << duration << " ms" << std::endl;
  std::cout << "============================================================="
               "==================="
            << std::endl;
#endif

  int n, h, w, bg;
#if ENABLE_FRAME_PIXEL_MAP
  // Draw next frame rect with color index
  n = FRAME_NUMBER;
  auto& image = fGIF->SavedImages[n];
  h = image.ImageDesc.Height;
  w = image.ImageDesc.Width;
  std::cout << "============================================================="
               "==================="
            << std::endl;
  std::cout << "Frame number " << n << std::endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cout << std::left << std::setw(3) << std::setfill(' ') << std::hex
                << (int)*(image.RasterBits + j + i * w);
    }
    std::cout << "\n";
  }
#endif

#if ENABLE_FRAME_PIXEL_DRAW
  // Draw next frame rect with color
  n = FRAME_NUMBER;
  auto& dImage = fGIF->SavedImages[n];
  h = dImage.ImageDesc.Height;
  w = dImage.ImageDesc.Width;
  bg = fGIF->SBackGroundColor;

  std::cout << "============================================================="
               "==================="
            << std::endl;
  std::cout << "Frame number " << std::dec << n << std::endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int k = dImage.RasterBits[j + i * w];
      auto& c = cm->Colors[k];

      if (k == bg)
        std::cout << " ";
      else
        // std::cout << colorize(*((cm->Colors) + c)) << "*";
        std::cout << "\033[38;2;" << (int)c.Red << ";" << (int)c.Green << ";"
                  << (int)c.Blue << "m● ";
    }
    std::cout << "\n";
  }
  std::cout << "\033[38;2;255;255;255m";

#endif
  std::cout << "============================================================="
               "==================="
            << std::endl;

  return 0;
}
