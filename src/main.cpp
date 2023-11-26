#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    // Initialize the Qt application class
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

//#include "application.h"
//#include <QtWidgets/QApplication>
//#include "mainwindow.h"
//
//int main(){
//    Application app;
//
//    QApplication a();
//
//    // Start the application
//    app.run();
//
//    return 0;
//}