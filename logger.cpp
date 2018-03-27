#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{

}

Logger::Logger(QObject *parent, QTextBrowser *textBrowser) : QObject(parent)
{
    this->textBrowser = textBrowser;
}

void Logger::print(const QString& text) {
    textBrowser->append(text);
}
