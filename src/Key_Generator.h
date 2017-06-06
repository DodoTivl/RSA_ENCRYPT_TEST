/*******************************************************************************
*
*                               KEY_GENERATOR
*                              THIVOLLE Dorian
*                                 BTS SIO
*                          dorian_thivolle@orange.fr
*
*******************************************************************************/

#ifndef __KEY_GENERATOR_H__
#define __KEY_GENERATOR_H__

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Public_Key.h"
#include "Private_Key.h"

class Key_Generator{

  public:
    /*
    * Constructor and Destructor
    */
    Key_Generator(){}
    ~Key_Generator(){}

    /*
    * Generate the public key
    */
    std::shared_ptr<Public_Key> generate_public_key(long _p, long _q){
      p = _p;
      q = _q;
      n = p*q;
      m = (p-1) * (q-1);
      for(int i = 20; i > 2; i--){
        if(pgcd(m,i) == 1){
          c = i;
          break;
        }
      }
      return std::make_shared<Public_Key>(n,c);
    }

    /*
    * Generate the private key
    */
    std::shared_ptr<Private_Key> generate_private_key(){
      // System command : ./BEZOUT/bezout -rsa C M > ./util/bezout.txt
      std::string _bezout = "./BEZOUT/bezout -rsa " + std::to_string(c) + " " + std::to_string(m) + " > ./util/bezout.txt";
      system(_bezout.c_str());

      // Lecture dans le fichier bezout afin de récupérer les données.
      std::fstream fs_bezout;
      fs_bezout.open("./util/bezout.txt", std::fstream::in);
      if(fs_bezout){
        fs_bezout >> u; // Stockage dans l'attribut u.
        fs_bezout.close();
      }else{
        std::cout << "Erreur : Impossible d'ouvrir le fichier bezout." << std::endl;
      }
      return std::make_shared<Private_Key>(u,n);
    }

    /*
    * Constructor and Destructor
    */
    long get_M(){ return m; } // Indicatrice d'Euler

  private:
    long p,q,n,m,u,v;
    int c;

    /* Si b est autre que zéro, on retourne le pgcd.
    * Ainsi, la valeur retournée sera réaffectée à chaque récursion.
    * Sinon, si b vaut 0, (le : permet de en gros d'exprimer un else),
    * on retourne a, soit le pgcd ! */
    unsigned int pgcd(unsigned int a,unsigned int b){
        return b ?  pgcd(b,a%b) : a;
    }
};
#endif //Key_Generator
