/*******************************************************************************
*
*                              MAIN_RSA_OBJECT
*                              THIVOLLE Dorian
*                                 BTS SIO
*                          dorian_thivolle@orange.fr
*
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

#include "Public_Key.h"
#include "Private_Key.h"

class Encode_Decode{
	public:
		Encode_Decode(){}
		~Encode_Decode(){}

		std::string encode(std::string str, std::shared_ptr<Public_Key>& public_key)
		{

			// Vector de valeur ASCII
			std::vector< int > v_ascii;

			// Remplissage du vector de valeur v_ascii
			for(unsigned int i = 0; i < str.size(); i++)
			{
				v_ascii.push_back(convert_str_to_ascii(str[i]));
			}

			// Vector crypté
			// Entrée fichier
			std::fstream file_calcul_rsa;
			// Chaine de caractère System Commande
			std::string _calcul_rsa;
			// Boucle
			for(auto value : v_ascii)
			{
				// Command Line
				_calcul_rsa = "./CALCULS_RSA/calculs_RSA " + std::to_string(value) + " "
				+ std::to_string(public_key->get_C()) + " "
				+ std::to_string(public_key->get_N()) + " > ./util/calculs_RSA.txt";
				system(_calcul_rsa.c_str());

				// Read file
				file_calcul_rsa.open("./util/calculs_RSA.txt", std::fstream::in);
				if(file_calcul_rsa)
				{
					long _tmp;
					file_calcul_rsa >> _tmp;
					v_rsa.push_back(_tmp);
					file_calcul_rsa.close();
				}
				else
				{
					std::cout << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
				}
			}

			// Concatain
			std::string result_str;
			for(auto value : v_rsa)
			{
				result_str += std::to_string(value);
			}

			return result_str;
		}

		std::string decode(std::shared_ptr<Private_Key>& private_key)
		{
			// Receive string decode
			std::vector< char > v_decode;
			// File bufferreader
			std::fstream file_decode;
			// Command System
			std::string _decode_rsa;

			for(auto value : v_rsa)
			{
				// Command line
				_decode_rsa = "./CALCULS_RSA/calculs_RSA " + std::to_string(value) + " "
				+ std::to_string(private_key->get_U()) + " "
				+ std::to_string(private_key->get_N()) + " > ./util/calculs_RSA.txt";
				system(_decode_rsa.c_str()); // exec Command

				// Read file
				file_decode.open("./util/calculs_RSA.txt", std::fstream::in);
				if(file_decode)
				{
					long _tmp_ch;
					file_decode >> _tmp_ch;
					v_decode.push_back(convert_ascii_to_str(_tmp_ch));
					file_decode.close();
				}
				else
				{
					std::cout << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
				}
			}

			// Concatain
			std::string decode_str;
			for(auto value : v_decode)
			{
				decode_str += value;
			}
			//std::cout << decode_str;
			return decode_str;
		}

	private:
		std::vector< long > v_rsa;

		/* Parameter : type(char) Convert character to ASCII */
		int convert_str_to_ascii(char c){ return (int) c; }
		char convert_ascii_to_str(long c){ return (char) c; }
};
