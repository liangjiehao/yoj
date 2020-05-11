#include <iostream>
using namespace std;
class Complex{
	private:
		double _re;
		double _im;
	public:
		Complex(double re,double im=0){
			_re=re;
			_im=im;
		}
		void show(){
			if (!_im && _re)cout<<_re<<endl;
			else if (!_re && _im)cout<<_im<<'i'<<endl;
			else if (!_re && !_im)cout<<0<<endl;
			else if (_im < 0)cout<<_re<<_im<<'i'<<endl;
				else cout<<_re<<'+'<<_im<<'i'<<endl;
		}
		void add(const Complex & c2){
			this->_re=this->_re+c2._re;
			this->_im=this->_im+c2._im;
		}
		void sub(const Complex & c1){
			this->_re=this->_re-c1._re;
			this->_im=this->_im-c1._im;
		}
};

int main()
{
	double re, im;
	cin >> re >> im;
	Complex c1(re, im);		// 用re, im初始化c1
	cin >> re;
	Complex c2 = re;     		// 用实数re初始化c2

	c1.show();
	c2.show();
	c1.add(c2);         // 将C1与c2相加，结果保存在c1中
	c1.show();          // 将c1输出
	c2.sub(c1);			// c2-c1，结果保存在c2中 
	c2.show();			// 输出c2 
	
    return 0;
}
