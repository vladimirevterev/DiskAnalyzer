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
    analyzer = new Analyzer(this);

    connect(this, SIGNAL(destroyed()), analyzer, SLOT(quit()));
    connect(analyzer, SIGNAL(finished()), this, SLOT(enableAnalyzeButton()));

    logger->print("Started");
}

MainWindow::~MainWindow()
{
    analyzer->requestInterruption();
    analyzer->wait(2000); // wait 2 seconds
    delete ui;
}

void MainWindow::enableAnalyzeButton()
{
    ui->analyzeButton->setText("Analyze");
    ui->analyzeButton->setEnabled(true);
}

void MainWindow::on_dirTree_clicked(const QModelIndex &index)
{
    QFileInfo fileInfo = dirModel->fileInfo(index);
    if (fileInfo.isDir()) {
        ui->analysisPath->setText(fileInfo.absoluteFilePath());
    }
    logger->print(fileInfo.absoluteFilePath());
}

void MainWindow::on_analyzeButton_clicked()
{
    if (analyzer->isRunning()) {
        analyzer->requestInterruption();
        ui->analyzeButton->setEnabled(false);
    }
    else {
        analyzer->folderPath = ui->analysisPath->toPlainText();
        analyzer->start();
        ui->analyzeButton->setText("Cancel");
    }
}
