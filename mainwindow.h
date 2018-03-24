#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QFileSystemModel>

#include "logger.h"
#include "analizer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void enableAnalize();
private slots:

    void on_analizeButton_clicked();

    void on_dirTree_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    Logger *logger;
    Analizer *analizer;
};

#endif // MAINWINDOW_H
