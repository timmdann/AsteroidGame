#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE
/**
 * @brief The Widget class represents the main game widget.
 */
class Widget : public QWidget {
  Q_OBJECT
  QGraphicsScene *scene;
  QTimer *animation;
  QTimer *generator;

  unsigned score = 0;
  QGraphicsSimpleTextItem *scoreText;

 public:
  /**
   * @brief Constructs the main game widget.
   * @param parent The parent widget.
   */
  Widget(QWidget *parent = nullptr);
     /**
   * @brief Destroys the main game widget.
   */
  ~Widget();

 private:
  Ui::Widget *ui;

 signals:
  /**
   * @brief Signal emitted when a new high score is achieved.
   * @param nickname The player's nickname.
   * @param score The player's score.
   */
  void newRecord(std::string, unsigned);
};
#endif  // WIDGET_H
