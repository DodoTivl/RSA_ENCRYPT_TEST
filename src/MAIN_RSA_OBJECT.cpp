/*******************************************************************************
*
*                              MAIN_RSA_OBJECT
*                              THIVOLLE Dorian
*                                 BTS SIO
*                          dorian_thivolle@orange.fr
*
*******************************************************************************/

#include <iostream>
#include <string>
#include <memory>

#include "Key_Generator.h"
#include "Private_Key.h"
#include "Public_Key.h"
#include "Encode_Decode.h"

int main() {

	std::cout << "#########################################" << std::endl;
	std::cout << "#                                       #" << std::endl;
	std::cout << "#              RSA_OBJECT               #" << std::endl;
	std::cout << "#            THIVOLLE Dorian            #" << std::endl;
	std::cout << "#               BTS SIO 2               #" << std::endl;
	std::cout << "#                                       #" << std::endl;
	std::cout << "#########################################" << std::endl << std::endl;

  std::shared_ptr<Key_Generator> key_gen = std::make_shared<Key_Generator>();
  std::shared_ptr<Public_Key> p_public_key = key_gen->generate_public_key(31649, 33107);
  std::shared_ptr<Private_Key> p_private_key = key_gen->generate_private_key();
  std::shared_ptr<Encode_Decode> algo = std::make_shared<Encode_Decode>();

  std::string _message;
  std::cout << " * Entrer un message à encoder : ";
	std::getline(std::cin, _message);

  std::string str_encode = algo->encode(_message, p_public_key);
  std::string str_decode = algo->decode(p_private_key);

	std::cout << std::endl;
  std::cout << " * Chaîne encodée : " << str_encode << std::endl;
  std::cout << " * Chaîne décodée : " << str_decode << std::endl;

  return 0;
}
