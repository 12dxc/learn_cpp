#include <QApplication>
#include "timedialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TimeDialog time;

    time.show();

    // 进入主事件循环
    return app.exec();
}
