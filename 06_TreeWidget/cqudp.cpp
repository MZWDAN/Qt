#include "cqudp.h"

CQUdp::CQUdp()
{
    //QT中的UDP
    QUdpSocket *revWBudp;
    revWBudp = new QUdpSocket;
    bool result = revWBudp->bind(LocalPort,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    if(result)
    {
        revWBudp->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024*8);//设置缓冲区
        //连接接收信号槽
        connect(revWBudp,SIGNAL(readyRead()),this,SLOT(dataReceived()));
        //发送数据 目的地址：serverIP  目的IP:serverPort
        QByteArray line;
        line.resize(2);
        line[0] = 0x02;
        line[1] = 0x7d;
        revWBudp->writeDatagram(line.data() , QHostAddress(serverIP),serverPort);
    ｝

        //QT中的组播
        QUdpSocket *revWBudp;
        revWBudp = new QUdpSocket;
        //绑定本地端口
        revWBudp->bind(QHostAddress::AnyIPv4, multicastPort, QUdpSocket::ShareAddress);
        //加入组播组
        bool result = revWBudp->joinMulticastGroup(QHostAddress(multicastIP));
        if(result)
        {
            //设置缓冲区
            revWBudp->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption,1024*1024*8);
            //连接接收信号槽
            connect(revWBudp,SIGNAL(readyRead()),this,SLOT(dataReceived()));
        ｝
}
