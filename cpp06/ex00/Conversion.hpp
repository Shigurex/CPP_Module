#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include	<iostream>
# include	<iomanip>

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

class Conversion
{
private:
	std::string	_input;
	t_type		_type;

	char		_input_char;
	int			_input_int;
	float		_input_float;
	double		_input_double;

	void		_printChar(void);
	void		_printInt(void);
	void		_printFloat(void);
	void		_printDouble(void);

	template <class T>
	void		_printConvertChar(T value);
	template <class T>
	void		_printConvertInt(T value);
	template <class T>
	void		_printConvertFloat(T value);
	template <class T>
	void		_printConvertDouble(T value);

	template <class T>
	std::string	_putZero(T value);

public:
	Conversion();
	Conversion(std::string input);
	Conversion(const Conversion& obj);
	~Conversion();
	Conversion&	operator=(const Conversion& rhs);
	void		parse(void);
	void		printConversion(void);
};

#endif
