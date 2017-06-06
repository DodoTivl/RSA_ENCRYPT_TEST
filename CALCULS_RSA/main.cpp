#include <iostream>
#include <gmpxx.h>

int main(int argc, char **argv)
{
	if ((argc != 3) && (argc != 4))
	{
		std::cout << "Usage : " << argv[0] << " x C" << std::endl;
		std::cout << "\t- resultat : x^C" << std::endl;
		std::cout << "Usage : " << argv[0] << " x C N" << std::endl;
		std::cout << "\t- resultat : (x^C)mod(N)" << std::endl;
			return 1;
	}
	
	if((!isdigit(argv[1][0])) || (!isdigit(argv[2][0])))
	{
		std::cout << "Vérifiez les arguments donnés au programme. Les valeurs doivent être numériques !" << std::endl;
		return 1;
    }

	if(argc == 4)
		if(!isdigit(argv[3][0]))
		{
			std::cout << "Vérifiez les arguments donnés au programme. Les valeurs doivent être numériques !" << std::endl;
			return 1;
        }
		
	mpz_class a(argv[1]), b(argv[2]), c, d;

	if(argc == 3)
	{
		if(b >= 5000)
		{
			std::string reponse;

			std::cout << "Le résultat peut être très grand, et mettre longtemps être calculer et à s'affcher entièrement." << std::endl;
			std::cout << "Voulez-vous vraiment continuer ? (oui / non) : ";

			getline(std::cin, reponse);

			if(reponse != "oui")
				return 1;
			else
				mpz_pow_ui(d.get_mpz_t(), a.get_mpz_t(), b.get_si()); // d = a^b;
		}
		else			
			mpz_pow_ui(d.get_mpz_t(), a.get_mpz_t(), b.get_si()); // d = a^b;
	}
	else //argc == 4
	{
		c = argv[3];
		mpz_powm(d.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t(), c.get_mpz_t());
	}



	std::cout << d << std::endl;

	return 0;
}


