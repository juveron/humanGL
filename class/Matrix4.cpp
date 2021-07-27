#include "../hdr/HumanGL.hpp"

Matrix4::Matrix4(void) : matrix{}
{
	this->matrix[0] = 1;
	this->matrix[5] = 1;
	this->matrix[10] = 1;
	this->matrix[15] = 1;
}

Matrix4::Matrix4(float const matrix_[16])
{
	int i = -1;

	while (++i < 16)
		this->matrix[i] = matrix_[i];
}

Matrix4::Matrix4(Matrix4 const &c) : matrix{}
{
	int i = 0;
	while (i < 16)
	{
		this->matrix[i] = c.matrix[i];
		i++;
	}
}

Matrix4::~Matrix4(void)
{
}

void Matrix4::rotateXAxis(float const angle)
{
	this->multiply(Matrix4::newXRotationMatrix(angle));
}

void Matrix4::rotateYAxis(float const angle)
{
	this->multiply(Matrix4::newYRotationMatrix(angle));
}

void Matrix4::rotateZAxis(float const angle)
{
	this->multiply(Matrix4::newZRotationMatrix(angle));
}

void Matrix4::print(void)
{
	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			std::cout << std::setw(5) << this->matrix[j * 4 + i] << ",";
			j++;
		}
		std::cout << std::endl;
		i++;
	}
}

void Matrix4::translate(float const x, float const y, float const z)
{
	this->matrix[12] += x;
	this->matrix[13] += y;
	this->matrix[14] += z;
	// std::cout << "Translate" << std::endl;
}

void Matrix4::translate(float const xyz)
{
	this->matrix[12] += xyz;
	this->matrix[13] += xyz;
	this->matrix[14] += xyz;
	// std::cout << "Translate" << std::endl;
}

void Matrix4::scale(float const x, float const y, float const z)
{
	this->matrix[0] *= x;
	this->matrix[5] *= y;
	this->matrix[10] *= z;
	// std::cout << "Scale" << std::endl;
}

void Matrix4::scale(float const xyz)
{
	this->matrix[0] *= xyz;
	this->matrix[5] *= xyz;
	this->matrix[10] *= xyz;
	// std::cout << "Scale" << std::endl;
}

void Matrix4::rotate(float const angle, e_axis const axis)
{
	if (axis == X_AXIS) {
		this->rotateXAxis(angle);
		// std::cout << "Rotate X_AXIS" << std::endl;
	}
	else if (axis == Y_AXIS) {
		this->rotateYAxis(angle);
		// std::cout << "Rotate Y_AXIS" << std::endl;
	}
	else if (axis == Z_AXIS) {
		this->rotateZAxis(angle);
		// std::cout << "Rotate Z_AXIS" << std::endl;
	}
}

void Matrix4::multiply(Matrix4 const &mat)
{
	Matrix4 tmp(*this);

	int i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			this->matrix[i * 4 + j] = 0;
			int k = -1;
			while (++k < 4)
				this->matrix[i * 4 + j] += tmp.matrix[i * 4 + k] * mat.matrix[k * 4 + j];
			j++;
		}
		i++;
	}
}

void Matrix4::multiply(float const num)
{
	int i = -1;
	while (++i < 16)
		this->matrix[i] *= num;
}

void Matrix4::add(Matrix4 const &mat)
{
	int i = -1;

	while (++i < 16)
		this->matrix[i] += mat.matrix[i];
}

void Matrix4::substract(Matrix4 const &mat)
{
	int i = -1;

	while (++i < 16)
		this->matrix[i] -= mat.matrix[i];
}

Matrix4 &Matrix4::operator+=(Matrix4 const &rhs)
{
	this->add(rhs);
	return (*this);
}

Matrix4 &Matrix4::operator-=(Matrix4 const &rhs)
{
	this->substract(rhs);
	return (*this);
}

Matrix4 &Matrix4::operator*=(Matrix4 const &rhs)
{
	this->multiply(rhs);
	return (*this);
}

Matrix4 &Matrix4::operator*=(float const &rhs)
{
	this->multiply(rhs);
	return (*this);
}

