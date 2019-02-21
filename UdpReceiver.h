#pragma once
#include <qthread.h>
#include <qudpsocket.h>
class UdpReceiver :
	public QThread
{
public:
	UdpReceiver();
	~UdpReceiver();

public:
	void read_data();

private:
	QUdpSocket *receiver;
};

