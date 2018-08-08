#ifndef PROJECTSCANNER_H
#define PROJECTSCANNER_H

#include <QString>
#include <QVector>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QHash>

struct FileCategory
{
    FileCategory(){}
    FileCategory(QStringList extensions)
    {
        this->extensions = extensions;
    }

    QVector<QFileInfo> files;
    QStringList extensions;
};

class ProjectScanner
{
public:
    ProjectScanner(QStringList paths);

    void setupCategories();
    void addCategory(QString name, QStringList extensions);

    void scan(QStringList paths);
    void scan(QString path);
    void scan(QFileInfo file);

    void addFile(QFileInfo path);

    QVector<QFileInfo> getFiles(QString category);

    bool exists(QFileInfo file);
    bool isFolder(QFileInfo file);
    bool isFile(QFileInfo file);

private:
    QVector<QString> processed;
    QHash<QString, FileCategory> categories;
};

#endif // PROJECTSCANNER_H
