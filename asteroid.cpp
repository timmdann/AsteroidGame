#include "asteroid.h"

#include <QGraphicsScene>

#include "qsprite.h"

Asteroid::Asteroid(unsigned& score)
    : QGraphicsPixmapItem(QPixmap(":asteroid.png")), score(score) {
  setScale(0.1);
  yspeed = 1 + 0.03 * score;
  setPos(rand() % (1024 - 78), -20);
}

void Asteroid::advance(int phase) {
  if (!phase) {
    moveBy(0, yspeed);
  } else {
    foreach (QGraphicsItem* i, collidingItems()) {
      if (i->type() == 123456 || i->type() == 654321) {
        ++score;
        scene()->addItem(new QSprite(pos()));
        i->setData(1, true);
        delete this;
        return;
      }
    }
  }
}
