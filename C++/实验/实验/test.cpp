//建立一个楼房基类Building为基类，用于存储地址和楼号
//建立住宅类House继承Building，用来存储房号和面积
//另外建立办公室类Office继承Building，存储办公室名称和电话号码。
//基本要求:编制应用程序，建立住宅和办公室对象测试之并输出有关数据提交程序。

#include <iostream>
#include <String>
using namespace std;

class Building
{
private:
	string address;//地址
	string buildnum;//楼号
public:
	void setAdd(string);//设置地址
	void setBui(string);//设置楼号
	string getAdd();
	string getBui();
};

void Building::setAdd(string address)
{
	this->address = address;
}
void Building::setBui(string buildnum)
{
	this->buildnum = buildnum;
}
string Building::getAdd()
{
	return address;
}
string Building::getBui()
{
	return buildnum;
}

class House :public Building
{
private:
	string housenum;//房号
	int area;//面积
public:
	void setHou(string);//设置房号
	void setAre(int);//设置面积
	string getHou();
	int getAre();
};

void House::setHou(string housenum)
{
	this->housenum = housenum;
}
void House::setAre(int area)
{
	this->area = area;
}
string House::getHou()
{
	return housenum;
}
int House::getAre()
{
	return area;
}


class Office :public Building//存储办公室名称和电话号码
{
private:
	string name;
	string number;
public:
	void setNam(string);//设置名称
	void setNum(string);//设置电话
	string getNam();
	string getNum();
};

void Office::setNam(string name)
{
	this->name = name;
}
void Office::setNum(string number)
{
	this->number = number;
}
string Office::getNam()
{
	return name;
}
string Office::getNum()
{
	return number;
}

int main()
{
	House hou;
	hou.setAdd("西安市");
	hou.setAre(230);
	hou.setBui("3号楼");
	hou.setHou("504");
	cout << hou.getAdd() << hou.getAre() << hou.getHou() << hou.getBui() << endl;
	return 0;
}