/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QDir>
#include <QFile>
#include <QFileInfo>
//// end system includes

//// begin project specific includes
#include "sivalcore/io/fileiohandler.hpp"
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL::Core {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
FileIOHandler::FileIOHandler(const QString &filename)
    :AbstractIOHandler(filename) {
}

/**************************************************************************************************/
/**
 *
 */
FileIOHandler::~FileIOHandler() {
}

QByteArray FileIOHandler::load() {
    QFile file(m_filename);
    QByteArray array;
    if(file.open(QIODevice::ReadOnly)) {
        array = file.readAll();
        file.close();
    }
    return array;
}
bool FileIOHandler::save(QByteArray content) {
    QFile file(m_filename);

    QFileInfo info(file);
    QString path = info.absolutePath();
    QDir dir(path);
    if(!dir.exists()) {
        dir.mkpath(path);
    }

    if (file.open(QIODevice::WriteOnly)) {
        file.write(content);
        file.close();
        return true;
    }
    return false;
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}
