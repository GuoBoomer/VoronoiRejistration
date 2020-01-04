
#include "pch.h"
#include "PointRegistration.h"



/*
构造函数：
初始化voronoi图vhead,vlength与每个voronoi节点的区域顶点索引
计算最大最小内角theta,计算致密度gama
*/
PointRegistration::PointRegistration(ver *head,std::string filename)
{
	std::cout <<"Start to deal the file " <<filename << ": " << std::endl;

	ver *t = head->next;
	VoronoiInfo *tem;
	tem = new VoronoiInfo;
	VoronoiareaPoints *vp;
	vhead->next = tem;
	int length = 0;
	//初始化head,vlength与每个voronoi节点的区域顶点索引
	while (t!= NULL) {


		//初始化voronoi图区域顶点索引
		
		
		vp=this->readVoronoiareaPoints(filename,length);
		tem->area_index = vp;
		//图序号索引
		tem->index = length+1; 
		length++;
		//中心点坐标
		tem->center_points[0] = t->x;
		tem->center_points[1] = t->y;
		tem->center_points[2] = t->z;

		tem->next = new VoronoiInfo;
		tem = tem->next;
		t = t->next;
	}
	
	//最后一行是空的
	vlength = length;
	std::cout << "Initialization of VoronoiInfo and VoronoiareaPoints is finished,the length of voronoi diagram is:"
		<<length<<"."<<std::endl
		<<"Start to calculate the value of theta."<<std::endl;


	//开始整theta
	this->calculateTheta();
}

/**************************************************************************************************/
//计算最大最小内角
void PointRegistration::calculateTheta()
{
	VoronoiInfo *tem = this->vhead->next;
	if (tem == NULL) {
		std::cout << "The value of vhead is null,fail to calculate the theta"<<std::endl;
		return;
	}
	//遍历所有info
	while (tem != NULL) {
		calculateEveryInfo(tem);
		tem = tem->next;
	}

}
//搞定单个info的theta
void PointRegistration::calculateEveryInfo(VoronoiInfo * node)
{
	VoronoiareaPoints *tem = node->area_index;
	double max=0;
	double min; //应该初始化最大角，应该是360


}

void PointRegistration::calculateSingalTheta(double max, double min, int index)
{
}
/**************************************************************************************************/


PointRegistration::~PointRegistration()
{
}

void PointRegistration::setEpsilon(double num)
{
}



void PointRegistration::calculateGama()
{
}

void PointRegistration::initialRegistration()
{
}


/**************************************************************************************************/
//从第length行开始，读取周围顶点信息
VoronoiareaPoints* PointRegistration::readVoronoiareaPoints(std::string filename, int length)
{
	VoronoiareaPoints *head = new VoronoiareaPoints;  //头结点
	VoronoiareaPoints *tem;
	tem = head;

	head->index = -1;
	std::string path = "D:\\IDE\\matlab\\bin\\data\\" + filename;
	std::ifstream fin;
	fin.open(path);
	if (!fin)
		return NULL;

	std::string temp;
	int flag = 0;
	while (getline(fin, temp)) {
		if (flag == length) {

			cutVoronoiareaPoints(temp, tem);
			break;
		}
		flag++;
	}

	/*tem = head;
	while (tem->next != NULL) {
		tem = tem->next;
		std::cout << tem ->index << " ";
	}
	std::cout << std::endl;*/
	return head;
}
//切点
void PointRegistration::cutVoronoiareaPoints(std::string s_of_points, VoronoiareaPoints * tem)
{
	std::string num;
	int head = 0;
	int tail = 0;
	int index = 0;
	while (tail < s_of_points.length()) {
		if (tail == s_of_points.length() - 1 || s_of_points.at(tail) == ',') {

			tem->next = new VoronoiareaPoints;
			tem = tem->next;
			num = s_of_points.substr(head, tail);
			tail++;
			index++;
			head = tail;
			tem->index = atof(num.c_str());
			continue;
		}
		tail++;
	}
}
/**************************************************************************************************/

