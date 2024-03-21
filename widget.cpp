#include "widget.h"

#include <spaceship.h>

#include <QInputDialog>

#include "asteroid.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  scene = new QGraphicsScene(0, 0, 1024, 768, this);
  resize(1070, 800);
  ui->graphicsView->setScene(scene);

  scene->addRect(0, 0, 1024, 768);

  auto background = new QGraphicsPixmapItem(QPixmap(":background.jpg"));
  background->setPos(-200, -200);
  scene->addItem(background);

  auto s = new Spaceship;
  scene->addItem(s);
  s->setFocus();
  scene->setStickyFocus(true);

  scoreText = new QGraphicsSimpleTextItem(QString("score: 0"));
  scoreText->setScale(3);
  scoreText->setPos(2, 2);
  scene->addItem(scoreText);

  animation = new QTimer(this);
  connect(animation, &QTimer::timeout, this, [this, s] {
    scene->advance();
    scoreText->setText(QString("score: %1").arg(score));
    scoreText->setBrush(QBrush(Qt::white));
    if (!s->isAlive()) {
      animation->stop();
      generator->stop();
      scene->removeItem(s);

      auto text = scene->addText("");
      text->setPos(1024 / 2 - 200, 768 / 2 - 60);
      text->setHtml(
          QString("<font color = \"white\"><h1> Game Over </h1></font>"));
      text->setScale(3);

      QString nickName =
          QInputDialog::getText(this, "Game over", "Enter nickname: ");

      if (!nickName.isEmpty() and score) {
        emit newRecord(nickName.toStdString(), score);
      }
    }
  });
  animation->start(1000 / 165);

  generator = new QTimer(this);
  connect(generator, &QTimer::timeout, this,
          [this] { scene->addItem(new Asteroid(score)); });
  generator->start(1000);
}

Widget::~Widget() { delete ui; }
