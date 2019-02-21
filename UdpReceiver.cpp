#include "UdpReceiver.h"



UdpReceiver::UdpReceiver()
{
	receiver = new QUdpSocket();
	//加入组播
	receiver->joinMulticastGroup(QHostAddress("224.104.100.101"));
	receiver->bind(QHostAddress::AnyIPv4, 8870);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(read_data()));
}


UdpReceiver::~UdpReceiver()
{

}

void UdpReceiver::read_data()
{
	QByteArray array;
	array.resize(receiver->bytesAvailable());//根据可读数据来设置空间大小
	receiver->readDatagram(array.data(), array.size()); //读取数据
	qDebug() << "--- Receiver ---" << array.data();
}
