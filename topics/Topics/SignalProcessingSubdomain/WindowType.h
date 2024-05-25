#ifndef WINDOW_TYPE_ENUM
#define WINDOW_TYPE_ENUM

namespace Topics {
    enum WindowType : uint8_t
    {
        WindowType_rectwin   = 1,
        WindowType_hamming   = 2,
        WindowType_hann      = 3,
        WindowType_blackman  = 4,
        WindowType_gaussian  = 5,
        WindowType_bohman    = 6,
        WindowType_bartlett  = 7,
        WindowType_chebyshev = 8
    };

}

#endif /* WINDOW_TYPE_ENUM */