Matrix4 &Matrix4::operator=(Matrix4 const &rhs)
{
	int i = -1;
	while (++i < 16)
		this->matrix[i] = rhs.matrix[i];
	return (*this);
}

Matrix4 Matrix4::newXRotationMatrix(float const angle)
{
	Matrix4 mat;

	mat.matrix[0] = 1;
	mat.matrix[5] = std::cos(angle * PI / 180.0);
	mat.matrix[6] = std::sin(angle * PI / 180.0);
	mat.matrix[9] = -std::sin(angle * PI / 180.0);
	mat.matrix[10] = std::cos(angle * PI / 180.0);
	return mat;
}

Matrix4 Matrix4::newYRotationMatrix(float const angle)
{
	Matrix4 mat;

	mat.matrix[0] = std::cos(angle * PI / 180.0);
	mat.matrix[2] = -std::sin(angle * PI / 180.0);
	mat.matrix[5] = 1;
	mat.matrix[8] = std::sin(angle * PI / 180.0);
	mat.matrix[10] = std::cos(angle * PI / 180.0);
	return mat;
}

Matrix4 Matrix4::newZRotationMatrix(float const angle)
{
	Matrix4 mat;

	mat.matrix[0] = std::cos(angle * PI / 180.0);
	mat.matrix[1] = std::sin(angle * PI / 180.0);
	mat.matrix[4] = -std::sin(angle * PI / 180.0);
	mat.matrix[5] = std::cos(angle * PI / 180.0);
	mat.matrix[10] = 1;
	return mat;
}

Matrix4 Matrix4::newRotationMatrix(float const angle, e_axis const axis)
{
	if (axis == X_AXIS)
		return Matrix4::newXRotationMatrix(angle);
	else if (axis == Y_AXIS)
		return Matrix4::newYRotationMatrix(angle);
	else if (axis == Z_AXIS)
		return Matrix4::newZRotationMatrix(angle);
	return Matrix4();
}

Matrix4 Matrix4::newIdentityMatrix(void)
{
	Matrix4 mat;
	return mat;
}

Matrix4 Matrix4::newProjectionMatrix(float fov, float aspectRatio, float znear, float zfar)
{
	Matrix4			mat;
	float			x_scale;
	float			y_scale;
	float			fovRad = 1 / std::tan(0.5 * fov * PI / 180.0);

	mat.matrix[0] = aspectRatio * fovRad;
	mat.matrix[5] = fovRad;
	mat.matrix[10] = zfar / (zfar - znear);
	mat.matrix[11] = 1;
	mat.matrix[14] = -(zfar * znear) / (zfar - znear);
	mat.matrix[15] = 1;
	return (mat);
}

Matrix4 Matrix4::newLookAtMAt(Vector3f pos, Vector3f target, Vector3f up)
{
	Matrix4 mat;
	Vector3f camDir = (pos - target);
	camDir.normalize();
	Vector3f camRight = camDir.crossProduct(up);
	camRight.normalize();
	Vector3f camUp = camRight.crossProduct(camDir);

	mat.matrix[0] = camRight.x;
	mat.matrix[1] = camUp.x;
	mat.matrix[2] = camDir.x;
	mat.matrix[4] = camRight.y;
	mat.matrix[5] = camUp.y;
	mat.matrix[6] = camDir.y;
	mat.matrix[8] = camRight.z;
	mat.matrix[9] = camUp.z;
	mat.matrix[10] = camDir.z;
	mat.matrix[12] = -camRight.dotProduct(target);
	mat.matrix[13] = -camUp.dotProduct(target);
	mat.matrix[14] = -camDir.dotProduct(target);

	return mat;
}

Matrix4 operator+(Matrix4 const &lhs, Matrix4 const &rhs)
{
	Matrix4 tmp(lhs);
	tmp += rhs;
	return tmp;
}

Matrix4 operator-(Matrix4 const &lhs, Matrix4 const &rhs)
{
	Matrix4 tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Matrix4 operator*(Matrix4 const &lhs, Matrix4 const &rhs)
{
	Matrix4 tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Matrix4 operator*(Matrix4 const &lhs, float const &rhs)
{
	Matrix4 tmp(lhs);
	tmp *= rhs;
	return tmp;
}

