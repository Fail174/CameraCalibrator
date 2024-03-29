
#ifndef ONVIFCOMMON_EXPORT_H
#define ONVIFCOMMON_EXPORT_H

#ifdef ONVIFCOMMON_STATIC_DEFINE
#  define ONVIFCOMMON_EXPORT
#  define ONVIFCOMMON_NO_EXPORT
#else
#  ifndef ONVIFCOMMON_EXPORT
#    ifdef onvifcommon_EXPORTS
        /* We are building this library */
#      define ONVIFCOMMON_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ONVIFCOMMON_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ONVIFCOMMON_NO_EXPORT
#    define ONVIFCOMMON_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ONVIFCOMMON_DEPRECATED
#  define ONVIFCOMMON_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ONVIFCOMMON_DEPRECATED_EXPORT
#  define ONVIFCOMMON_DEPRECATED_EXPORT ONVIFCOMMON_EXPORT ONVIFCOMMON_DEPRECATED
#endif

#ifndef ONVIFCOMMON_DEPRECATED_NO_EXPORT
#  define ONVIFCOMMON_DEPRECATED_NO_EXPORT ONVIFCOMMON_NO_EXPORT ONVIFCOMMON_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ONVIFCOMMON_NO_DEPRECATED
#    define ONVIFCOMMON_NO_DEPRECATED
#  endif
#endif

#endif /* ONVIFCOMMON_EXPORT_H */
