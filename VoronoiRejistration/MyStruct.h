#pragma once

#include<iostream>
#include<fstream>
#include<sstream>
// 中心点坐标
struct ver {
	double x;
	double y;
	double z;
	int index;
	ver *next=NULL;
};

//存voronoi圈
struct VoronoiareaPoints {
	int index;//顶点索引
	VoronoiareaPoints *next=NULL;

};

//voronoi图信息
struct VoronoiInfo {
	VoronoiareaPoints *area_index; //此维诺图的各个顶点索引
	double theta_max; //内角
	double theta_min;
	double gama; //致密度
	double center_points[3]; //中心点坐标     
	
	int index; //图的索引号    
	VoronoiInfo *next = NULL;
};

//存点对
struct PointsPairs {
	int index_a; //索引
	int index_b;
	PointsPairs *next = NULL;
};



