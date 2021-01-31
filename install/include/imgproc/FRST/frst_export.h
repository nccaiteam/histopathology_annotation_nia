
#ifndef FRST_EXPORT_H
#define FRST_EXPORT_H

#ifdef FRST_STATIC_DEFINE
#  define FRST_EXPORT
#  define FRST_NO_EXPORT
#else
#  ifndef FRST_EXPORT
#    ifdef FRST_EXPORTS
        /* We are building this library */
#      define FRST_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define FRST_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef FRST_NO_EXPORT
#    define FRST_NO_EXPORT 
#  endif
#endif

#ifndef FRST_DEPRECATED
#  define FRST_DEPRECATED __declspec(deprecated)
#endif

#ifndef FRST_DEPRECATED_EXPORT
#  define FRST_DEPRECATED_EXPORT FRST_EXPORT FRST_DEPRECATED
#endif

#ifndef FRST_DEPRECATED_NO_EXPORT
#  define FRST_DEPRECATED_NO_EXPORT FRST_NO_EXPORT FRST_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef FRST_NO_DEPRECATED
#    define FRST_NO_DEPRECATED
#  endif
#endif

#endif /* FRST_EXPORT_H */
