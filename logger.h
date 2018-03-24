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
    Logger(QObject *parent = nullptr);
    Logger(QObject *parent = nullptr, QTextBrowser *textBrowser = nullptr);

    void print(const QString& text);
signals:

public slots:
};

#endif // LOGGER_H
