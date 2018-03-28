#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QtWidgets>
#include <QString>

class Logger : public QObject
{
    Q_OBJECT
private:
    QTextBrowser *textBrowser;
public:
    Logger(QObject *parent = 0);
    Logger(QObject *parent = 0, QTextBrowser *textBrowser = 0);

signals:

public slots:
    void print(const QString& text);
};

#endif // LOGGER_H
