#include <QtWidgets>
#include "betterwidget.h"

BetterWidget::BetterWidget(IClickMsg &clicker, QWidget *parent) :  QWidget(parent), clicker(clicker)
{
    auto button_ = new QPushButton(tr("Better Push Me!"));
    textBrowser_ = new QTextBrowser();

    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(button_, 0, 0);
    mainLayout->addWidget(textBrowser_, 1, 0);

    // connect to button the buttonClicked slot
    connect(button_, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setLayout(mainLayout);
    setWindowTitle(tr("Connecting buttons to processes.."));
}

void BetterWidget::buttonClicked()
{
    clicker.Click();
    textBrowser_->setText(clicker.Str().c_str());
}
