
#ifndef JPEG2KCODEC_EXPORT_H
#define JPEG2KCODEC_EXPORT_H

#ifdef JPEG2KCODEC_STATIC_DEFINE
#  define JPEG2KCODEC_EXPORT
#  define JPEG2KCODEC_NO_EXPORT
#else
#  ifndef JPEG2KCODEC_EXPORT
#    ifdef jpeg2kcodec_EXPORTS
        /* We are building this library */
#      define JPEG2KCODEC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define JPEG2KCODEC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef JPEG2KCODEC_NO_EXPORT
#    define JPEG2KCODEC_NO_EXPORT 
#  endif
#endif

#ifndef JPEG2KCODEC_DEPRECATED
#  define JPEG2KCODEC_DEPRECATED __declspec(deprecated)
#endif

#ifndef JPEG2KCODEC_DEPRECATED_EXPORT
#  define JPEG2KCODEC_DEPRECATED_EXPORT JPEG2KCODEC_EXPORT JPEG2KCODEC_DEPRECATED
#endif

#ifndef JPEG2KCODEC_DEPRECATED_NO_EXPORT
#  define JPEG2KCODEC_DEPRECATED_NO_EXPORT JPEG2KCODEC_NO_EXPORT JPEG2KCODEC_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef JPEG2KCODEC_NO_DEPRECATED
#    define JPEG2KCODEC_NO_DEPRECATED
#  endif
#endif

#endif /* JPEG2KCODEC_EXPORT_H */
