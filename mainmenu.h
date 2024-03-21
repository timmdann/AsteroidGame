#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMessageBox>
#include <QTableWidget>
#include <QWidget>
#include <fstream>
#include <map>

#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

 /**
 * @brief The MainMenu class represents the main menu of the game.
 */
class MainMenu : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructs the main menu.
   * @param parent The parent widget.
   */
  MainMenu(QWidget *parent = nullptr);
   /**
   * @brief Reads the high scores from the database file.
   */
  void readDB();
  /**
   * @brief Writes the high scores to the database file.
   */
  void writeDB();
  /**
   * @brief Destroys the main menu.
   */
  ~MainMenu();

 public slots:
  /**
   * @brief Adds a new record to the high scores.
   * @param nickname The player's nickname.
   * @param score The player's score.
   */
  void addRecord(const std::string &nickname, unsigned score);
     /**
   * @brief Shows the high scores.
   */
  void showRecords();

 private:
  Ui::MainMenu *ui;
  Widget *game = nullptr;
  std::map<std::string, unsigned> scores;
};
#endif  // MAINMENU_H
