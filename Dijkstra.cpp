/*Name: Dijkstra
Compiler: Dev-C++ 5.8.0
Coded by: Jianyu Chen
Place: Middelburg, the Netherlands
Function: use Dijkstra to caculate the minimnum distance between strart point and other points
Time: 4th,Jan,2017 
*/
#include<iostream>
#include<vector>
#define max 9999                                      ///a large number, it should be larger than any distance
using namespace std;
class Dijkstra{
	public:
	vector<int> result;                               ////the result of algerithm
	int startpoint,num_point;
	Dijkstra(int num,int startpoint);                
	void addline(int point1,int point2,int weight);
	void begin();
	void show();
	private:
		int min,minpoint;
		vector<vector<int> > distance;                ////the array to store the distance information between points
		
		vector<bool> S,V;                             ////the arrays to store whether a point is caculated or not, true in S means caculated, in V means not
}; 
/////initialization of some parameters
////num is the numebr of all points, the program will give each point a number, from 0
Dijkstra::Dijkstra(int num,int startpoint){
	min=max;
	num_point=num;
	this->startpoint=startpoint;
	distance.resize(num);
	S.resize(num);
	V.resize(num);
	result.resize(num);
	for(int i=0;i<num;i++){
		distance[i].resize(num);
		S[i]=false;
		V[i]=true;
	}
	for(int i=0;i<num;i++)
	   for(int j=0;j<num;j++)
	      distance[i][j]=max;
	for(int i=0;i<num;i++)
	distance[i][i]=0;
}
/////add lines between points, weight is the distance between points
void Dijkstra::addline(int point1,int point2,int weight){
	distance[point1][point2]=weight;
	distance[point2][point1]=weight;
}
/////use the algerithm to caculate the minimum distance between the start point and the other points
void Dijkstra::begin(){	
    ////move the start point from the uncaculated array to caculated array 
	S[startpoint]=true;
	V[startpoint]=false;
	for(int i=0;i<num_point;i++)
	result[i]=distance[startpoint][i];
/////use iteration caculate all points 
	for(int j=0;j<num_point-1;j++){
	min=max;
	for(int i=0;i<num_point;i++){
		if( V[i]&&(min>result[i]) ){   /////choose the nearest point
			min=result[i];
			minpoint=i;	
		}
	}
	S[minpoint]=true;                  ////move the nearest point
	V[minpoint]=false;
	for(int i=0;i<num_point;i++)
	result[i]=(distance[minpoint][i]+result[minpoint]<result[i])?(distance[minpoint][i]+result[minpoint]):result[i];  ///recaculate the nearst distance
}
}
//////show the result
void Dijkstra::show(){
	cout<<"start point:"<<startpoint<<endl;
	for(int i=0;i<num_point;i++){
		cout<<"minimum distance between start point and the point"<<i<<" is "<<result[i]<<"  "<<endl;
	}
	
}

int main(void){
	Dijkstra mygraph(5,2);
	mygraph.addline(0,1,10);
	mygraph.addline(0,4,100);
	mygraph.addline(0,3,30);
	mygraph.addline(1,2,50);
	mygraph.addline(2,4,10);
	mygraph.addline(3,4,60);
	mygraph.addline(2,3,20);
	mygraph.begin();
	mygraph.show();
	return 0;
}
