#include <iostream>
#include <math.h>

struct point{
	int x,y;
	point(int x, int y): x(x),y(y) {}
	bool operator < (const point &o) const{
		return x < o.x;
	}
};

struct vec{
	int dx, dy;
	vec(point &a, point &b){
		dx = b.x - a.x;
		dy = b.y - a.y;
	}
};

struct line{
	point p0, p1;
	line(point &p0, point &p1): p0(p0), p1(p1) {}
};

int dot(vec &u, vec &v){
	return (u.dx * v.dy) + (u.dy * v.dx);
}

int cross(vec &v0, vec &v1){
	return v1.dy * v0.dx - v1.dx * v0.dy;
}

int ccw(point &a, point &b, point &c){
	int k1t = b.y-a.y;
	int k1b = b.x-a.x;
	int k2t = c.y-b.y;
	int k2b = c.x-b.x;
	int n1 = k1t * k2b;
	int n2 = k2t * k1b;
	return n1 - n2;  
}

double dist_point(point a, point b){
	return sqrt((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y));
}

double dist_point_to_line(point l0, point l1, point p){
	return abs(((l0.y - l1.y) * p.x + (l1.x - l0.x) * p.y + (l0.x * l1.y - l1.x * l0.y))/dist_point(l0,l1));
} 

double dist_line(point l0, point l1, point p){
	vec vl(l0,l1);
	vec w(l0,p);
	double vldist = dist_point(l0,l1);
	int crossm = cross(vl,w);
	return crossm/vldist;	
} 

double dist_point_to_line(line l, point p){
	vec v(l.p0, l.p1);
	vec w(l.p0,p);
	int c1 = dot(w,v);
	int c2 = dot(v,v);
	double k = double(c1)/double(c2);	
	point perp(l.p0.x + k * v.dx, l.p0.y + k * v.dy); 
	return dist_point(p,perp);
} 

int main(){
	point a(0,0), b(0,1), c(1,1);
	std::cout << (a < c) << std::endl;
	std::cout << ccw(a,b,c) << std::endl;
	std::cout << ccw(a,c,b) << std::endl;

	point p1(0,0), p2(0,5), p3(3,3); 
	line l1(p1,p2);
	//std::cout << dist_point_to_line(l1, p3) << std::endl; 
	std::cout << dist_point_to_line(p1,p2,p3) << std::endl; 
	std::cout << dist_line(p1,p2,p3) << std::endl; 
	point p4(0,0), p5(4,4), p6(0,4); 
	std::cout << dist_point_to_line(p4,p5,p6) << std::endl; 
	std::cout << dist_line(p4,p5,p6) << std::endl; 
	return 0;
}
