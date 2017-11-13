#include <process.h>
#include "FileOpt.h"
#include <iostream>
#include "Logger.h"

void main()
{
	InitLogger("Log\\info_log.txt","Log\\warn_log.txt","Log\\error_log.txt");
	LOG("hello world");

	FileOpt* file = new FileOpt();
	file->setPath("a.txt");
	while(true)
	{
		char input;
		
		cout<<"r ��ȡ�ļ�"<<endl;
		cout<<"w д���ļ�"<<endl;
		cout<<"b ����ѭ��"<<endl;
		cout<<"�������ַ�:";
		cin>>input;
		if(input>= 'A' && input <='Z')
			input += 32; //ת��Сд

		if(input == 'r')
		{
			file->ReadBinary();
		}
		else if (input == 'w')
		{
			file->WriteBinary();
		}
		else if (input == 'b' || input == 'q')
		{
			LOG("Quit, Jump Break");
			break;
		}
		else
		{
			ERROR("invalid input char: reinput again!");
		}
	}
	system("pause");
}

