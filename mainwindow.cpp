#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix();


    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    dirModel->setRootPath(QDir::rootPath());
    ui->dirTree->setModel(dirModel);
    for (int i = 1; i < dirModel->columnCount(); ++i) {
        ui->dirTree->hideColumn(i);
    }
    ui->dirTree->header()->hide();

    logger = new Logger(this, ui->loggingBrowser);

    connect(ui->dirTree, SIGNAL(clicked(QModelIndex)), this, SLOT(on_dirTree_clicked(QModelIndex)));
    connect(ui->analizedPath, SIGNAL(clicked(QModelIndex)), this, SLOT(on_pushButton_clicked(QModelIndex)));

    logger->print("Started");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_dirTree_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = dirModel->fileInfo(index);
    if (fileInfo.isDir()) {
        ui->analizedPath->setText(fileInfo.absoluteFilePath());
    }
    logger->print(fileInfo.absoluteFilePath());
}

void MainWindow::on_analizeButton_clicked()
{

}




//void MainWindow::on_dirTreeList_doubleClicked(const QModelIndex &index)
//{
//    QListView* listView = (QListView*)sender();
//    QFileInfo fileInfo = model->fileInfo(index);
//    if (fileInfo.fileName() == "..") {
//        QDir dir = fileInfo.dir();
//        dir.cdUp();
//        listView->setRootIndex(model->index(dir.absolutePath()));
//    }
//    else if (fileInfo.fileName() == ".") {
//        listView->setRootIndex(model->index(""));
//    }
//    else if (fileInfo.isDir()) {
//        listView->setRootIndex(index);
//    }
//}

