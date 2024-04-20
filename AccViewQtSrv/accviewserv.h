#ifndef ACCVIEWSERV_H
#define ACCVIEWSERV_H

#include <QtGui/QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include "ui_accviewserv.h"
#include "AccSensor.h"
#define SERV_PORT 4040
#define MAX_CLIENTS 50

class AccViewServ : public QDialog, public AccManager
{
	Q_OBJECT
	QTcpServer serv;
	QTcpSocket* clients[MAX_CLIENTS];
	QTimer timer;
	bool sending;
	AccSensor* sensor;

public:
	AccViewServ(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AccViewServ();

private:
	Ui::AccViewServClass ui;
	
	void Msg(const QString& s)
	{
		ui.m_txt->addItem(s);
		ui.m_txt->scrollToBottom();
		ui.m_txt->repaint();
	}
	public slots:
		void on_connexion()//demande connexion client
		{
			size_t idx = 0;
			while(clients[idx] && idx<MAX_CLIENTS)idx;;
			QTcpSocket* pclient = serv.nextPendingConnection();
			if(idx<MAX_CLIENTS)//il reste une place
			{
				Msg(QString("Connexion acceptée pour %1:%2").arg(pclient->peerAddress().toString()).arg(pclient->peerPort()));
				clients[idx] = pclient;
				connect(pclient,SIGNAL(disconnected()),this,SLOT(on_disconnected()));
			}
			else
			{
				Msg(QString("Connexion refusée pour %1:%2").arg(pclient->peerAddress().toString()).arg(pclient->peerPort()));
				pclient->close();
				delete pclient;
				connect(pclient,SIGNAL(disconnected()),this,SLOT(on_disconnected()));
			}

		}
		void on_disconnected()
		{
			QTcpSocket* pclient = (QTcpSocket*)sender();
			if(!pclient)return;
			for(size_t idx = 0; idx<MAX_CLIENTS; idx++)
			{
				if(clients[idx]==pclient)
				{
					Msg(QString("Connexion Terminée pour %1:%2").arg(pclient->peerAddress().toString()).arg(pclient->peerPort()));
					clients[idx] = 0;
					pclient->close();pclient->deleteLater();
					break;
				}
			}
		}
		void on_m_send_released()
		{
			Msg(QString("send_clicked"));
			sending = !sending;
			if(sending){
				if(GetNbSensors()){
				sensor = GetSensor(0);
				timer.start(1000);}
			}
			else timer.stop();
			ui.m_send->setText(sending?QString("Sending..."):QString("Send"));
		}

		void on_timer()
		{
			char xyz[6];
			if(sensor->ReadAcc((short*)xyz))
			{
				for(size_t idx = 0; idx<MAX_CLIENTS; idx++)
					if(clients[idx])clients[idx]->write(xyz,6*sizeof(char));
				Msg(QString("X:%1, Y:%2, Z:3%").arg(*((short*)xyz)).arg(*(((short*)xyz)+1)).arg(*(((short*)xyz)+2)));
			}
			else Msg(QString("ERREUR"));
		}
		
};

#endif // ACCVIEWSERV_H
