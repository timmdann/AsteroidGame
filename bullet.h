#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsLineItem>
#include <QPen>
/**
 * @brief The Bullet class represents a bullet in the game.
 * @tparam r Red component of the bullet color.
 * @tparam g Green component of the bullet color.
 * @tparam b Blue component of the bullet color.
 */

template <int r, int g, int b>
class Bullet : public QGraphicsLineItem {
 public:
    /**
   * @brief Constructs a bullet at a given position.
   * @param x X-coordinate of the bullet's position.
   * @param y Y-coordinate of the bullet's position.
   */
  Bullet(int x, int y) {
    setLine(0, 0, 0, -10);
    setPos(x, y);
    setPen(QPen(QColor(r, g, b), 5));
  }
  /**
   * @brief Advances the bullet's position during the game.
   * @param phase The game advancement phase.
   */
  void advance(int phase) override {
    if (!phase) {
      moveBy(0, -1);
    } else {
      if (data(1).toBool()) delete this;
    }
  }
  /**
   * @brief Returns the type of the bullet.
   * @return The type identifier.
   */
  int type() const override { return 123456; }
};

#endif  // BULLET_H
