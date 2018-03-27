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

    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden);
    fileSystemModel->setRootPath(QDir::rootPath());
    ui->dirTree->setModel(fileSystemModel);
    for (int i = 1; i < fileSystemModel->columnCount(); ++i) {
        ui->dirTree->hideColumn(i);
    }
    ui->dirTree->header()->hide();

    groupsTableModel = new GroupsTableModel(this);
    ui->groupsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // TODO: DELETE EXAMPLE!
    //---------- EXAMPLE FILLING TABLE----------
    QVector<QVector<QVariant> > example;
    int rowCount = 100;
    int columnCount = 4;
    example.resize(rowCount);
    for (int i = 0; i < rowCount; i++) {
        example[i].resize(columnCount);
        for (int j = 0; j < columnCount; j++) {
            QString text = "[" + QString::number(i) + ", " + QString::number(j) + "]";
            example[i][j] = QVariant(text);
        }
    }
    groupsTableModel->groupsVector = example;
    //---------- END EXAMPLE ----------
    ui->groupsView->setModel(groupsTableModel);

    logger = new Logger(this, ui->loggingBrowser);
    analyzer = new Analyzer();
    analyzer->moveToThread(analyzer);

    connect(this, &MainWindow::destroyed, analyzer, &Analyzer::quit);
    connect(analyzer, &Analyzer::finished, this, &MainWindow::enableAnalyzeButton);
    connect(analyzer, &Analyzer::analysisProgressText, logger, &Logger::print);

    logger->print("Started. Main thread: " + QString::number((long long)this->thread(), 16));
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
    QFileInfo fileInfo = fileSystemModel->fileInfo(index);
    if (fileInfo.isDir()) {
        ui->analysisPath->setText(fileInfo.absoluteFilePath());
    }
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
