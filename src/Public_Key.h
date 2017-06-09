/*******************************************************************************
*
*                                PUBLIC_KEY
*                              THIVOLLE Dorian
*                                 BTS SIO
*                          dorian_thivolle@orange.fr
*
*******************************************************************************/

#ifndef __PUBLIC_KEY_H__
#define __PUBLIC_KEY_H__

class Public_Key {
	public:
		Public_Key(long _n, long _c):m_N(_n), m_C(_c)
		{
			std::cout << " * Public Key created : (" << m_N << ", " << m_C << ")" << std::endl;
		}
		~Public_Key(){}

		long get_N(){ return m_N; } // Nombre N
		int get_C(){ return m_C; } // Puissance qui êleve le chiffrement à la puissance C

	private:
		long m_N;
		long m_C;
};

#endif // PUBLIC_KEY
