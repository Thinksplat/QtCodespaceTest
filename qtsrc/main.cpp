#include <QtWidgets>
#include "mainwidget.h"
#include "betterwidget.h"
#include "clickbusiness.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget mainwindow;

    auto mainWidget = new MainWidget(&mainwindow);

    ClickBusiness business(10, "OMG! Stop!");

    auto betterWidget = new BetterWidget(business, &mainwindow);

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(mainWidget, 0, 0);
    mainLayout->addWidget(betterWidget, 0, 1);
    mainwindow.setLayout(mainLayout);

    mainwindow.show();
    return app.exec();
}