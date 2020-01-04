// VoronoiRejistration.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "PointRegistration.h"


/**************************函数声明*********************************/
void cutVerString(std::string s, ver *tem);
ver* readVer(std::string filename);



int main()
{

	ver *chead1; //存着晶胞的中心点。
	ver *chead2;
	chead1 = readVer("cow1_box_points.txt");
	chead2 = readVer("cow2_box_points.txt");
	
	PointRegistration pr1(chead1,"voronoi_r1.txt");
	PointRegistration pr2(chead2,"voronoi_r2.txt");

}

void cutVerString(std::string s, ver *tem) {
	std::string num[3];
	int head = 0;
	int tail = 0;
	int index = 0;
	while (tail < s.length()) {
		if (tail == s.length() - 1 || s.at(tail) == ',') {
			num[index] = s.substr(head, tail);
			tail++;
			index++;
			head = tail;
			continue;

		}
		tail++;
	}
	tem->x = atof(num[0].c_str());
	tem->y = atof(num[1].c_str());
	tem->z = atof(num[2].c_str());
	//std::cout << tem->z;
}


//读中心坐标文件
ver* readVer(std::string filename) {
	ver *head;
	ver *tem;

	std::string path = "D:\\IDE\\matlab\\bin\\data\\" + filename;

	std::ifstream fin;
	fin.open(path);
	if (!fin)
		return NULL;
	std::string temp;
	head = new ver;
	tem = new ver;
	head->next = tem;
	int len = 0;
	while (getline(fin, temp)) {
		cutVerString(temp, tem);
		len++;
		tem->next = new ver;
		tem = tem->next;
	}
	//std::cout << "points number of " << filename << "is :" << len << std::endl;
	return head;

}






