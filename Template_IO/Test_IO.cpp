#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
#include<fstream>
using namespace std;

////IO流
//int main()
//{
//	int i = 1;
//	double d = 2.2;
//	cout << i << endl;//cout.operator<<(i);
//	cout << d;//cout.operator<<(d);
//	return 0;
//}


struct ServerInfo
{
	char _ip[32];//ip
	int _port;//接口
};

void Test_C_W_Bin()
{
	ServerInfo info = { "127.0.0.1",8080 };
	FILE* fout = fopen("text.bin", "wb");
	assert(fout);
	fwrite(&info, sizeof(info), 1, fout);
	fclose(fout);
}
void Test_C_R_Bin()
{
	FILE* fin = fopen("text.bin", "r");
	assert(fin);
	ServerInfo info;
	fread(&info, sizeof(info), 1, fin);
	fclose(fin);
	printf("%s : %d\n", info._ip, info._port);
}

void Test_C_W_Txt()
{
	FILE* fout = fopen("test.txt", "w");
	assert(fout);
	ServerInfo info = { "127.0.0.1",8080 };
	fprintf(fout, "%s %d\n", info._ip,info._port);
	fclose(fout);
}
void Test_C_R_Txt()
{
	FILE* fin = fopen("test.txt", "r");
	assert(fin);
	ServerInfo info;
	fscanf(fin, "%s %d\n", info._ip, &info._port);
	fclose(fin);
	printf("%s : %d\n", info._ip, info._port);
}
//int main()
//{
//	Test_C_W_Bin();//二进制写：
//	Test_C_R_Bin();//二进制读：
//	Test_C_W_Txt();//文本写:
//	Test_C_R_Txt();//文本读：
//	return 0;
//}
//------------------------------------------------------------------------------------------------>>>>>>>>>>>>

//c++的读写：


class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(_filename)
	{}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename.c_str(), ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(info));
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename.c_str(), ios_base::in | ios_base::binary);
		ifs.read((char*)&info, sizeof(info));
	}

	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename.c_str());
		ofs << info._ip << " " << info._port;
	}
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename.c_str());
		ifs >> info._ip >> info._port;
	}
private:
	string _filename;
};
int main()
{
	////二进制：
	//ServerInfo info = { "127.0.0.1",8081 };
	//ConfigManager cm("config.bin");
	////cm.WriteBin(info);
	//cm.ReadBin(info);
	//cout << info._ip << info._port << endl;


	//文本：
	ServerInfo winfo = { "127.0.0.1",8081 };

	ConfigManager cm("config1.txt");
	//cm.WriteText(winfo);
	
	
	ServerInfo rinfo;
	cm.ReadText(rinfo);
	cout << rinfo._ip << rinfo._port << endl;
	return 0;
}