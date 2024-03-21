#include "mainmenu.h"

#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent), ui(new Ui::MainMenu) {
  ui->setupUi(this);

  connect(ui->quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
  connect(ui->newGameButton, &QPushButton::clicked, this, [this] {
    if (game) {
      disconnect(game, &Widget::newRecord, this, &MainMenu::addRecord);
      delete game;
    }
    game = new Widget;
    connect(game, &Widget::newRecord, this, &MainMenu::addRecord);
    game->show();
  });

  connect(ui->recordsButton, &QPushButton::clicked, this,
          &MainMenu::showRecords);

  readDB();
}

void MainMenu::readDB() {
  std::ifstream fin;
  fin.exceptions(std::iostream::badbit);
  try {
    fin.open("db.txt");
    if (!fin.is_open()) return;
    std::string nick;
    unsigned score;
    while (true) {
      std::getline(fin, nick);
      if (fin.eof()) break;
      fin >> score;
      if (fin.eof()) break;
      fin.ignore(1);  // ignore '\n'
      if (nick.empty() or score == 0)
        throw std::runtime_error("Exception reading file");
      scores[nick] = score;
    }
    fin.close();
  } catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", e.what());
  }
}

void MainMenu::writeDB() {
  try {
    std::ofstream fout("db.txt");
    for (const auto& [nickname, score] : scores) {
      fout << nickname << std::endl << score << std::endl;
    }
    fout.close();
  } catch (const std::exception& e) {
    QMessageBox::critical(this, "Error", e.what());
  }
}

MainMenu::~MainMenu() { delete ui; }

void MainMenu::addRecord(const std::string& nickname, unsigned score) {
  if (scores.count(nickname)) {
    if (scores[nickname] < score) {
      scores[nickname] = score;
    }
  } else {
    scores[nickname] = score;
  }

  writeDB();
}

void MainMenu::showRecords() {
  auto view = new QTableWidget;
  view->setRowCount(scores.size());
  view->setColumnCount(2);
  uint counter = -1;
  for (const auto& [nickname, score] : scores) {
    ++counter;
    view->setItem(counter, 0,
                  new QTableWidgetItem(QString::fromStdString(nickname)));
    view->setItem(counter, 1, new QTableWidgetItem(QString::number(score)));
  }
  view->show();
}
