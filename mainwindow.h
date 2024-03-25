#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cipher.h"
#include "caesarstrategy.h"
#include "atbashstrategy.h"
#include "disappearstrategy.h"
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void changeStrategy(int index);
    void encrypt();
    void decrypt();

private:
    Cipher cipher;
    QList<ICipherStrategy*> strategys;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
