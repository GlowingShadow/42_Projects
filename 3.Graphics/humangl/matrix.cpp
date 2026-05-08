#include "stdafx.h"
#include "matrix.hpp"


Matrix4::Matrix4() {
	cout << "Matrix4 cons" << endl;
	this->identity();
	this->_order = ROW_MAJOR;
}

Matrix4::Matrix4(Matrix4& src) {
	cout << "Matrix4 cons by copy" << endl;
	*this = src;
}

Matrix4&		Matrix4::operator=(const Matrix4& src) {
	cout << "Matrix4 copy operator" << endl;
	float*	s = src.getData();
	for (int i = 0; i < 16; i++)
		this->e[i] = s[i];
	this->_order = src.getOrder();
	return (*this);
}


Matrix4::~Matrix4() {
	cout << "Matrix4 des" << endl;
}

void			Matrix4::projectionMatrix(float rad, float farv, float nearv, int win_x, int win_y) {
	this->reset();
	this->_order = ROW_MAJOR;
	float		ratio = 1.0f / tanf(rad / 2.0f);
	tab[0][0] = ratio / ((float)win_x / (float)win_y);
	tab[1][1] = ratio;
	tab[2][2] = -(farv + nearv) / (farv - nearv);
	tab[2][3] = -2.0f * farv * nearv / (farv - nearv);
	tab[3][2] = -1.0f;
	this->setOrder(COLUMN_MAJOR);
}

void			Matrix4::viewMatrix(Math::Vector3 camPos, Math::Rotation camRot) {
	this->identity();
	this->_order = ROW_MAJOR;

	float		val[8];
	
	COS_A = cosf(camRot.x);
	SIN_A = sinf(camRot.x);
	COS_B = cosf(camRot.y);
	SIN_B = sinf(camRot.y);
	COS_C = cosf(camRot.z);
	SIN_C = sinf(camRot.z);
	val[6] = COS_A * SIN_B;
	val[7] = SIN_A * SIN_B;
	tab[0][0] = COS_B * COS_C;
	tab[1][0] = val[7] * COS_C + COS_A * SIN_C;
	tab[2][0] = -val[6] * COS_C + SIN_A * SIN_C;
	tab[0][1] = -COS_B * SIN_C;
	tab[1][1] = -val[7] * SIN_C + COS_A * COS_C;
	tab[2][1] = val[6] * SIN_C + SIN_A * COS_C;
	tab[0][2] = SIN_B;
	tab[1][2] = -SIN_A * COS_B;
	tab[2][2] = COS_A * COS_B;
	camPos.rotate(camRot.toRad(), ROT_WAY);
//	res = Math::vector3Rot(camPos, camRot, ROT_WAY);
	tab[0][3] = -camPos.x;
	tab[1][3] = -camPos.y;
	tab[2][3] = -camPos.z;
	this->setOrder(COLUMN_MAJOR);
}

void			Matrix4::modelMatrix(Math::Vector3 pos, Math::Rotation rot) {//add scale
	float		val[8];

	rot.setAsRad();//important
	COS_A = cosf(rot.x);
	SIN_A = sinf(rot.x);
	COS_B = cosf(rot.y);
	SIN_B = sinf(rot.y);
	COS_C = cosf(rot.z);
	SIN_C = sinf(rot.z);
	val[6] = COS_A * SIN_B;
	val[7] = SIN_A * SIN_B;
	this->tab[0][0] = COS_B * COS_C;
	this->tab[1][0] = val[7] * COS_C + COS_A * SIN_C;
	this->tab[2][0] = -val[6] * COS_C + SIN_A * SIN_C;
	this->tab[0][1] = -COS_B * SIN_C;
	this->tab[1][1] = -val[7] * SIN_C + COS_A * COS_C;
	this->tab[2][1] = val[6] * SIN_C + SIN_A * COS_C;
	this->tab[0][2] = SIN_B;
	this->tab[1][2] = -SIN_A * COS_B;
	this->tab[2][2] = COS_A * COS_B;
	this->tab[0][3] = pos.x;
	this->tab[1][3] = pos.y;
	this->tab[2][3] = pos.z;
	this->tab[3][3] = 1.0f;
	this->_order = ROW_MAJOR;//because above calculations are ROW_MAJOR
	this->setOrder(COLUMN_MAJOR);
}

