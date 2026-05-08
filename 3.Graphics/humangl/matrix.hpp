#pragma once
#include "stdafx.h"
#include <vector>
#include <iomanip>
#include "math.hpp"

#define ROW_MAJOR		0
#define COLUMN_MAJOR	1
#define ROT_RIGHT		-1
#define ROT_LEFT		1
#define ROT_WAY			1

class Matrix4
{
public:
	Matrix4();
	Matrix4(Matrix4& src);
	Matrix4&	operator=(const Matrix4& mat);
	~Matrix4();

	//add scale
	void		projectionMatrix(float rad, float farv, float nearv, int win_x, int win_y);
	void		viewMatrix(Math::Vector3 camPos, Math::Rotation camRot);
	void		modelMatrix(Math::Vector3 pos, Math::Rotation rot);
	void		identity();
	void		reset();
	void		setOrder(uint8_t order);
	void		transpose();
	void		printData() const;

	void		updatePosValue(Math::Vector3 pos);
	void		updateRotValue(Math::Rotation rot);
	//void		updateScaleValue();

	//static
	//mutator
	//accessor
	float*			getData() const;
	uint8_t			getOrder() const;

private:
	union {
		float	e[16];
		float	tab[4][4];
	};
	uint8_t		_order;
};
