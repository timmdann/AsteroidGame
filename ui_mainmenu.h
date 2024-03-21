/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QGridLayout *gridLayout;
    QPushButton *quitButton;
    QPushButton *recordsButton;
    QLabel *label;
    QPushButton *newGameButton;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(325, 243);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MainMenu);
        gridLayout->setObjectName("gridLayout");
        quitButton = new QPushButton(MainMenu);
        quitButton->setObjectName("quitButton");

        gridLayout->addWidget(quitButton, 5, 0, 1, 1);

        recordsButton = new QPushButton(MainMenu);
        recordsButton->setObjectName("recordsButton");

        gridLayout->addWidget(recordsButton, 4, 0, 1, 1);

        label = new QLabel(MainMenu);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        newGameButton = new QPushButton(MainMenu);
        newGameButton->setObjectName("newGameButton");

        gridLayout->addWidget(newGameButton, 3, 0, 1, 1);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        quitButton->setText(QCoreApplication::translate("MainMenu", "Quit", nullptr));
        recordsButton->setText(QCoreApplication::translate("MainMenu", "Records", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "Asteroids", nullptr));
        newGameButton->setText(QCoreApplication::translate("MainMenu", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
