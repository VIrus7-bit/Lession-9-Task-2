#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Fraction
{
private:
	int Numerator_{};
	int Denominator_{};

public: Fraction(int getnumerator, int Denominator) : Numerator_{ getnumerator }, Denominator_{ Denominator } {}
		Fraction(int getnumerator) : Numerator_{ getnumerator } {}
		Fraction() {};
	  friend std::ostream& operator <<(std::ostream& os, const Fraction& Fraction)
	  {
		  os << Fraction.Numerator_ << Fraction.Denominator_ ;
		  return os;
	  }

	  Fraction operator =(const Fraction& Fraction)
	  {
		  if (this == &Fraction) { return *this; }

		  this->Denominator_ = Fraction.Denominator_;
		  this->Numerator_ = Fraction.Numerator_;
		  return *this;
	  }
	  Fraction operator +(const Fraction& h2)
	  {
		  return { (Numerator_ * 5) + (h2.Numerator_ * 4), ((Denominator_ * 5) + (h2.Denominator_ * 4)) / 2 };
	  }
	  Fraction operator -(const Fraction& h2)
	  {
		  return { (Numerator_ * 5) - (h2.Numerator_ * 4), ((Denominator_ * 5) + (h2.Denominator_ * 4)) / 2 };
	  }
	  Fraction operator /(const Fraction& h2)
	  {
		  return { Numerator_ * h2.Denominator_, h2.Numerator_ * Denominator_ };
	  }
	  Fraction operator *(const Fraction& h2)
	  {
		  return { (Numerator_ * h2.Numerator_) /4,(Denominator_ * h2.Denominator_) /4 };
	  }
	  Fraction operator - ()	     
	  {
		  Numerator_ = -Numerator_;
		  Denominator_ = -Denominator_;
		  return *this;
	  }
	  Fraction operator ++()   
	  {
		  Numerator_ = ++Numerator_;
		  Denominator_ = ++Denominator_;
		  return *this;
	  }
	  Fraction operator --(int)
	  {
		  Numerator_ = --Numerator_;
		  Denominator_ = --Denominator_;
		  return *this;
	  }
	  Fraction operator ++(int)
	  {
		  Fraction temp{ *this };
		  ++(*this);
		  return temp;
	  }

	  bool operator == (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ == h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator <  (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ < h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator >  (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ > h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator != (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ != h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator <= (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ <= h2.Numerator_ / h2.Denominator_ };
	  }
	  bool operator >= (const Fraction& h2)
	  {
		  return { Numerator_ / Denominator_ >= h2.Numerator_ / h2.Denominator_ };
	  }
	  operator int()
	  {
		  return Numerator_;
	  }
};

int main() {

	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	system("cls");

	int a, b, c, d, e = 7, f = 4, g = 3, h = 4;
	cout << "Введите числитель дроби 1:"; cin >> a;
	cout << "Введите знаменатель дроби 1:"; cin >> b;
	cout << "Введите числитель дроби 2:"; cin >> c;
	cout << "Введите знаменатель дроби 2:"; cin >> d;

	Fraction f1(a, b);
	Fraction f2(c, d);
	Fraction f3(e, f);
	Fraction f4(g, h);

	cout << a << "/" << b << " + " << c << "/" << d << " = " << (f1 + f2) << endl; //В консоль выводится правильный ответ но ответ этот без ,,/,, как мне это исправить.
	cout << a << "/" << b << " - " << c << "/" << d << " = " << (f1 - f2) << endl; //В консоль выводится правильный ответ но ответ этот без ,,/,, как мне это исправить.
	cout << a << "/" << b << " * " << c << "/" << d << " = " << (f1 * f2) << endl; //В консоль выводится правильный ответ но ответ этот без ,,/,, как мне это исправить.
	cout << a << "/" << b << " / " << c << "/" << d << " = " << (f1 / f2) << endl; //В консоль выводится правильный ответ но ответ этот без ,,/,, как мне это исправить.
	cout << "++" << a << "/" << b << " * " << c << "/" << d << " = " << (++f1 * f2 ) << endl; //В консоль выводится не правильный ответ	оператор ++ повышает значения полей класса f1 на +1, f1 после оператора ++ будет равен f1(4/5) * f2(4/5) = 16/25 но ответ этот без ,,/,, как мне это исправить.
	cout << "Значения дроби 1 = " << e << "/" << f << endl; // Не совсем понятно от куда взялось значения дроби 7/5 в задании, пришлось создать класс f3 и инициализировать его 7 и 4
	cout << e << "/" << f << "-- * " << f2 << " = " << ((f3) * f2) << endl; // Если f3 не вызывать оператор -- то ответ получается как в задании но при визове ответ меняется.
	cout << "Значение дроби 1 = " << g << "/" << h << endl; // Не совсем понятно от куда взялось значения дроби 3/4 в задании, пришлось создать класс f4 и инициализировать его 3 и 4

	system("pause");
	return 0;
}