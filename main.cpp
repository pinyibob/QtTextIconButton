#include <QApplication>
#include "MyButton.h"
#include "MyWidget.h"
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
	QFile file("style.qss");

	if (false == file.open(QIODevice::ReadOnly))
	{
		qDebug() << "open qss file fail!";
	}
	QByteArray fileContent = file.readAll();
	file.close();

    QApplication a(argc, argv);
	qApp->setStyleSheet(fileContent);
    MyWidget myWidget;
    myWidget.show();
    return a.exec();
}
