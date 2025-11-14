#ifndef SIVAL_CORE_GLOBAL_H
#define SIVAL_CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIVAL_CORE_LIBRARY)
#define SIVAL_CORE_EXPORT Q_DECL_EXPORT
#else
#define SIVAL_CORE_EXPORT Q_DECL_IMPORT
#endif

#endif // SIVAL_CORE_GLOBAL_H
