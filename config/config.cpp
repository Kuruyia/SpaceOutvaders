/**
 * @file config.cpp
 * @brief Fichier pour la config
 * @author LAUGIER Colin
 * @version 1.0
 * @date 09 janvier 2020
 */

#include "config.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "../gui/text.h"

using namespace std;
typedef vector<char> TableauCommande ;

void nsConfig::WriteCommande (const TableauCommande & Commande)
{
    ofstream FichierCommande ;
    FichierCommande.open(NomFichierCommande, ofstream::out);
    for (unsigned i = 0 ; i < Commande.size() ; ++i)
    {
        FichierCommande << Commande[i] << endl ;
    }
}

void nsConfig::ChangerCommande (MinGL &window)
{
    TableauCommande Commande (0) ;
    ReadCommande(Commande);
    stringstream Str ;

    Str << "Quel commande pour aller a droite ? : " ;

    window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);
    cin >> Commande[0];

    Str << "Quel commande pour aller a gauche ? : " ;

    window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);
    cin >> Commande[1];

    Str << "Quel commande pour tirer ? : " ;

    window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);
    cin >> Commande[2];

    WriteCommande(Commande);

    Str << "Voici vos nouvelles commandes : " << endl ;
    window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);

    AfficheCommande(window);
}

void nsConfig::InitCommande (TableauCommande & Commande)
{
    Commande.push_back(KDefaultRightKey);
    Commande.push_back(KDefaultLeftKey);
    Commande.push_back(KDefaultFirekey);
    Commande.push_back(KDefaultDifficulty);
}

void nsConfig::ReadCommande (TableauCommande & Commande)
{
    unsigned Cpt = 0 ;
    while (true)
    {
        if (Cpt == 3)
        {
            cerr << "Après 3 tentatives le fichier " << NomFichierCommande << " n'a toujours pas pu s'ouvrir, erreur critique numéro 001" << endl;
            break ;
        }
        ifstream FichierCommande (NomFichierCommande);

        if (!FichierCommande.is_open())
        {
            InitCommande(Commande);
            WriteCommande(Commande);
            cerr << "Le fichier " << NomFichierCommande << " est manquant, un nouveau avec les parametres par default à été créer" << endl;
            ++Cpt ;
        }
        else
        {
            string ValeursCourante ;
            while (true)
            {
                getline(FichierCommande, ValeursCourante);
                if (FichierCommande.eof()) break ;
                Commande.push_back(ValeursCourante[0]) ;
            }
            break ;
        }
    }
}

void nsConfig::AfficheCommande (MinGL &window)
{
    TableauCommande Commande (0) ;
    ReadCommande(Commande);
    for (unsigned  i = 0 ; i < Commande.size(); ++i)
    {
        stringstream Str ;
        Str << "la touche : '" << Commande[i] << KTabDirection[i] ;
        window << nsGui::Text(Vec2D(window.getWindowSize().x/2+100, 20*i+150), Str.str(), KBlue, GlutFont::BITMAP_HELVETICA_12);
    }
}
