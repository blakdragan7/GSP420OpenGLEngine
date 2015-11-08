#pragma once

template <class t>
class Vector2D
{
public:
	t x;
	t y;


	Vector2D(void): x(0),y(0){}
	Vector2D(t x_,t y_):x(x_),y(y_){}

	~Vector2D(void){}

	Vector2D operator -(Vector2D other)
	{
		Vector2D ret = *this;
		ret.x -= other.x;
		ret.y -= other.y;

		return ret;
	}

	Vector2D operator +(Vector2D other)
	{
		Vector2D ret = *this;
		ret.x += other.x;
		ret.y += other.y;

		return ret;
	}

	Vector2D operator *(Vector2D other)
	{
		Vector2D ret = *this;
		ret.x *= other.x;
		ret.y *= other.y;

		return ret;
	}

	Vector2D operator /(Vector2D other)
	{
		Vector2D ret = *this;
		ret.x /= other.x;
		ret.y /= other.y;

		return ret;
	}

	Vector2D operator =(Vector2D other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	Vector2D operator -=(Vector2D other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2D operator +=(Vector2D other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2D operator *=(Vector2D other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vector2D operator /=(Vector2D other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	Vector2D operator -(t scalor)
	{
		Vector2D ret = *this;
		ret.x -= scalor;
		ret.y -= scalor;

		return ret;
	}

	Vector2D operator +(t scalor)
	{
		Vector2D ret = *this;
		ret.x += scalor;
		ret.y += scalor;

		return ret;
	}

	Vector2D operator *(t scalor)
	{
		Vector2D ret = *this;
		ret.x *= scalor;
		ret.y *= scalor;

		return ret;
	}

	Vector2D operator /(t scalor)
	{
		Vector2D ret = *this;
		ret.x /= scalor;
		ret.y /= scalor;

		return ret;
	}

	Vector2D operator -=(t scalor)
	{
		x -= scalor;
		y -= scalor;

		return *this;
	}

	Vector2D operator +=(t scalor)
	{
		x += scalor;
		y += scalor;

		return *this;
	}

	Vector2D operator *=(t scalor)
	{
		x *= scalor;
		y *= scalor;

		return *this;
	}

	Vector2D operator /=(t scalor)
	{
		x /= scalor;
		y /= scalor;

		return *this;
	}

	Vector2D operator =(t scalor)
	{
		x = scalor;
		y = scalor;

		return *this;
	}

	void rotate(Vector2D origin,float angle /*radians*/)
	{
		Vector2D p(*this);
	  
		float s = sin(angle);
		float c = cos(angle);

		// translate point back to origin:
		p.x -= origin.x;
		p.y -= origin.y;

		// rotate point
		float xnew = p.x * c - p.y * s;
		float ynew = p.x * s + p.y * c;

		// translate point back:
		p.x = xnew + origin.x;
		p.y = ynew + origin.y;

		x = p.x;
		y = p.y;
	}

	t magnitude()
	{
		return sqrt((x*x) + (y*y));
	}

	void normalize()
	{
		t mag = magnitude();
		*this /= mag;
	}
};

typedef Vector2D<int>		Vec2I;
typedef Vector2D<float>		Vec2F;
typedef Vector2D<double>	Vec2D;