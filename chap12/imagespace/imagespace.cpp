#include <iostream>
#include <QDir>
#include <QImageReader>
#include <QCoreApplication>
qlonglong imageSpace(const QString &path)
{
    QDir dir(path);
    qlonglong size = 0;

    QStringList filters;
    for (const QByteArray & format : QImageReader::supportedImageFormats())
        filters += "*." + format;

    for (const QString & file : dir.entryList(filters, QDir::Files))
        size += QFileInfo(dir, file).size();

    for (const QString & subDir : dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
        size += imageSpace(path + QDir::separator() + subDir);

    return size;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = QCoreApplication::arguments();

    QString path = QDir::currentPath();
    if (args.count() > 1)
        path = args[1];

    std::cout << "Space used by images in " << qPrintable(path)
              << " and its subdirectories is "
              << (imageSpace(path) / 1024) << " KB" << std::endl;

    return 0;
}
