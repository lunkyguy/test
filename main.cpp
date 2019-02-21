#include <QtCore/QCoreApplication>
#include "UdpSender.h"
#include "UdpReceiver.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	UdpSender *sender = new UdpSender();
	UdpReceiver *receiver = new UdpReceiver();
	sender->start();
	receiver->start();
	sender->wait();
	receiver->wait();
	return a.exec();
}
