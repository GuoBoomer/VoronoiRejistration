
#include "pch.h"
#include "PointRegistration.h"



/*
���캯����
��ʼ��voronoiͼvhead,vlength��ÿ��voronoi�ڵ�����򶥵�����
���������С�ڽ�theta,�������ܶ�gama
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
	//��ʼ��head,vlength��ÿ��voronoi�ڵ�����򶥵�����
	while (t!= NULL) {


		//��ʼ��voronoiͼ���򶥵�����
		
		
		vp=this->readVoronoiareaPoints(filename,length);
		tem->area_index = vp;
		//ͼ�������
		tem->index = length+1; 
		length++;
		//���ĵ�����
		tem->center_points[0] = t->x;
		tem->center_points[1] = t->y;
		tem->center_points[2] = t->z;

		tem->next = new VoronoiInfo;
		tem = tem->next;
		t = t->next;
	}
	
	//���һ���ǿյ�
	vlength = length;
	std::cout << "Initialization of VoronoiInfo and VoronoiareaPoints is finished,the length of voronoi diagram is:"
		<<length<<"."<<std::endl
		<<"Start to calculate the value of theta."<<std::endl;


	//��ʼ��theta
	this->calculateTheta();
}

/**************************************************************************************************/
//���������С�ڽ�
void PointRegistration::calculateTheta()
{
	VoronoiInfo *tem = this->vhead->next;
	if (tem == NULL) {
		std::cout << "The value of vhead is null,fail to calculate the theta"<<std::endl;
		return;
	}
	//��������info
	while (tem != NULL) {
		calculateEveryInfo(tem);
		tem = tem->next;
	}

}
//�㶨����info��theta
void PointRegistration::calculateEveryInfo(VoronoiInfo * node)
{
	VoronoiareaPoints *tem = node->area_index;
	double max=0;
	double min; //Ӧ�ó�ʼ�����ǣ�Ӧ����360


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
//�ӵ�length�п�ʼ����ȡ��Χ������Ϣ
VoronoiareaPoints* PointRegistration::readVoronoiareaPoints(std::string filename, int length)
{
	VoronoiareaPoints *head = new VoronoiareaPoints;  //ͷ���
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
//�е�
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

