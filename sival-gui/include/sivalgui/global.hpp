#ifndef SIVAL_GUI_GLOBAL_H
#define SIVAL_GUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIVAL_GUI_LIBRARY)
#define SIVAL_GUI_EXPORT Q_DECL_EXPORT
#else
#define SIVAL_GUI_EXPORT Q_DECL_IMPORT
#endif

#endif // SIVAL_GUI_GLOBAL_H
