#include "format.h"

Format::Format(QString format_name)
{
    if(format_name != "")
    {
        this->loadFormat(format_name);
    }
}

void Format::loadFormat(QString format_name)
{
    this->name = format_name;
}

void Format::loadFile(QString file)
{
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cerr << "Could not open file " << file.toStdString() << std::endl;
        return;
    }
    QTextStream in(&f);
    QString s = in.readAll();
    f.close();

    int b = s.indexOf("{");
    int e = s.lastIndexOf("}");
    s = s.mid(b, e - b + 1);

    QJsonParseError error;
    QJsonDocument d = QJsonDocument::fromJson(s.toUtf8(), &error);

    if(error.error != QJsonParseError::NoError)
    {
        qCritical() << "Error in file" << file << "at offset" << error.offset << ":" << error.errorString();
        return;
    }

    this->loadMetaData(d);
}

void Format::loadMetaData(QJsonDocument &d)
{
    QJsonObject root = d.object();
    this->name = this->getStringParameter("name", root);
    this->version = this->getStringParameter("version", root);
    this->description = this->getStringParameter("description", root);
    this->author = this->getStringParameter("author", root);
}

QString Format::getStringParameter(const QString &parameter, const QJsonObject &obj) const
{
    return obj.contains(parameter) ? obj[parameter].toString() : QString();
}

QString Format::getName()
{
    return this->name;
}

QString Format::getAuthor()
{
    return this->author;
}

QString Format::getVersion()
{
    return this->version;
}
