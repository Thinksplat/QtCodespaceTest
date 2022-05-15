#include <QtWidgets>
#include "mainwidget2.h"

// Constructor for main widget
MainWidget2::MainWidget2(IClickMsg &clicker, QWidget *parent) :  QWidget(parent), clicker(clicker)
{
    auto button_ = new QPushButton(tr("Push Me!"));
    textBrowser_ = new QTextBrowser();

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(button_, 0, 0);
    mainLayout->addWidget(textBrowser_, 1, 0);

    // connect to button the buttonClicked slot
    connect(button_, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setLayout(mainLayout);
    setWindowTitle(tr("Connecting buttons to processes.."));
}

void MainWidget2::buttonClicked()
{
    clicker.Click();
    textBrowser_->setText(clicker.Str().c_str());
}
