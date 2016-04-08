// This provides the frozen (compiled bytecode) files that are included if
// any.
#include <Python.h>

// Blob from which modules are unstreamed.
#if defined(_WIN32) && defined(_NUITKA_EXE)
extern const unsigned char* constant_bin;
#else
extern "C" const unsigned char constant_bin[];
#endif

#define stream_data constant_bin

// These modules should be loaded as bytecode. They may e.g. have to be loadable
// during "Py_Initialize" already, or for irrelevance, they are only included
// in this un-optimized form. These are not compiled by Nuitka, and therefore
// are not accelerated at all, merely bundled with the binary or module, so
// that CPython library can start out finding them.

void copyFrozenModulesTo( void* destination )
{
    _frozen frozen_modules[] = {
        { (char *)"codecs", (unsigned char *)&constant_bin[ 7099835 ], 36107 },
        { (char *)"copy_reg", (unsigned char *)&constant_bin[ 7135942 ], 5050 },
        { (char *)"encodings", (unsigned char *)&constant_bin[ 7140992 ], -4350 },
        { (char *)"encodings.aliases", (unsigned char *)&constant_bin[ 7145342 ], 8757 },
        { (char *)"encodings.ascii", (unsigned char *)&constant_bin[ 7154099 ], 2223 },
        { (char *)"encodings.cp437", (unsigned char *)&constant_bin[ 7156322 ], 8031 },
        { (char *)"encodings.hex_codec", (unsigned char *)&constant_bin[ 7164353 ], 3707 },
        { (char *)"encodings.idna", (unsigned char *)&constant_bin[ 7168060 ], 6326 },
        { (char *)"encodings.mbcs", (unsigned char *)&constant_bin[ 7174386 ], 1995 },
        { (char *)"encodings.utf_8", (unsigned char *)&constant_bin[ 7176381 ], 1918 },
        { (char *)"functools", (unsigned char *)&constant_bin[ 7178299 ], 5951 },
        { (char *)"locale", (unsigned char *)&constant_bin[ 7184250 ], 54920 },
        { (char *)"re", (unsigned char *)&constant_bin[ 7239170 ], 13299 },
        { (char *)"sre_compile", (unsigned char *)&constant_bin[ 7252469 ], 12476 },
        { (char *)"sre_constants", (unsigned char *)&constant_bin[ 7264945 ], 6162 },
        { (char *)"sre_parse", (unsigned char *)&constant_bin[ 7271107 ], 19387 },
        { (char *)"stringprep", (unsigned char *)&constant_bin[ 7290494 ], 14381 },
        { (char *)"types", (unsigned char *)&constant_bin[ 7304875 ], 2468 },
        { NULL, NULL, 0 }
    };

    memcpy(
        destination,
        frozen_modules,
        ( _NUITKA_FROZEN + 1 ) * sizeof( struct _frozen )
    );
}
