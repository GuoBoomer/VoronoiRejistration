#pragma once
#include"MyStruct.h"


class PointRegistration
{
private:
	VoronoiareaPoints* readVoronoiareaPoints(std::string filename, int length);
	void cutVoronoiareaPoints(std::string s_of_points, VoronoiareaPoints* tem);
	
	void calculateTheta(); //����Thetaֵ�������̺�������С����
	void calculateEveryInfo(VoronoiInfo *node);
	void calculateSingalTheta(double max, double min,int index); //���㵥��theta

public:

	VoronoiInfo *vhead =new VoronoiInfo;//ͷָ�� ָ������VoronoiInfo����
	PointsPairs *phead =new PointsPairs; //�����������Ľṹ��
	int vlength = 0; //Info����ĳ���
	int plength = 0; //��������б�ĳ���
	double epsilon; //������ֵ


	PointRegistration(ver *head,std::string filename);
	~PointRegistration();
	void setEpsilon(double num); //���þ�����ֵ
	void calculateGama();  //����gama
	void initialRegistration(); //���г�ʼ��׼�����ƥ���ĵ�� ����phead��plength��ʼ��
};

