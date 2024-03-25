#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Caesar");
    ui->comboBox->addItem("Atbash");
    ui->comboBox->addItem("Disappear");

    strategys.append(new CaesarStrategy);
    strategys.append(new AtbashStrategy);
    strategys.append(new DisappearStrategy);

    cipher.setStrategy(strategys[0]);

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::changeStrategy);
    connect(ui->encryptButton, &QPushButton::clicked, this, &MainWindow::encrypt);
    connect(ui->decryptButton, &QPushButton::clicked, this, &MainWindow::decrypt);

}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < strategys.size(); i++)
    {
        delete strategys[i];
    }
}

void MainWindow::changeStrategy(int index)
{
    cipher.setStrategy(strategys[index]);
}

void MainWindow::encrypt()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/vasyl", tr("Text files (*.txt)"));
    cipher.encrypt(path);
}

void MainWindow::decrypt()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/vasyl", tr("Text files (*.txt)"));
    cipher.decrypt(path);
}
