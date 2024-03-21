#include <QApplication>
#include <QMessageBox>
#include <QStyleFactory>

#include "mainmenu.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  //  QMessageBox::information(0, "Info", "This application was created by
  //  Daniil");

  //  Widget w;
  //  w.show();

  a.setStyle(QStyleFactory::create("fusion"));

  MainMenu m;
  m.show();

  return a.exec();
}
