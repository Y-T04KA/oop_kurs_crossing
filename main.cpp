#include "TCrossingInterface.h"

int main(int argc, char *argv[]) {
    //QApplication a(argc, argv);
    //QPushButton button("Hello world!", nullptr);
    //button.resize(200, 100);
    //button.show();
    TCrossingInterface a(argc,argv);
    a.setStyle("fusion");
    return a.exec();
    //return QApplication::exec();
}
