template <class elemType> class Complex; //this extra step for templates with friends 
template <class elemType> 
std::ostream& operator<<(std::ostream&, const Complex<elemType>&);
template <class elemType>
std::istream& operator>>(std::istream&, Complex<elemType>&);


template <class elemType>
class Complex {
	
	public:
		Complex(elemType, elemType);
	
		void setReal(elemType);
		void setImagine(elemType);
		elemType getReal() {return this->real;}
		elemType getImagine() {return this->imagine;}


		Complex operator+(const Complex&);
		Complex operator-(const Complex&);
		Complex operator*(const Complex&);
		void    operator=(const Complex&);

		
		friend std::ostream& operator<< <>(std::ostream&, const Complex<elemType>&);
		friend std::istream& operator>> <>(std::istream&, Complex<elemType>&);

	private:
		elemType real, imagine;
};

template <class elemType>
Complex<elemType>::Complex(elemType real, elemType imagine) {
	this->real = real;
	this->imagine = imagine;
}

template <class elemType>
void Complex<elemType>::setReal(elemType real) {
	this->real = real;
}

template <class elemType>
void Complex<elemType>::setImagine(elemType imagine) {
	this->imagine = imagine;
}

template <class elemType>
Complex<elemType> Complex<elemType>::operator+(const Complex& other) {
	return Complex<elemType>(this->real + other.real, this->imagine + other.imagine);
}

template <class elemType>
Complex<elemType> Complex<elemType>::operator-(const Complex& other) {
	return Complex<elemType>(this->real - other.real, this->imagine - other.imagine);
}

template <class elemType>
Complex<elemType> Complex<elemType>::operator*(const Complex& other) {
	return Complex<elemType>((this->real * other.real - (this->imagine * other.imagine)),
				 (this->real * other.imagine + (this->imagine * other.real))); 
}

template <class elemType>
void Complex<elemType>::operator=(const Complex& other) {
	this->real = other.real;
	this->imagine = other.imagine;
}


template <class elemType>
std::ostream& operator<<(std::ostream& out, const Complex<elemType>& cmplx) {
	return out << cmplx.real << " + " << cmplx.imagine << "i";
}

template <class elemType>
std::istream& operator>> (std::istream& in , Complex<elemType>& cmplx) {
	char dummy; //to catch the + character
	in >> cmplx.real >> dummy >> cmplx.imagine;
	return in;
}
