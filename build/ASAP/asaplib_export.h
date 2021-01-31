
#ifndef ASAPLIB_EXPORT_H
#define ASAPLIB_EXPORT_H

#ifdef ASAPLIB_STATIC_DEFINE
#  define ASAPLIB_EXPORT
#  define ASAPLIB_NO_EXPORT
#else
#  ifndef ASAPLIB_EXPORT
#    ifdef ASAPLib_EXPORTS
        /* We are building this library */
#      define ASAPLIB_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ASAPLIB_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ASAPLIB_NO_EXPORT
#    define ASAPLIB_NO_EXPORT 
#  endif
#endif

#ifndef ASAPLIB_DEPRECATED
#  define ASAPLIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef ASAPLIB_DEPRECATED_EXPORT
#  define ASAPLIB_DEPRECATED_EXPORT ASAPLIB_EXPORT ASAPLIB_DEPRECATED
#endif

#ifndef ASAPLIB_DEPRECATED_NO_EXPORT
#  define ASAPLIB_DEPRECATED_NO_EXPORT ASAPLIB_NO_EXPORT ASAPLIB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ASAPLIB_NO_DEPRECATED
#    define ASAPLIB_NO_DEPRECATED
#  endif
#endif

#endif /* ASAPLIB_EXPORT_H */
