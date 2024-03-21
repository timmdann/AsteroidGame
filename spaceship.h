#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QGraphicsPixmapItem>
/**
 * @brief The Spaceship class represents the player's spaceship in the game.
 */
class Spaceship : public QGraphicsPixmapItem {
  int speedX = 0, speedY = 0;
  int timeout = 0;
  bool alive = true;

 public:
  /**
   * @brief Constructs a spaceship.
   */
  Spaceship();
     /**
   * @brief Advances the spaceship's position during the game.
   * @param phase The game advancement phase.
   */
  void advance(int phase) override;
  /**
   * @brief Returns the type of the spaceship.
   * @return The type identifier.
   */
  int type() const override;
  /**
   * @brief Checks if the spaceship is alive.
   * @return True if the spaceship is alive, false otherwise.
   */

  bool isAlive() const;

protected:
  /**
   * @brief Handles key press events for controlling the spaceship.
   * @param event The key event.
   */
  void keyPressEvent(QKeyEvent *event) override;
    /**
   * @brief Handles key release events for controlling the spaceship.
   * @param event The key event.
   */
  void keyReleaseEvent(QKeyEvent *event) override;

};

#endif  // SPACESHIP_H
