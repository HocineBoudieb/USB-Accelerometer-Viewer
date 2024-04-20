#include "accviewserv.h"

AccViewServ::AccViewServ(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags),sending(false)
{
	ui.setupUi(this);
	for(size_t idx = 0; idx<MAX_CLIENTS; idx++) clients[idx] = 0;
	connect(&serv,SIGNAL(newConnection()),this,SLOT(on_connexion()));
	serv.listen(QHostAddress::Any,SERV_PORT);
	Msg("Demarage");
	ui.m_send->setEnabled(true);
}

AccViewServ::~AccViewServ()
{
	serv.close();
	for(size_t idx = 0; idx<MAX_CLIENTS; idx++) 
		if(clients[idx]){clients[idx]->close();clients[idx]->deleteLater();}
}
