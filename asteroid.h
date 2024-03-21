#ifndef ASTEROID_H
#define ASTEROID_H
/**
 * @brief The Asteroid class represents an asteroid in the game.
 */
#include <QGraphicsPixmapItem>

class Asteroid : public QGraphicsPixmapItem {
  float yspeed;
  unsigned& score;

 public:
  /**
   * @brief Constructs an asteroid with a given score reference.
   * @param score Reference to the game score.
   */
  Asteroid(unsigned& score);
     /**
   * @brief Advances the asteroid's position during the game.
   * @param phase The game advancement phase.
   */
  void advance(int phase) override;

};

#endif  // ASTEROID_H
