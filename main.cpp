#include "mainwindow.h"
#include "datatypes.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<AnalysisResult>();

    MainWindow w;
    w.setWindowTitle("Disk Analyzer");
    w.setWindowIcon(QIcon(":/icon.png"));
    w.show();

    return a.exec();
}
