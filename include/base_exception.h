#ifndef _BASE_EXCEPTION_H_
#define _BASE_EXCEPTION_H_

class BaseException
{
	public:
		BaseException(
			int errorCode,
			const std::string &errorMessage
			)
		{
			m_errorCode = errorCode;
			m_errorMessage = errorMessage;
		}

		virtual ~BaseException() throw() {}

    	virtual const char* what() const throw() { return m_errorMessage.c_str(); }
	
    	virtual int getErrorCode() { return m_errorCode; }
	
    	virtual void print() { std::cerr << getString() << "\n"; }
	
    	virtual std::string
    	getString()
    	{
        	std::stringstream hh;
        	hh << std::dec << m_errorCode << ": " << m_errorMessage;
        	return hh.str();
    	}
	
    	virtual void
    	setString(
        	int errorCode,
        	const char *message
			)
    	{
        	m_errorCode = errorCode;
        	m_errorMessage = message;
    	}
	
	protected:
		int m_errorCode;
		std::string m_errorMessage;
};

#endif //_BASE_EXCEPTION_H_
