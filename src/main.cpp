#include <iostream>
#include <windef.h>
#include <rpc.h>
#include "CImg.h"

int main() {
    const unsigned short
            x = static_cast<const unsigned short>(GetSystemMetrics(SM_CXSCREEN )),
            y = 0;

    cimg_library::CImgDisplay imgDisplay(GetSystemMetrics(SM_CXVIRTUALSCREEN) - GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Curtain", 3, /*is_fullscreen*/ true);
    cimg_library::CImg<unsigned char> image(
            (const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);

    imgDisplay.move(x, y);

    do {
        imgDisplay.wait();
        if (imgDisplay.is_keyESC() || imgDisplay.is_keyQ()) {
            imgDisplay.close();
        }
    } while(!imgDisplay.is_closed());

    return 0;
}
