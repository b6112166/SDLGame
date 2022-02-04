#pragma once

//interface class
class Entity
{

public:
	Entity() { x = 0.0; y = 0.0; type = -1; };

	~Entity() {};

	enum direction { d_up, d_down, d_left, d_right, d_topleft, d_topright, d_downleft, d_downright };

protected:
	int type;
	//bool visible;
	float x ;
	float y ;

	

private:
};

