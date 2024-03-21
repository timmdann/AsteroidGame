#ifndef QSPRITE_H
#define QSPRITE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QTimer>
/**
 * @brief The QSprite class represents a sprite in the game.
 */
class QSprite : public QObject, public QGraphicsItem {
  Q_OBJECT
 public:
  /**
   * @brief Constructs a sprite at a given position.
   * @param pos The initial position of the sprite.
   * @param parent The parent QObject.
   */
  explicit QSprite(QPointF pos, QObject *parent = nullptr)
      : QObject(parent), QGraphicsItem() {
    setPos(pos);
    currentFrame = 0;
    spriteImage = new QPixmap(":explosion3.png");

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &QSprite::nextFrame);
    timer->start(30);
  }

 private slots:
  /**
   * @brief Moves the sprite to the next frame of animation.
   */
  void nextFrame() {
    currentFrame += 128;
    if (currentFrame >= 2176) {
      timer->stop();
      delete this;
      return;
    }
    this->update(-10, -10, 128, 128);
  }

 private:
  /**
   * @brief Paints the sprite on the scene.
   * @param painter The QPainter object.
   * @param option Not used.
   * @param widget Not used.
   */
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) {
    painter->drawPixmap(-10, -10, *spriteImage, currentFrame, 0, 128, 128);
  }
  /**
   * @brief Returns the bounding rectangle of the sprite.
   * @return The bounding rectangle.
   */
  QRectF boundingRect() const { return QRectF(-10, -10, 128, 128); }

 private:
  QTimer *timer;
  QPixmap *spriteImage;
  int currentFrame;
};

#endif  // QSPRITE_H
