/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbStart;
    QPushButton *pbInfo;
    QPushButton *pbStop;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(376, 148);
        centralwidget = new QWidget(Widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 297, 63));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbStart = new QPushButton(layoutWidget);
        pbStart->setObjectName(QStringLiteral("pbStart"));

        horizontalLayout->addWidget(pbStart);

        pbInfo = new QPushButton(layoutWidget);
        pbInfo->setObjectName(QStringLiteral("pbInfo"));

        horizontalLayout->addWidget(pbInfo);

        pbStop = new QPushButton(layoutWidget);
        pbStop->setObjectName(QStringLiteral("pbStop"));

        horizontalLayout->addWidget(pbStop);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        Widget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Widget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 376, 26));
        Widget->setMenuBar(menubar);
        statusbar = new QStatusBar(Widget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Widget->setStatusBar(statusbar);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QMainWindow *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pbStart->setText(QApplication::translate("Widget", "Start", Q_NULLPTR));
        pbInfo->setText(QApplication::translate("Widget", "Info", Q_NULLPTR));
        pbStop->setText(QApplication::translate("Widget", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
