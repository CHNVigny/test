#include <iostream>
#include "equipment.h"
#include "recoContact.h"

void init(){
	//读取本地的配置文件记录之前的历史记录，或者重要信息，
}


int main(){
	//RecoGrant();
	struct smartSwitch ss;
	recoContact reco;
	int i=reco.RecoScan(&ss,"192.168.253.255");
	cout<<i<<endl;
	i=reco.contral(GETINFOINS,&ss);
	cout<<ss.I<<endl;
	cout<<ss.U<<endl;
	
	cout<<ss.P<<endl;
	cout<<ss.E<<endl;
	return 1;

	//1扫描已经建立的连接
	//2与远程端建立连接，使用p2p或者本地模式
	//3接收指令，进行处理，调用不同的函数进行实现
	//接收指令时，记录访问信息，同时记录连接记录。


}
