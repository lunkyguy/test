#pragma once
#include <qthread.h>
#include <qudpsocket.h>
class UdpSender :
	public QThread
{
public:
	UdpSender();
	~UdpSender();

public:
	void run();

private:
	QUdpSocket *sender;
};

