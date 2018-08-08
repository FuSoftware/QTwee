#include "projectscanner.h"
#include <iostream>

ProjectScanner::ProjectScanner(QStringList paths)
{
    this->setupCategories();

    if(!paths.isEmpty())
    {
         this->scan(paths);
    }
}

void ProjectScanner::setupCategories()
{
    this->addCategory("twee", {"tw","twee"});
    this->addCategory("css", {"css"});
    this->addCategory("js", {"js"});
    this->addCategory("img", {"jpg","png","gif","bmp"});
    this->addCategory("misc", {""});
}

void ProjectScanner::addCategory(QString name, QStringList extensions)
{
    this->categories[name] = FileCategory(extensions);
}

void ProjectScanner::scan(QStringList paths)
{
    for(QString s : paths)
    {
        this->scan(s);
    }
}

void ProjectScanner::scan(QString path)
{
    this->scan(QFileInfo(path));
}

void ProjectScanner::scan(QFileInfo file)
{
    QString path = file.absoluteFilePath();
    if(!this->processed.contains(path))
    {
        this->processed.append(path);

        if(this->exists(file))
        {
            if(this->isFile(file))
            {
                this->addFile(file);
            }
            else if(this->isFolder(file))
            {
                QDir d = QDir(file.absoluteFilePath());
                d.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

                for(QFileInfo f : d.entryInfoList())
                {
                    this->scan(f);
                }
            }
            else
            {
                std::cerr << "Path " << path.toStdString() << " was not found." << std::endl;
            }
        }
    }
}

void ProjectScanner::addFile(QFileInfo file)
{
    for(QString k : this->categories.keys())
    {
        if(this->categories[k].extensions.contains(file.suffix()))
        {
            this->categories[k].files.append(file);
            return;
        }
    }

    this->categories["misc"].files.append(file);
}

QVector<QFileInfo> ProjectScanner::getFiles(QString category)
{
    return this->categories[category].files;
}

QVector<QFileInfo> ProjectScanner::getTweeFiles()
{
    return this->getFiles("twee");
}

QVector<QFileInfo> ProjectScanner::getJsFiles()
{
    return this->getFiles("js");
}

QVector<QFileInfo> ProjectScanner::getCssFiles()
{
    return this->getFiles("css");
}

QVector<QFileInfo> ProjectScanner::getImageFiles()
{
    return this->getFiles("img");
}

QVector<QFileInfo> ProjectScanner::getMiscFiles()
{
    return this->getFiles("misc");
}

bool ProjectScanner::exists(QFileInfo file)
{
    return file.exists();
}

bool ProjectScanner::isFolder(QFileInfo file)
{
    return file.isDir();
}

bool ProjectScanner::isFile(QFileInfo file)
{
    return file.isFile();
}
