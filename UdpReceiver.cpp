#include "UdpReceiver.h"



UdpReceiver::UdpReceiver()
{
	receiver = new QUdpSocket();
	//�����鲥
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
	array.resize(receiver->bytesAvailable());//���ݿɶ����������ÿռ��С
	receiver->readDatagram(array.data(), array.size()); //��ȡ����
	qDebug() << "--- Receiver ---" << array.data();
}
