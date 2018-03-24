#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QFileSystemModel>

#include "logger.h"
#include "analyzer.h"

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
    void enableAnalyzeButton();
private slots:

    void on_dirTree_clicked(const QModelIndex &index);

    void on_analyzeButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    Logger *logger;
    Analyzer *analyzer;
};

#endif // MAINWINDOW_H
