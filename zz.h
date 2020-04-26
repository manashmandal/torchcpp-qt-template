#ifndef ZZ_H
#define ZZ_H

#include "./ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr)
      : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
  }
  ~MainWindow() { delete ui; }

private:
  Ui::MainWindow *ui;
};

#endif // ZZ_H
