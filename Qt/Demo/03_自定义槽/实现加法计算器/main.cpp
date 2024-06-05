#include <QApplication>
#include "calculatordialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CalculatorDialog calc;

    calc.show();

    // 进入主事件循环
    return app.exec();
}
