#include <iostream>
#include "webUrl.h"

int main(){
	string s1="/hello?www=1&teed=2&hello=nihao";
	webUrl w=webUrl(s1);
	string s=w.getValue("type");
	cout<<s<<endl;
	s=w.getValue("www");
	cout<<s<<endl;
	s=w.getValue("teed");
	cout<<s<<endl;
	s=w.getValue("hello");
	cout<<s<<endl;
	return 0;
}