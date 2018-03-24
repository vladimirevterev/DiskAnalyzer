#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMessageBox>
#include <QDir>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    dirModel->setRootPath(QDir::rootPath());
    ui->dirTree->setModel(dirModel);
    for (int i = 1; i < dirModel->columnCount(); ++i) {
        ui->dirTree->hideColumn(i);
    }
    ui->dirTree->header()->hide();

    logger = new Logger(this, ui->loggingBrowser);
    analizer = new Analizer();
    analizer->moveToThread(analizer);

    connect(ui->analizeButton, SIGNAL(clicked(QModelIndex)), this, SLOT(on_analizeButton_clicked(QModelIndex)));
    connect(this, SIGNAL(destroyed()), analizer, SLOT(quit()));
    connect(analizer, SIGNAL(finished()), this, SLOT(enableAnalize()));

    logger->print("Started");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableAnalize()
{
    ui->analizeButton->setEnabled(true);
}

void MainWindow::on_analizeButton_clicked()
{
    ui->analizeButton->setEnabled(false);
    analizer->folderPath = ui->analizedPath->toPlainText();
    analizer->start();
}

void MainWindow::on_dirTree_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = dirModel->fileInfo(index);
    if (fileInfo.isDir()) {
        ui->analizedPath->setText(fileInfo.absoluteFilePath());
    }
    logger->print(fileInfo.absoluteFilePath());
}
