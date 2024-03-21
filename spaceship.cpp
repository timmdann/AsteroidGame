#include "spaceship.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "bullet.h"
#include "qsprite.h"

bool Spaceship::isAlive() const { return alive; }

Spaceship::Spaceship() : QGraphicsPixmapItem(QPixmap(":spaceship.png")) {
  setPos(0, 660);
  setScale(0.15);

  setFlag(ItemIsFocusable);
}

void Spaceship::advance(int phase) {
  if (phase) {
    if (timeout > 0) --timeout;
    if (data(1).toBool()) {
      scene()->addItem(new QSprite(pos()));
      alive = false;  // godmode
    }
  } else {
    if (pos().x() + speedX >= -20 && pos().x() + speedX <= 945 &&
        pos().y() + speedY >= 0 && pos().y() + speedY <= 670)
      moveBy(speedX, speedY);
    qDebug() << pos();
  }
}

int Spaceship::type() const { return 654321; }

void Spaceship::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Left:
      speedX = -5;
      break;
    case Qt::Key_Right:
      speedX = 5;
      break;
    case Qt::Key_Up:
      speedY = -5;
      break;
    case Qt::Key_Down:
      speedY = 5;
      break;
    case Qt::Key_Space:
      if (timeout == 0) {
        QGraphicsItem *item;
        switch (rand() % 3) {
          case 0:
            item = new Bullet<255, 0, 0>(
                pos().x() + sceneBoundingRect().width() / 2, pos().y());
            break;
          case 1:
            item = new Bullet<0, 255, 0>(
                pos().x() + sceneBoundingRect().width() / 2, pos().y());
            break;
          case 2:
            item = new Bullet<255, 255, 0>(
                pos().x() + sceneBoundingRect().width() / 2, pos().y());
            break;
        }

        scene()->addItem(item);
        timeout = 100;
      }
      break;
  }
}

void Spaceship::keyReleaseEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Left:
      if (speedX != 5) speedX = 0;
      break;
    case Qt::Key_Right:
      if (speedX != -5) speedX = 0;
      break;
    case Qt::Key_Up:
      if (speedY != 5) speedY = 0;
      break;
    case Qt::Key_Down:
      if (speedY != -5) speedY = 0;
      break;
  }
}
