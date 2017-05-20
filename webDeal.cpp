#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <memory.h>
#include <pthread.h>

#include <arpa/inet.h>
#include <unistd.h>

#include "webDeal.h"
#include "webUrl.h"


using namespace std;

int webDeal::start(){
	struct headers hdr;
	getHeader(&hdr);
	string uri=hdr.uri;
	webUrl url=webUrl(uri);
	string type=url.getValue("type");
	cout<<uri<<endl;
	if(type=="reco"){
		send(sockID, "reco", 4, 0);
	}
	else if(type=="look"){
		send(sockID, "look", 4, 0);
	}
	else if(type=="state"){
		send(sockID, "state", 5, 0);
	}
	else{
		send(sockID, "error", 5, 0);
	}
}
void webDeal::getHeader(struct headers *hdr)
{
    int i = 0, j = 0;
    char c = '\n';

    memset(hdr, 0, sizeof(struct headers));
	printf("memset\n");
    //getcwd(hdr->uri, HDR_URI_SZ);

    for(i = 0; (i < HDR_METHOD_SZ) && (recv(sockID, &c, 1, 0) > 0) && (c != ' ' && c != '\n'); i++)
		//每次取得一个字节，分别进行赋值，根据http协议进行处理，首先是访问方式，一般为get，之后是访问链接长度，最后为访问版本号
    {
        if(c != '\r')
        {
            hdr->method[i] = c;
        }
    }
    for(i = 0, j = i; (i < HDR_URI_SZ) && (recv(sockID, &c, 1, 0) > 0) && (c != ' ' && c != '\n'); i++)
    {
        if(c != '\r')
        {
            hdr->uri[i] = c;
        }
    }

    for(i = 0; (i < HDR_VERSION_SZ) && (recv(sockID, &c, 1, 0) > 0) && (c != ' ' && c != '\n'); i++)
    {
        if(c != '\r')
        {
            hdr->version[i] = c;
        }
    }

    printf("HTTP version: %s\n", hdr->version);
    printf("HTTP request: %s\n", hdr->method);
    printf("HTTP uri:     %s\n", hdr->uri);
}

