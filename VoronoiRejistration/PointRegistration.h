#pragma once
#include"MyStruct.h"


class PointRegistration
{
private:
	VoronoiareaPoints* readVoronoiareaPoints(std::string filename, int length);
	void cutVoronoiareaPoints(std::string s_of_points, VoronoiareaPoints* tem);
	
	void calculateTheta(); //计算Theta值的主流程函数，大小都算
	void calculateEveryInfo(VoronoiInfo *node);
	void calculateSingalTheta(double max, double min,int index); //计算单个theta

public:

	VoronoiInfo *vhead =new VoronoiInfo;//头指针 指向所有VoronoiInfo区域
	PointsPairs *phead =new PointsPairs; //点对索引链表的结构体
	int vlength = 0; //Info链表的长度
	int plength = 0; //点对索引列表的长度
	double epsilon; //经验阈值


	PointRegistration(ver *head,std::string filename);
	~PointRegistration();
	void setEpsilon(double num); //设置经验阈值
	void calculateGama();  //计算gama
	void initialRegistration(); //进行初始配准，获得匹配后的点对 并把phead、plength初始化
};

