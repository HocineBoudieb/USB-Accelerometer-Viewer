#include "accviewserv.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AccViewServ w;
	w.show();
	return a.exec();
}
