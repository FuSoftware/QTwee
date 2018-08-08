#ifndef FORMAT_H
#define FORMAT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class Format
{
public:
    Format(QString format_name = "");
    void loadFormat(QString format_name);
    void loadFile(QString file);

    QString getName();
    QString getAuthor();
    QString getVersion();

private:
    void loadMetaData(QJsonDocument &d);
    QString getStringParameter(const QString &parameter, const QJsonObject &obj) const;

    QString name;
    QString version;
    QString description;
    bool proofing;

    QString license;
    QString author;
    QString code;

};

#endif // FORMAT_H
