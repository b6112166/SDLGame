#pragma once
extern enum direction { d_up, d_down, d_left, d_right, d_upleft, d_upright, d_downleft, d_downright };
//interface class
class Entity
{

public:
	Entity() { x = 0.0; y = 0.0; type = -1; };

	~Entity() {};

	int getPosX() { return x; };
	int getPosY() { return y; };

protected:
	int type;
	//bool visible;
	int x ;
	int y ;

	

private:
};

