#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
// ���ĵ�����
struct ver {
	double x;
	double y;
	double z;
	int index;
	ver *next=NULL;
};

//��voronoiȦ
struct VoronoiareaPoints {
	int index;//��������
	VoronoiareaPoints *next=NULL;

};

//voronoiͼ��Ϣ
struct VoronoiInfo {
	VoronoiareaPoints *area_index; //��άŵͼ�ĸ�����������
	double theta_max; //�ڽ�
	double theta_min;
	double gama; //���ܶ�
	double center_points[3]; //���ĵ�����     
	
	int index; //ͼ��������    
	VoronoiInfo *next = NULL;
};

//����
struct PointsPairs {
	int index_a; //����
	int index_b;
	PointsPairs *next = NULL;
};



