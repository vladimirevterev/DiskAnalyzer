#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QFileSystemModel>
#include <QDir>
#include "logger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_dirTree_clicked(const QModelIndex &index);
    void on_analizeButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    Logger *logger;
};

#endif // MAINWINDOW_H
