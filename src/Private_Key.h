/*******************************************************************************
*
*                                PRIVATE_KEY
*                              THIVOLLE Dorian
*                                 BTS SIO
*                          dorian_thivolle@orange.fr
*
*******************************************************************************/

#ifndef __PRIVATE_KEY_H__
#define __PRIVATE_KEY_H__

class Private_Key{

	public:
		Private_Key(long _u, long _n):m_U(_u), m_N(_n)
		{
			std::cout << " * Private Key created : (" << m_U << ", " << m_N << ")" << std::endl;
		}
		~Private_Key(){}

		long get_U(){ return m_U; } // Permet d'inverser la fonction de chiffrement
		long get_N(){ return m_N; } // Nombre N

	private:
		long m_U;
		long m_N;
};

#endif // PRIVATE_KEY
