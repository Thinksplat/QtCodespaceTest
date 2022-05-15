#include <QtWidgets>
#include "mainwidget.h"
#include "mainwidget2.h"
#include "clickbusiness.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget mainwindow;

    auto mainWidget = new MainWidget(&mainwindow);

    ClickBusiness business(10);

    auto mainWidget2 = new MainWidget2(business, &mainwindow);

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(mainWidget, 0, 0);
    mainLayout->addWidget(mainWidget2, 1, 0);
    mainwindow.setLayout(mainLayout);

    mainwindow.show();
    return app.exec();
}