inline void		Matrix4::identity() {
	e[0] = e[5] = e[10] = e[15] = 1.0f;
	e[1] = e[2] = e[3] = e[4] = e[6] = e[7] = e[8] = e[9] = e[11] = e[12] = e[13] = e[14] = 0.0f;
}

inline void		Matrix4::reset() {
	e[0] = e[5] = e[10] = e[15] = 0.0f;
	e[1] = e[2] = e[3] = e[4] = e[6] = e[7] = e[8] = e[9] = e[11] = e[12] = e[13] = e[14] = 0.0f;
}

void		Matrix4::setOrder(uint8_t order) {
	if (order == this->_order)
		return;
	this->_order = order;
	this->transpose();
}

void			Matrix4::transpose() {
	Matrix4	cp(*this);
	float	*v = cp.getData();

	e[1] = v[4];	e[2] = v[8];	e[3] = v[12];
	e[4] = v[1];	e[6] = v[9];	e[7] = v[13];
	e[8] = v[2];	e[9] = v[6];	e[11] = v[14];
	e[12] = v[3];	e[13] = v[7];	e[14] = v[11];
}

void		Matrix4::printData() const {
	if (this->_order == ROW_MAJOR)
		cout << "row major" << endl;
	else
		cout << "column major" << endl;

	cout << std::fixed << std::setprecision(2);
	for (int i = 0; i < 16; i++) {
		cout << this->e[i] << " ";
		if (i % 4 == 3)
			cout << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (this->_order == ROW_MAJOR)
				cout << this->tab[i][j] << " ";
			else
				cout << this->tab[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << std::resetiosflags(std::ios::showbase) << std::defaultfloat;
}

//inline ?
void		Matrix4::updatePosValue(Math::Vector3 pos) {

	if (this->_order == ROW_MAJOR) {
		this->tab[0][3] = pos.x;
		this->tab[1][3] = pos.y;
		this->tab[2][3] = pos.z;
	} else if (this->_order == COLUMN_MAJOR) {
		this->tab[3][0] = pos.x;
		this->tab[3][1] = pos.y;
		this->tab[3][2] = pos.z;
	} else {
		cerr << "Matrix4::_order impossible case: must be either ROW_MAJOR or COLUMN_MAJOR" << endl;
		exit(EXIT_FAILURE);
	}

}

void		Matrix4::updateRotValue(Math::Rotation rot) {
	float		val[8];

	rot.setAsRad();//important
	COS_A = cosf(rot.x);
	SIN_A = sinf(rot.x);
	COS_B = cosf(rot.y);
	SIN_B = sinf(rot.y);
	COS_C = cosf(rot.z);
	SIN_C = sinf(rot.z);
	val[6] = COS_A * SIN_B;
	val[7] = SIN_A * SIN_B;
	this->transpose();
	this->tab[0][0] = COS_B * COS_C;
	this->tab[1][0] = val[7] * COS_C + COS_A * SIN_C;
	this->tab[2][0] = -val[6] * COS_C + SIN_A * SIN_C;
	this->tab[0][1] = -COS_B * SIN_C;
	this->tab[1][1] = -val[7] * SIN_C + COS_A * COS_C;
	this->tab[2][1] = val[6] * SIN_C + SIN_A * COS_C;
	this->tab[0][2] = SIN_B;
	this->tab[1][2] = -SIN_A * COS_B;
	this->tab[2][2] = COS_A * COS_B;
	this->transpose();
}

//mutator
//accessor
float*				Matrix4::getData() const { return (float*)(this->e); }
uint8_t				Matrix4::getOrder() const { return this->_order; }
