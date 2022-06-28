#include <iostream>

class point
{
      public:
	point(int x, int y) : x_{x}, y_{y} {};

	friend point	     operator+(point const &lhs, point const &rhs);
	friend std::ostream &operator<<(std::ostream &os, point const &p);

      private:
	int x_;
	int y_;
};

point operator+(point const &lhs, point const &rhs)
{
	return point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}

std::ostream& operator<<(std::ostream& os, point const& p) {
	os << "(" << p.x_ << "," << p.y_ << ")";
	return os;
}

int main(int argc, char *argv[])
{
	point p1{1, 2};
	point p2{3, 4};
	std::cout << p1 + p2 << std::endl;
	return 0;
}
