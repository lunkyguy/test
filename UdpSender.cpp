 #include "UdpSender.h"



UdpSender::UdpSender()
{
	sender = new QUdpSocket();
}


UdpSender::~UdpSender()
{
}

void UdpSender::run()
{
	//¼ÓÈë×é²¥
	/*sender->joinMulticastGroup(QHostAddress("224.0.0.100"));*/
	//sender->bind();
	while (true)
	{
		//qus.writeDatagram(msg, QHostAddress("127.0.0.1"), PORT);
		QByteArray msg = "Hello world!";
		//qDebug() << "--- Sender ---" << msg;
		sender->writeDatagram(msg, QHostAddress("224.104.100.101"), 8870);
	}
}
